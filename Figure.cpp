#include "Figure.h"
#include <cmath>

Rectangle::Rectangle(int x,int y,int w,int h,char s):x(x),y(y),width(w),height(h),symbol(s) {}

void Rectangle::draw(Canvas &canvas) const 
{
    for(int i=y;i<y+height;++i) 
    {
        for(int j=x;j<x+width;++j) 
        {
            canvas.drawPixel(j,i,symbol);
        }
    }
}

Square::Square(int x,int y, int size,char s):Rectangle(x,y,size,size,s) {}

Circle::Circle(int cx,int cy,int r,char s):cx(cx),cy(cy),radius(r),symbol(s) {}

void Circle::draw(Canvas &canvas) const 
{
    for (int y= -radius;y<=radius;++y) 
    {
        for (int x= -radius; x<=radius;++x) 
        {
            if (x*x+y*y<=radius*radius) 
            {
                canvas.drawPixel(cx+x,cy+y,symbol);
            }
        }
    }
}
