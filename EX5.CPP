#include <graphics.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
int main (){
float x,y,a, b,r,p,h,k,p1,p2;
h=319;
k=239;
a=50;
b=40;
int gdriver = DETECT, gmode, errorcode;
int midx, midy, i;
initgraph (&gdriver, &gmode, "C:\\TURBOC3\\BGI ");
x=0;
y=b;
p1 = ((b * b)-(a * a * b) + (a * a)/4);
{
putpixel (x+h, y+k, RED);
putpixel (-x+h, -y+k, RED);
putpixel (x+h, -y+k, RED);
putpixel (-x+h, y+k, RED);
if (p1 < 0)
p1 += ((2 *b * b) *(x+1))-((2 * a * a)*(y-1)) + (b * b);
else
{
p1+= ((2 *b * b) *(x+1))-((2 * a * a)*(y-1))-(b * b);
y--;
}
x++;
}
p2 =((b * b)* (x + 0.5))+((a * a)*(y-1) * (y-1))-(a * a *b * b);
while (y>=0){
if (p2>0){
p2=p2-((2 * a * a)* (y-1))+(a *a);
}
else{
p2=p2-((2 * a * a)* (y-1))+((2 * b * b)*(x+1))+(a * a);
x++;
}
y--;
putpixel (x+h, y+k, RED);
putpixel (-x+h, -y+k, RED);
putpixel (x+h, -y+k, RED);
putpixel (-x+h, y+k, RED);
}
getch();
return 0;
}