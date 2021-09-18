#include <stdio.h>
class CohenSutherLandAlgo {
private:
double x1,y1,x2,y2;
double x_max,y_max,x_min,y_min;
const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;
public:
CohenSutherLandAlgo() {
x1 = 0.0;
x2 = 0.0;
y1 = 0.0;
y2 = 0.0;
}
void getCoordinates();
void getClippingRectangle();
int generateCode(double x, double y);
void cohenSutherland();
};
void CohenSutherLandAlgo::getCoordinates(){
printf("\nEnter Co-ordinates of P1(X1,Y1) of Line Segment : ");
printf("\Enter X1 Co-ordinate : ");
scanf( "%lf",&x1);
printf( "\Enter Y1 Co-ordinate : ");
scanf( "%lf",&y1);
printf("\nEnter Co-ordinates of P2(X2,Y2) of Line Segment : ");
printf( "\Enter X2 Co-ordinate : ");
scanf( "%lf",& x2);
printf( "\Enter Y2 Co-ordinate : ");
scanf( "%lf",& y2);
}
void CohenSutherLandAlgo::getClippingRectangle(){
printf( "\nEnter the Co-ordinates of Interested Rectangle.");
printf( "\nEnter the X_MAX : ");
scanf( "%lf",&x_max);
printf( "\nEnter the Y_MAX : ");
scanf( "%lf",& y_max);
printf( "\nEnter the X_MIN : ");
scanf( "%lf",& x_min);
printf( "\nEnter the Y_MIN : ");
scanf( "%lf",& y_min);
}
int CohenSutherLandAlgo::generateCode(double x, double y) {
int code = INSIDE; // intially initializing as being inside
if (x < x_min) // lies to the left of rectangle
code |= LEFT;
else if (x > x_max) // lies to the right of rectangle
code |= RIGHT;
if (y < y_min) // lies below the rectangle
code |= BOTTOM;
else if (y > y_max) // lies above the rectangle
code |= TOP;
return code;
}
void CohenSutherLandAlgo::cohenSutherland() {
int code1 = generateCode(x1, y1);
int code2 = generateCode(x2, y2);
bool accept = false;
while (true) {
if ((code1 == 0) && (code2 == 0)) {
accept = true;
break;
}
else if (code1 & code2) {
break;
}
else {
int code_out;
double x, y;
if (code1 != 0)
code_out = code1;
else
code_out = code2;
if (code_out & TOP) {
x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
y = y_max;
}
else if (code_out & BOTTOM) {
x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
y = y_min;
}
else if (code_out & RIGHT) {
y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
x = x_max;
}
else if (code_out & LEFT) {
y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
x = x_min;
}
if (code_out == code1) {
x1 = x;
y1 = y;
code1 = generateCode(x1, y1);
}
else{
x2 = x;
y2 = y;
code2 = generateCode(x2, y2);
}
}
}
if (accept) {
printf("Line accepted from ( %lf %lf ) to (%lf %lf )",x1 ,y1,x2,y2 );
}
else
printf("Line can't be drawn");
}
int main() {
CohenSutherLandAlgo c;
c.getCoordinates();
c.getClippingRectangle();
c.cohenSutherland();
return 0;
}