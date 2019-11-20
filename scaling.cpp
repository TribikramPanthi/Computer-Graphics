
#include<graphics.h>
#include<iostream>
#include<math.h>
#include<iomanip>
void dratriag(int a, int b, int c, int d)
 {
float x1,y1,x2,y2,x,y,k,dx,dy,m,step;
float xinc, yinc;
  x1=a;
  y1=b;
  x2=c;
  y2=d;
 dx=(x2-x1);
 dy=(y2-y1);
 m=(dy/dx);
 if (abs(dx)>abs(dy))
 {
     step=(dx);
 }

 else
 {
     step=(dy);
 }
    x=x1;
    y=y1;
    k=0;
     xinc=(dx/step);
     yinc=(dy/step);
    do{
    putpixel(round(x),round(y),3);
    x=x+xinc;
    y=y+yinc;
    k=k+1;
    }while(k<=abs(step));
}
using namespace std;
int main()
{
    int gd= DETECT,gm;
    int l1,r1,l2,r2,l3,r3,xf,yf,sx,sy,c1,c2;
    initgraph(&gd,&gm,"");
      cout<<"Enter start coordinate : ";
      cin>>l1>>r1;
      cout<<"Enter second coordinate : ";
      cin>>l2>>r2;
      cout<<"Enter third coordinate : ";
      cin>>l3>>r3;
      cout<<"enter fixed points and scaling factors: xf, yf, sx, sy";
      cin>>xf>>yf>>sx>>sy;
      dratriag(l1,r1,l2,r2);
      cout<<l1<<r1<<l2<<r2<<endl;
      dratriag(l1,r1,l3,r3);
      cout<<l1<<r1<<l3<<r3<<endl;
      dratriag(l3,r3,l2,r2);
      cout<<l3<<r3<<l2<<r2<<endl;
      c1=xf*(1-sx);
      c2=yf*(1-sy);
      dratriag(l1*sx+c1,r1*sy+c2,l2*sx+c1,r2*sy+c2);
      cout<<(l1*sx+c1)<<(r1*sy+c2)<<(l2*sx+c1)<<(r2*sy+c2)<<endl;
      dratriag(l1*sx+c1,r1*sy+c2,l3*sx+c1,r3*sy+c2);
      cout<<(l1*sx+c1)<<(r1*sy+c2)<<(l3*sx+c1)<<(r3*sy+c2)<<endl;
      dratriag(l3*sx+c1,r3*sy+c2,l2*sx+c1,r2*sy+c2);
      cout<<(l3*sx+c1)<<(r3*sy+c2)<<(l2*sx+c1)<<(r2*sy+c2)<<endl;
	getch();
	closegraph();
	return 0;
}







