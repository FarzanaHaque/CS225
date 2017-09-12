#include <cstdlib>
#include <cmath>
#include <iostream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;

// sets up the output image
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

// Returns my favorite color
HSLAPixel* myFavoriteColor(double saturation) {
    //HSLAPixel pixel(174, saturation, 0.5);
    //return &pixel;
	//HSLAPixel *pixel=new HSLAPixel(174,saturation,1.0);
	HSLAPixel *pixel=new HSLAPixel(174,saturation,0.5);
	return pixel;
}

void sketchify(std::string inputFile, std::string outputFile) {
    // Load in.png
    PNG* original = new PNG();
//cout << "reached line 23" << endl;
    original->readFromFile(inputFile);
    unsigned width = original->width();
    unsigned height = original->height();
//cout << "reached line 27" << endl;
    // Create out.png
    PNG* output= setupOutput(width, height);
//cout << "output worked" << endl;
    // Load our favorite color to color the outline

    //HSLAPixel* myPixel = myFavoriteColor(1.0);
   HSLAPixel* myPixel = myFavoriteColor(0.5);
////////////////////////////////////////////////cout<<"mypixel l="<<(myPixel->l)<<endl;

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (unsigned y = 1; y < height; y++) {
        for (unsigned x = 1; x < width; x++) {
            // Calculate the pixel difference
            HSLAPixel* prev = original->getPixel(x - 1, y - 1);
           HSLAPixel* curr = original->getPixel(x, y);
           double diff = std::fabs(curr->h - prev->h);
//cout<<"curr->l="<<curr->l<<endl;
//cout<<"prev->l="<<prev->l<<endl;
            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
          HSLAPixel* currOutPixel = (*output).getPixel(x, y);
//cout<<"currout->l="<<currOutPixel->l<<endl;
		/*myPixel->l=prev->l;
		currOutPixel->l=prev->l;*/
            if (diff > 20) {////////////////////////////20
                //???????????currOutPixel = myPixel;
	currOutPixel->h=myPixel->h;
	currOutPixel->l=myPixel->l;
	currOutPixel->s=myPixel->s;
	currOutPixel->a=myPixel->a;
            }
//cout<<"updated currout"<<currOutPixel->l<<endl;
/////////////cout<<"myP->l="<<myPixel->l<<endl;
        }
    }
    // Save the output file
    output->writeToFile(outputFile);
//cout<<"output written"<<endl;
    // Clean up memory
    delete myPixel;

//cout<<"mypixel"<<endl;
    delete output;
//cout<<"myoutput"<<endl;
    delete original;
//cout<<"original"<<endl;
}
