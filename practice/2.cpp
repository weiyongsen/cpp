#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159f
class Shape{
   public:
      virtual float area() = 0;
};
class Circle: public Shape{
   public:
      float dia;
      Circle(){
         dia=0;
      }
      Circle(float d):dia(d){ }
      float area(){
         return PI*dia*dia;
      }
};
class Square: public Shape{

   public:
      float len;
      Square(){
         len=0;
      }
      Square(float d):len(d){ }
      float area(){
         return len*len;
      }
};
class Rectangle: public Shape{
   public: 
      float wid;
      float len;
      Rectangle(){
         wid=0;
         len=0;
      }
      Rectangle(float w,float l):wid(w), len(l){ }
      float area(){
         return wid*len;
      }
};
class Trapezoid: public Shape{
   public:
      float upwid;
      float dwwid;
      float len;
      Trapezoid(){
         upwid=0;
         dwwid=0;
         len=0;
      }
      Trapezoid(float uw,float dw,float l):upwid(uw), dwwid(dw), len(l){ }
      float area(){
         return (upwid+dwwid)*len/2;
      }
};
class Triangle: public Shape{    
   public:
      float wid;
      float len;
      Triangle(){
         wid=0;
         len=0;
      }
      Triangle(float w,float l):wid(w), len(l){ }
      float area(){
         return wid*len/2;
      }
};
int main(){
   Circle c;
   Square s;
   Rectangle r;
   Trapezoid tra;
   Triangle tri;
   cin >> c.dia >> s.len >> r.wid >> r.len >> tra.upwid >> tra.dwwid >> tra.len >> tri.wid >> tri.len;
   printf("%.3f\n",c.area()+s.area()+r.area()+tra.area()+tri.area());
   return 0;
}
