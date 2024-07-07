#include "Canvas.h"
ASCIICanvas::ASCIICanvas(int w,int h,char emptySymbol):width(w),height(h),emptySymbol(emptySymbol) 
{
    clear();
}

void ASCIICanvas::clear() 
{
    grid.assign(height,std::string(width,emptySymbol));
}


void ASCIICanvas::drawPixel(int x,int y,char symbol) 
{
    if (x>=0 && x<width && y>=0 && y<height) 
    {
        grid[y][x]=symbol;
    }
}

void ASCIICanvas::render(std::ostream &out) const 
{
    for(const auto &line:grid) 
    {
        out<<line<<'\n';
    }
}
