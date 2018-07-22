#pragma once
#include "shape.hpp"
class Circle : public Shape
{
public:
  Circle(Position position, unsigned int radius) : m_position(position), m_radius(radius){};
  virtual ~Circle(){}
  std::string const className()override;
  unsigned int getArea() const override;
  unsigned int getPerimeter() const override;
  void draw(Image &, unsigned char) const override;
  Circle * copy () const override;
  Position getPosition() const;
  unsigned int getRadius() const;

private:
  unsigned int m_radius;
  Position m_position;
};