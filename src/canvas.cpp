/*
Haiqa Kamran
Last Modified: 18 March, 2021
*/

#include "canvas.h"
#include <cassert>

using namespace std;
using namespace agl;

canvas::canvas(int w, int h) : myCanvas(w, h)
{
}

canvas::~canvas()
{
}

void canvas::save(const std::string& filename)
{
   myCanvas.save(filename);
}

void canvas::begin(PrimitiveType type)
{
   reqType = type;
}

void canvas::end()
{
   if(reqType == LINES) {
      for (int i = 0; i < v.size()-1; i+=2) 
      {
         drawLine(v[i],v[i+1]);
      }
   } else if(reqType == TRIANGLES) {
      for (int i = 0; i < v.size()-2; i+=3) 
      {
         barycentricFill(v[i],v[i+1],v[i+2]);
      }
   }
   v.clear();
}

void canvas::vertex(int x, int y)
{
   v.push_back(point{x,y,_color});
}

void canvas::color(unsigned char r, unsigned char g, unsigned char b)
{
   _color = ppm_pixel{r,g,b};
}

void canvas::background(unsigned char r, unsigned char g, unsigned char b)
{
    for(int h = 0; h < myCanvas.height(); h++) {
    	for(int w = 0; w < myCanvas.width(); w++) {
    	myCanvas.set(h, w, ppm_pixel{r,g,b});
      	}
   }
}

void canvas::drawLine(point a, point b) 
{
   int width = b.x-a.x;
   int height = b.y-a.y;
   point c; 
   	if(height < width) { 
    	if(a.x > b.x) { //a not left-most point so switch 
			c = a;
			a = b;
			b = c;
		}
		int y1 = a.y;
   		int w1 = b.x-a.x;
   		int h1 = b.y-a.y;
   		int inc1 = 1;
   		float t1;
   		ppm_pixel color;

   		if(h1 < 0) {
      		inc1 = -1;
      		h1 = -h1;
   		}
   		int f = 2*h1 - w1;

   		for(int x = a.x; x <= b.x; x++) {
      		t1 = (x-a.x)/(float)(b.x-a.x);
      		color = interpolateL(a.color, b.color, t1);
      		myCanvas.set(y1,x,color);
      		if(f > 0) {
         		y1 += inc1;
         		f += 2*(h1-w1);
      		} else {
         		f += 2*h1;
      		}
   		}
	}  	else { //height more than width
    		if(a.y > b.y) { //a not left-most point so switch
    			c = a;
				a = b;
				b = c;
      		} 
			int x2 = a.x;
   			int w2 = b.x - a.x;
   			int h2 = b.y - a.y;
   			int inc2 = 1;
   			float t2;
   			ppm_pixel color;
   			if(w2 < 0) {
      			inc2 = -1;
      			w2 = -w2;
   			}
   			int f2 = 2*w2 - h2;
			for (int y = a.y; y <= b.y; y++){
      			t2 = (y-a.y)/(float)(b.y-a.y);
      			color = interpolateL(a.color, b.color, t2);
      			myCanvas.set(y,x2,color);
      			if(f2 > 0) { 
        			x2 += inc2;
        			f2 += 2*(w2-h2);
      			} else {
        			f2 += 2*w2;
      			}
   			}
    	}
}

ppm_pixel canvas::interpolateL(ppm_pixel c1, ppm_pixel c2, float t)
{
   unsigned char red = (unsigned char)((1-t)*c1.r+c2.r*t);
   unsigned char green = (unsigned char)((1-t)*c1.g+c2.g*t);
   unsigned char blue = (unsigned char)((1-t)*c1.b+c2.b*t);
   return ppm_pixel{red,green,blue};
}

ppm_pixel canvas::interpolateT(ppm_pixel c1, ppm_pixel c2, ppm_pixel c3, 
   float alpha, float beta, float gamma)
{
   unsigned char red = (unsigned char)(alpha*c1.r + beta*c2.r + gamma*c3.r);
   unsigned char green = (unsigned char)(alpha*c1.g + beta*c2.g + gamma*c3.g);
   unsigned char blue = (unsigned char)(alpha*c1.b + beta*c2.b + gamma*c3.b);

   return ppm_pixel{red,green,blue};
}

int canvas::implicitEq(point a, point b, point p) 
{
	int H = b.y-a.y;
	int W = b.x-a.x;
	return (H*(p.x-a.x)-W*(p.y-a.y)); 
}

void canvas::barycentricFill(point a, point b, point c) 
{
   point p;
   ppm_pixel color;
   int alpha = implicitEq(b,c,a);
   int beta = implicitEq(a,c,b);
   int gamma = implicitEq(a,b,c);
   int min_x = min(min(a.x, b.x), c.x);
   int max_x = max(max(a.x, b.x), c.x);
   int min_y = min(min(a.y, b.y), c.y);
   int max_y = max(max(a.y, b.y), c.y);
   for(int ht = min_y; ht < max_y; ht++) {
      for(int wd = min_x; wd < max_x; wd++) {
		 p = {wd,ht,ppm_pixel{0,0,0}};
         if(implicitEq(b,c,p)/(float)alpha >= 0 && 
		 	implicitEq(a,c,p)/(float)beta >= 0 && 
			implicitEq(a,b,p)/(float)gamma >= 0) { //pixel inside triangle
            point out = {-1,-1,ppm_pixel{0,0,0}};
            if(0 < alpha || 0 < implicitEq(a,c,out)*alpha || 
							0 < implicitEq(a,b,out)*alpha || 
							0 < implicitEq(b,c,out)*alpha){ //adjacent edge{
               color = interpolateT(a.color, b.color, c.color, 	
			   			implicitEq(b,c,p)/(float)alpha, 
			   			implicitEq(a,c,p)/(float)beta, 
						implicitEq(a,b,p)/(float)gamma);
               myCanvas.set(ht,wd,color);
            }
         }
      }
   }
}

void canvas::drawRec(int x, int y, int width, int height) {
	int wd = width/2;
	int ht = height/2;
	point p1 = {x - wd, y - ht, _color};
    point p2  = {x + wd, y - ht, _color};
    point p3  = {x + wd, y - ht, _color};
	point p4 = {x + wd, y + ht, _color};
	point p5 = {x - wd, y + ht, _color};
	drawLine(p1, p2);
	drawLine(p1, p5);
	drawLine(p5, p4);
	drawLine(p3, p4);

}


