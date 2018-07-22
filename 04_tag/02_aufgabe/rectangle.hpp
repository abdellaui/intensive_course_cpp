#pragma once
#include "shape.hpp"
class Rectangle : public Shape
{
public:
  Rectangle(Position, Position);
  virtual ~Rectangle() {}
  std::string const className()override;
  unsigned int getArea() const override;
  unsigned int getPerimeter() const override;
  Position getPosition_edge_1() const;
  Position getPosition_edge_2() const;
  void draw(Image &, unsigned char) const override;
  Rectangle *copy() const override;

private:
  Position m_edge_1;
  Position m_edge_2;
};