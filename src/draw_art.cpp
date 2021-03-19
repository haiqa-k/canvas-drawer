/*
Haiqa Kamran
*/
#include <iostream>
#include "canvas.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   canvas drawer(100, 100);
   drawer.background(0, 0, 0);
   //drawer.drawRec(50,70,50,50);

   drawer.begin(TRIANGLES);
   drawer.color(255, 0, 255);
   drawer.vertex(50, 0);
   drawer.color(0, 255, 255);
   drawer.vertex(90, 50);
   drawer.color(255, 255, 0);
   drawer.vertex(10, 50);
   drawer.begin(TRIANGLES);

   drawer.color(255, 0, 255);
   drawer.vertex(50, 0);
   drawer.color(0, 255, 255);
   drawer.vertex(50, 90);
   drawer.color(255, 255, 0);
   drawer.vertex(50, 10);

   drawer.begin(TRIANGLES);
   drawer.color(255, 0, 255);
   drawer.vertex(30, 50);
   drawer.color(0, 255, 255);
   drawer.vertex(30, 90);
   drawer.color(255, 255, 0);
   drawer.vertex(70, 90);

   drawer.color(255, 255, 0);
   drawer.vertex(70, 90);
   drawer.color(0, 255, 255);
   drawer.vertex(70, 50);
   drawer.color(255, 0, 255);
   drawer.vertex(30, 50);
   drawer.color(165,42,42);
   for (int i = 0; i <= 100; i+=20){
      for(int j = 0; j <= 100; j+=50){
         drawer.drawRec(i, j, 20, 20);
      }
   }
   drawer.color(192,192,192);
   for (int i = 0; i <= 100; i+=5){
      for(int j = 0; j <= 100; j+=20){
         drawer.drawRec(i, j, 10, 10);
      }
   }

   drawer.end();
   drawer.save("artwork.png");
}

