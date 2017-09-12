#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "mp1.h"
using namespace cs225;



// sets up the output image
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

void rotate(std::string inputFile, std::string outputFile) {
/*fstream myfile;
myfile.open(inputFile);
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel *pixel = image.getPixel(x, y);
	}
   }*/
PNG* original=new PNG();
original->readFromFile(inputFile);
unsigned width=original->width();
unsigned height=original->height();
PNG* output=setupOutput(width,height);
  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 0; y < height; y++) {
      //HSLAPixel * myPixel = new HSLAPixel();
      HSLAPixel* myPixel=original->getPixel(width-x-1, height-y-1);
	//HSLAPixel* myPixel=original->getPixel(width-x,height-y);
	HSLAPixel* currOutPixel=(*output).getPixel(x,y);
	//?????????????currOutPixel=myPixel;
	currOutPixel->h=myPixel->h;
	currOutPixel->l=myPixel->l;
	currOutPixel->s=myPixel->s;
	currOutPixel->a=myPixel->a;
	
	}
   }






output->writeToFile(outputFile);
//delete myPixel;
delete output;
delete original;
}
