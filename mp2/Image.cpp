#include "Image.h"
#include <cmath>
using namespace cs225;
  void Image::lighten(){
	unsigned width=this->width();
	unsigned height=this->height();
	//Image* output=new Image(width,height);
//	HSLAPixel * newImageData= new HSLAPixel[width*height];	
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		//HSLAPixel * original=this->getPixel(i,j);
		//HSLAPixel * out=(*output).getPixel(i,j);
		//HSLAPixel *output=new HSLAPixel;
		//if((original->l)<=0.9){
		//this->getPixel(i,j)->l=(this->getPixel(i,j)->l)+0.1;
		//output->l=(output->l)+0.1;	
		HSLAPixel * original=this->getPixel(i,j);
		//HSLA & newPixel=newImage	
		original->l=(original->l)+0.1;
		/*out->h=original->h;
		out->s=original->s;
		out->a=original->a;*/
		//output=original;

		//}
		if(original->l > 1)
			original->l=1;
	 }
	}
	//this=output;
	//delete output;
  }
  void Image::lighten(double amount){
	unsigned width=this->width();
	unsigned height=this->height();
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		HSLAPixel * original=this->getPixel(i,j);
		original->l=(original->l)+amount;
	if((original->l) >1)
		original->l=1;
	}
	}
  }
  void Image::darken(){
	unsigned width=this->width();
	unsigned height=this->height();
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		HSLAPixel * original=this->getPixel(i,j);
		original->l=(original->l)-0.1;
	if((original->l) <0)
		original->l=0;
	}
	}
  }
  void Image::darken(double amount){
	unsigned width=this->width();
	unsigned height=this->height();
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		HSLAPixel * original=this->getPixel(i,j);
		original->l=(original->l)-amount;
	if((original->l) <0)
		original->l=0;
	}
	}
  }
  void Image::saturate(){
	unsigned width=this->width();
	unsigned height=this->height();
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		HSLAPixel * original=this->getPixel(i,j);
		original->s=(original->l)+0.1;
	if((original->s) >1)
		original->s=1;
	}
	}
  }
  void Image::saturate(double amount){
	unsigned width=this->width();
	unsigned height=this->height();
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		HSLAPixel * original=this->getPixel(i,j);
		original->s=(original->s)+amount;
	if((original->s) >1)
		original->s=1;
	}
	}
  }
  void Image::desaturate(){
	unsigned width=this->width();
	unsigned height=this->height();
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		HSLAPixel * original=this->getPixel(i,j);
		original->s=(original->s)-0.1;
	if((original->s) <0)
		original->s=0;
	}
	}
  }
  void Image::desaturate(double amount){
	unsigned width=this->width();
	unsigned height=this->height();
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		HSLAPixel * original=this->getPixel(i,j);
		original->s=(original->s)-amount;
	if((original->s) <0)
		original->s=0;
	}
	}
  }
  void Image::grayscale(){
	unsigned width=this->width();
	unsigned height=this->height();
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		HSLAPixel * original=this->getPixel(i,j);
		original->s=0;

	}
  }
}
  void Image::rotateColor(double degrees){
	unsigned width=this->width();
	unsigned height=this->height();
	for(unsigned int i=0;i<width;i++){
	 for(unsigned int j=0;j<height;j++){
		HSLAPixel * original=this->getPixel(i,j);
		original->h=fmod((original->h+degrees),360);
		
	

	}
  }
  }
  void Image::illinify(){
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      HSLAPixel *pixel = this->getPixel(x, y);
if((pixel->h)<=113){
pixel->h=11;
}
else if(abs(360-(pixel->h)-11)<abs((pixel->h)-216)){
pixel->h=11;
}
else{
pixel->h=216;
}






    }
  }
  }
  void Image::scale(double factor){
	Image *newI=this;
	unsigned int width=this->width();
	unsigned int height=this->height();
	resize(factor*(this->width()), factor*(this->height()));
	for(unsigned i=0;i<width;i++){
		for(unsigned j=0;j<height;j++){
			for(unsigned int x=i*factor;x<((i+1)*factor);x++){
				for (unsigned int y=j*factor;y<(factor*(j+1));y++){
				HSLAPixel * out=this->getPixel(x,y);
					out->h=(newI->getPixel(i,j))->h;
					out->l=(newI->getPixel(i,j))->l;
					out->s=(newI->getPixel(i,j))->s;
					out->a=(newI->getPixel(i,j))->a;
				}
			}	
		}
	}
//delete newI;	
  }
  void Image::scale(unsigned w, unsigned h){
  }
