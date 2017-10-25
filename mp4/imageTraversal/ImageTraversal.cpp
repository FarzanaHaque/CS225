#include <cmath>
#include <iterator>
#include <iostream>
 
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"
 
#include "ImageTraversal.h"
 
/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *  
 * @param p1 First pixel
 * @param p2 Second pixel
 */
double ImageTraversal::calculateDelta(/*const*/ HSLAPixel & p1, /*const*/ HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;
 
  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;
 
  return sqrt( (h*h) + (s*s) + (l*l) );     
}
 
/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
 
}
ImageTraversal::Iterator::Iterator(Point * point,ImageTraversal * imtrav) {
  /** @todo [Part 1] */
point_=point;
travpointer=imtrav;
}
 
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
 // return *this;

const Point *cpoint= point_;
//Point * temp=this->travpointer->DFSqueue.top();
this->travpointer->add(*cpoint);
Point temp=this->travpointer->pop();
HSLAPixel * H1=travpointer->png_->getPixel(point_->x,point_->y);
HSLAPixel* H2=travpointer->png_->getPixel(temp.x,temp.y);
if(travpointer->tolerance_<=this->travpointer->calculateDelta(*H1,*H1)){
	while(travpointer->tolerance_<=this->travpointer->calculateDelta(*H2,*H2)){	
	temp=this->travpointer->pop();
        H2=travpointer->png_->getPixel(temp.x,temp.y);
	}
}
//Point *temp= new Point((this->travpointer->pop()).x,(this->travpointer->pop()).y);
//Point temp=(this->travpointer->pop());

/*HSLAPixel *H1=travpointer->png_->getPixel(point_->x,point_->y);
HSLAPixel *H2=travpointer->png_->getPixel(temp.x,temp.y);
//temp=pop();
if(travpointer->tolerance_<=this->calculateDelta(*H1,*H2)&&//!travpointer->empty()){
	//while(travpointer->tolerance_<=this->calculateDelta(point_,temp)&&!this->empty()){//valid- not visited and tolerance
//	while(travpointer->tolerance_<=this->calculateDelta(*H1,*H2)&&//!travpointer->empty()){
	temp=travpointer->pop();
	}
}

*/
//cout<<temp.x<<","<<temp.y<<endl;
//Point *fake=new Point(53,32);
Point *rigid=new Point(temp.x,temp.y);
point_=rigid;
//Iterator its= Iterator(fake,travpointer);//&temp
//cout<<*its.x<<","<<*its->y<<endl;
return *this;

//return *this;
}
 
/**
 * Iterator accessor opreator.
 *  
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
//cout<<point_<<endl;
  return *point_;
}
 
/**
 * Iterator inequality operator.
 *  
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  return false;
}

