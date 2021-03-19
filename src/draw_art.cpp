#include <iostream>
#include "canvas.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   canvas drawer(640, 380);
   drawer.background(0, 0, 0);
   drawer.drawRec(50, 50, 60, 80);
   drawer.save("rectangle.png");
}

