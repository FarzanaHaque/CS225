/**
 * Copyright 2011 University of Illinois at Urbana-Champaign
 * CS 225 Lab 04 C++ Object Oriented Programming
 * Authors:
 *   Simon Krueger <skruege2@illinois.edu>
 *   Modified (FA17): Jordi Paris Ferrer <parisfe2@illinois.edu>
 */

#ifndef FLOWER_H_
#define FLOWER_H_

#include "shape.h"

//are we allowed to include following headers?????
#include "circle.h"
#include "color.h"
#include "rectangle.h"
#include "triangle.h"
class Flower : public Drawable
{
  private:
    Shape * stem;
    Shape * pistil; // center piece of flower
    Shape * leaf;
/*Rectangle stem;
Circle pistil;
Triangle leaf;*/
  /* const Vector2 stem_center(center.x(), center.y() + STEM_HEIGHT / 2);
    Rectangle my_stem(stem_center, STEM_COLOR, STEM_WIDTH, STEM_HEIGHT);
   //stem = my_stem;

    Circle my_pistil(Vector2(center.x(), center.y() - PISTIL_RADIUS / 2),
                     PISTIL_COLOR, PISTIL_RADIUS);
   //pistil = my_pistil;

    const Vector2 leaf_center(stem_center.x() - STEM_WIDTH / 2 + 1,
                              stem_center.y() + STEM_HEIGHT / 4);
    Triangle my_leaf(LEAF_COLOR,
        Vector2(leaf_center.x(), leaf_center.y() - STEM_HEIGHT / 4),
        Vector2(leaf_center.x() - LEAF_WIDTH, leaf_center.y() - LEAF_HEIGHT),
        Vector2(leaf_center.x() - LEAF_WIDTH / 2, leaf_center.y()));
    //leaf = my_leaf;*/

    void drawPetals(PNG* canvas, const Vector2& center, int x, int y) const;

  public:
    Flower(const Vector2& center);
    void draw(PNG* canvas) const; ///////////////need to change so it's not coming from shape
};

#endif // FLOWER_H_
