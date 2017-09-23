#include "Image.h"
using namespace cs225;
  void Image::lighten(){
	unsigned width=this->width();
	unsigned height=this->height();
	Image* output=new Image(width,height);
	for(int i=0;i<height;i++){
	 for(int j=0;j<width;j++){
		HSLAPixel * original=this->getPixel(i,j);
		HSLAPixel * out=(*output).getPixel(i,j);
		//HSLAPixel *output=new HSLAPixel;
		if((original->l)<=0.9){
		//this->getPixel(i,j)->l=(this->getPixel(i,j)->l)+0.1;
		//output->l=(output->l)+0.1;		
		out->l=(original->l)+0.1;
		out->h=original->h;
		out->s=original->s;
		out->a=original->a;
		//output=original;

		}
	 }
	}
	this=output;
	delete output;
  }
  void Image::lighten(double amount){
  }
  void Image::darken(){
  }
  void Image::darken(double amount){
  }
  void Image::saturate(){
  }
  void Image::saturate(double amount){
  }
  void Image::desaturate(){
  }
  void Image::desaturate(double amount){
  }
  void Image::grayscale(){
  }
  void Image::rotateColor(double degrees){
  }
  void Image::illinify(){
  }
  void Image::scale(double factor){
  }
  void Image::scale(unsigned w, unsigned h){
  }
