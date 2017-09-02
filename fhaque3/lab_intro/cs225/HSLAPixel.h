#ifndef CS225_HSLAPIXEL_H
#define CS225_HSLAPIXEL_H

using namespace std;

namespace cs225{
 class HSLAPixel {
 public:
  double h;
  double s;
  double l;
  double a;

  HSLAPixel();
  HSLAPixel(double hue, double saturation, double luminance);
  HSLAPixel(double hue, double saturation, double luminance, double alpha);
 };
}
#endif
