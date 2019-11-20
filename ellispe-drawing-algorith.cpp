#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#define ROUND(a) ((int) (a+0.5))
using namespace std;
void ellispeplot(int xcenter,int ycenter,int x,int y)
{
         putpixel(xcenter+x,ycenter+y,RED);
         putpixel(xcenter+x,ycenter-y,RED);
         putpixel(xcenter-x,ycenter+y,RED);
         putpixel(xcenter-x,ycenter-y,RED);
         delay(20);
}
void ellispes(int xcenter,int ycenter,int rx,int ry)
{
         int rx2=rx*rx;
         int ry2=ry*ry;
         int tworx2=2*rx2;
         int twory2=2*ry2;
         int p;
         int x=0;
         int y=ry;
         int px=0;
         int py=tworx2*y;
         ellispeplot(xcenter,ycenter,x,y);
         //region 1;
         p=ROUND(ry2-rx2*y+0.25*rx2);
         while(px<py)
         {
                  x++;
                  px+=twory2;
                  if(p<0)
                           p+=ry2+px;
                  else
                  {
                           y--;
                           py-=tworx2;
                           p+=ry2+px-py;
                  }
                  ellispeplot(xcenter,ycenter,y,x);
                  ellispeplot(xcenter,ycenter,x,y);
         }

         //region 2;
         p=ROUND(ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2);
         while(y>0)
         {
                  y--;
                  py-=tworx2;
                  if(p>0)
                           p+=rx2-py;
                  else
                  {
                           x++;
                           px+=twory2;
                           p+=ry2-py+px;
                  }
                  ellispeplot(xcenter,ycenter,y,x);
                  ellispeplot(xcenter,ycenter,x,y);
         }
}



int main()
{
         int gd=DETECT,gm;
         initgraph(&gd,&gm,"C\\TC\\BGI");
         int xc,yc,rx,ry;
         cout<<"Enter the center of ellispe";
         cin>>xc>>yc;
         cout<<"Enter the major and minor axis";
         cin>>rx>>ry;
         if(rx>ry)
         ellispes(xc,yc,rx,ry);

         getch();
         closegraph();
         return 0;

}
