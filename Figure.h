#ifndef FIGURE_H
#define FIGURE_H

#include "Canvas.h"

class Figure 
{
public:
    virtual ~Figure() {}
    virtual void draw(Canvas &canvas) const=0;
};




class Rectangle:public Figure 
{
protected:
    int x,y,width,height;
    char symbol;
public:
    Rectangle(int x,int y,int w,int h,char s);
    void draw(Canvas &canvas) const override;
};

class Square:public Rectangle 
{
public:
    Square(int x,int y,int size,char s);
};



class Circle:public Figure 
{
private:
    int cx,cy,radius;
    char symbol;
public:
    Circle(int cx,int cy,int r,char s);
    void draw(Canvas &canvas) const override;
};

#endif // FIGURE_H
