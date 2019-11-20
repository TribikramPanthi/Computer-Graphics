#include<graphics.h>
#include<iostream>
#include<math.h>
#include<iomanip>
 void dratriag(float x1,float y1,float x2, float y2)
{
    float x,y,xp,yp,dx,dy,step,k;
    dx=x2-x1;
            dy=y2-y1;
            if(abs(dx)>abs(dy))
            {
                step=abs(dx);
            }
            else
            {
                step=abs(dy);
            }
            x=x1;y=y1;
            k=0;
            xp=dx/step;
            yp=dy/step;
            do{

                putpixel(round(x),round(y),3);
                x=x+xp;
                y=y+yp;
                k++;
            }while(k<=step);
}
using namespace std;
int main()
{
    int gd= DETECT,gm;
    int l1,r1,l2,r2,l3,r3,xr,yr,angleo;
    float angle;
    initgraph(&gd,&gm,"");
      cout<<"Enter start coordinate : ";
      cin>>l1>>r1;
      cout<<"Enter second coordinate : ";
      cin>>l2>>r2;
      cout<<"Enter third coordinate : ";
      cin>>l3>>r3;
      cout<<"enter pivoting point n angle of rotation: xr,yr,angle";
      cin>>xr>>yr>>angleo;
      angle=(angleo*3.1415)/180;
      dratriag(l1,r1,l2,r2);
      dratriag(l1,r1,l3,r3);
      dratriag(l3,r3,l2,r2);
      float tx1,tx2,tx3,ty1,ty2,ty3;
      tx1=xr+(l1-xr)*cos(angle)-(r1-yr)*sin(angle);
      tx2=xr+(l2-xr)*cos(angle)-(r2-yr)*sin(angle);
      tx3=xr+(l3-xr)*cos(angle)-(r3-yr)*sin(angle);


      ty1=yr+(l1-xr)*sin(angle)+(r1-yr)*cos(angle);
      ty2=yr+(l2-xr)*sin(angle)+(r2-yr)*cos(angle);
      ty3=yr+(l3-xr)*sin(angle)+(r3-yr)*cos(angle);

      dratriag(tx1,ty1,tx2,ty2);
      cout<<tx1<<"  "<<ty1<<"  "<<tx2<<"  "<<ty2<<endl;
      dratriag(tx1,ty1,tx3,ty3);
      cout<<tx1<<"  "<<ty1<<"  "<<tx3<<"  "<<ty3<<endl;
      dratriag(tx2,ty2,tx3,ty3);
      cout<<tx2<<"  "<<ty2<<"  "<<tx3<<"  "<<ty3<<endl;
    getch();
	closegraph();
	return 0;
}








