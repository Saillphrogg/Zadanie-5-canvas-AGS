#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Canvas.h"
#include "Figure.h"

void parseConfig(const std::string &filename,int &canvasWidth,int &canvasHeight,char &emptySymbol,std::string &outputFile,std::vector<std::unique_ptr<Figure>> &figures) 
{
    std::ifstream file(filename);
    if(!file) 
    {
        throw std::runtime_error("Nie udalo otworzyc pliku config");
    }
    file>>canvasWidth>>canvasHeight;
    file>>emptySymbol;
    file>>outputFile;
    std::string figureType;
    while(file>>figureType) 
    {
        if(figureType=="Rectangle") 
        {
            int x,y,w,h;
            char symbol;
            file >>x>>y>> w>>h>>symbol;
            figures.push_back(std::unique_ptr<Rectangle>(new Rectangle(x,y,w,h,symbol)));
        } 
        else if(figureType=="Square") 
        {
            int x,y,size;
            char symbol;
            file>>x>>y>>size>>symbol;
            figures.push_back(std::unique_ptr<Square>(new Square(x,y,size,symbol)));
        } 
        else if(figureType=="Circle") 
        {
            int cx,cy,r;
            char symbol;
            file>>cx>>cy>>r>> symbol;
            figures.push_back(std::unique_ptr<Circle>(new Circle(cx, cy, r, symbol)));
        }
    }
}

int main(int argc, char** argv) 
{
    if(argc<2) 
    {
        std::cerr<<"Usage: "<<argv[0]<<" <config file>"<<std::endl;
        return 1;
    }

    int canvasWidth, canvasHeight;
    char emptySymbol;
    std::string outputFile;
    std::vector<std::unique_ptr<Figure>> figures;
    parseConfig(argv[1],canvasWidth,canvasHeight,emptySymbol,outputFile,figures);
    ASCIICanvas canvas(canvasWidth, canvasHeight, emptySymbol);
    for(const auto &figure:figures) 
    {
        figure->draw(canvas);
    }
    std::ofstream outFile(outputFile);
    if (!outFile) 
    {
        std::cerr<<"Nie mozna otwozyc output"<<std::endl;
        return 1;
    }
    canvas.render(outFile);

    return 0;
}
