#pragma once
#include "../01_aufgabe/image.hpp"
class Shape
{
public:
  virtual ~Shape(){};
  virtual unsigned int getArea() const = 0;
  virtual unsigned int getPerimeter() const = 0;
  virtual void draw(Image &, const unsigned char) const = 0;
  virtual Shape *copy() const = 0;
  virtual std::string const className() = 0;
};
