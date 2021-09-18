#include <graphics.h>
#include<conio.h>
#include <stdio.h>
#include<dos.h>
main(){
int wxmax,wymax,wxmin,wymin;
int vxmax,vymax,vxmin,vymin;
float sx,sy;
int x,x1,x2,y,y1,y2;
int gr=DETECT ,gm;
initgraph (&gr,&gm,"C:\\TURBOC3\\BGI");
printf("Enter coordinates for triangle x,y");
scanf("%d %d",&x,&y);
printf("\n x1 and y1");
scanf("%d %d",&x1,&y1);
printf("\n x2 and y2");
scanf("%d %d",&x2,&y2);
printf("Enter window coordinates for triangle wxmax,wymax");
scanf("%d %d",&wxmax,&wymax);
printf("Enter window coordinates for triangle wxmin,wymin");
scanf("%d %d",&wxmin,&wymin);
cleardevice();
delay(50);
rectangle(wxmin,wymin,wxmax,wymax);
outtextxy(wxmin,wymin-10,"Window");
line(x,y,x1,y1);
line(x1,y1, x2,y2);
line(x2,y2,x,y);
vxmin=300; vymin=30; vxmax=550; vymax=350;
rectangle(vxmin,vymin,vxmax,vymax);
outtextxy(vxmin,vymin-10,"Viewport");
sx=(float)(vxmax-vxmin)/(wxmax-wxmin);
sy=(float)(vymax-vymin)/(wymax-wymin);
x=vxmin+(float)((x-wxmin)*sx);
y=vymin+(float)((y-wymin)*sy);
x1=vxmin+(float)((x1-wxmin)*sx);
x2=vxmin+(float)((x2-wxmin)*sx);
y1=vymin+(float)((y1-wymin)*sx);
y2=vymin+(float)((y2-wymin)*sx);
line(x,y,x1,y1);
line(x1,y1, x2,y2);
line(x2,y2,x,y);
getch();
closegraph();
}