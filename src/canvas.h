#ifndef canvas_H_
#define canvas_H_

#include <string>
#include <vector>
#include "ppm_image.h"

using namespace std;

namespace agl
{
   struct point {
      int x;
      int y;
      ppm_pixel color;
   };
   enum PrimitiveType {UNDEFINED, LINES, TRIANGLES};
   class canvas
   {
   private:
      ppm_pixel _color;
      ppm_image myCanvas;
      PrimitiveType reqType;
      vector<point> v;
   
   public:
      canvas(int w, int h);
      virtual ~canvas();

      // Save to file
      void save(const std::string& filename);

      // Draw primitives with a given type (either LINES or TRIANGLES)
      // For example, the following draws a red line followed by a green line
      // begin(LINES);
      //    color(255,0,0);
      //    vertex(0,0);
      //    vertex(100,0);
      //    color(0,255,0);
      //    vertex(0, 0);
      //    vertex(0,100);
      // end();
      void begin(PrimitiveType type);
      void end();

      // Specifiy a vertex at raster position (x,y)
      // x corresponds to the column; y to the row
      void vertex(int x, int y);

      // Specify a color. Color components are in range [0,255]
      void color(unsigned char r, unsigned char g, unsigned char b);

      // Fill the canvas with the given background color
      void background(unsigned char r, unsigned char g, unsigned char b);

      // Draw a line from point a to point b
      void drawLine(point a, point b);

      //Used for colored line
      ppm_pixel interpolateL(ppm_pixel c1, ppm_pixel c2, float t);

      //Used for colored triangle
      ppm_pixel interpolateT(ppm_pixel c1, ppm_pixel c2, ppm_pixel c3, float alpha, float beta, float gamma);

      //Implicit line eq
      int implicitEq(point a, point b, point p);

      //Used to draw triangle
      void barycentricFill(point a, point b, point c);

      //Draws a rectangle with the vertices as parameters
      void drawRec(int a, int b, int c, int d);

     
   };
}

#endif