#ifndef IMAGETRAVERSAL_H
#define IMAGETRAVERSAL_H

#include <iterator>
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"
#include <vector>
using namespace cs225;

/**
 * A base class for traversal algorithms on images.
 * 
 * Each derived class must maintain an ordering of points on an image,
 * through calls to the virtual member functions `add` and `pop`.
 * 
 * A derived class provides a traversal by returning instances of
 * ImageTraversal::Iterator.
 */
class ImageTraversal {
public:
  /**
   * A forward iterator through an ImageTraversal.
   */
vector< vector<bool> > visited;
	Point * start_;
	const PNG *png_;
	double tolerance_;

  class Iterator : std::iterator<std::forward_iterator_tag, Point> {
  public:
ImageTraversal *travpointer;
    Iterator();
    Iterator(Point * point, ImageTraversal * imtrav);
Point * point_;
    Iterator & operator++();
    Point operator*();
    bool operator!=(const Iterator &other);
	//static double calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2);

  
  private:

  };  


  virtual Iterator begin() = 0;
  virtual Iterator end() = 0;

  virtual void add(const Point & t) = 0;
 // virtual void add(Point & t) = 0;
  virtual Point pop() = 0;
  virtual Point peek() const = 0;
  virtual bool empty() const = 0;

private:
  static double calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2);  
  static double calculateDelta(HSLAPixel & p1, HSLAPixel & p2);  
};




#endif
