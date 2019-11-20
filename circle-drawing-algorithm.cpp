#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
void circleplot(int xcenter,int ycenter,int x,int y)
{
         putpixel(xcenter+x,ycenter+y,RED);
          putpixel(xcenter-x,ycenter+y,RED);
           putpixel(xcenter+x,ycenter-y,RED);
            putpixel(xcenter-x,ycenter-y,RED);
             putpixel(xcenter+y,ycenter+x,RED);
              putpixel(xcenter+y,ycenter-x,RED);
               putpixel(xcenter-y,ycenter+x,RED);
                putpixel(xcenter-y,ycenter-x,RED);
                delay(100);

}








void circles(int xcenter,int ycenter,int radius)
{
         int x=0;
         int y=radius;
         int p=1-radius;
         //void circleplot(int,int,int,int);
         circleplot(xcenter,ycenter,x,y);
         while(x<y)
         {
                  x++;
                  if(p<0)
                           p+=2*x+1;
                  else
                  {
                           y--;
                           p+=2*x+1-2*y;
                  }
                  circleplot(xcenter,ycenter,x,y);
         }
}



int main()
{
         int gd=DETECT,gm;
         initgraph(&gd,&gm,"C:\\TC\\BGI");
         int x,y,r;
         cout<<"Enter the center of circle";
         cin>>x>>y;
         cout<<"Enter the radius of circle";
         cin>>r;
         circles(x,y,r);
         getch();
         closegraph();
         return 0;
}
