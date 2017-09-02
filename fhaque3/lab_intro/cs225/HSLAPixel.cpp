#include "HSLAPixel.h"
namespace cs225{
 HSLAPixel::HSLAPixel()
 {
	h=0;
	s=0;
	l=1;//makes white?
	a=1;//makes opaque
 }

 HSLAPixel::HSLAPixel(double hue, double saturation, double luminance){
  h=hue;
  s=saturation;
  l=luminance;
  a=1;
 }

  HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha){
   h=hue;
   s=saturation;
   l=luminance;
   a=alpha;
  }
}
