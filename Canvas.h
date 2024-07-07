#ifndef CANVAS_H
#define CANVAS_H
#include <iostream>
#include <vector>
#include <string>

class Canvas 
{
public:
    virtual ~Canvas() {}
    virtual void clear() = 0;
    virtual void drawPixel(int x,int y,char symbol)=0;
    virtual void render(std::ostream &out) const=0;
};

class ASCIICanvas : public Canvas 
{
private:
    int width;
    int height;
    std::vector<std::string> grid;
    char emptySymbol;

public:
    ASCIICanvas(int w,int h,char emptySymbol);
    void clear() override;
    void drawPixel(int x,int y,char symbol) override;
    void render(std::ostream &out) const override;
};



#endif // CANVAS_H
