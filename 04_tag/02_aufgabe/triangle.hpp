#pragma once
#include "shape.hpp"
class Triangle : public Shape
{
public:
  Triangle(Position p, unsigned int sideLength) : m_edge_left(p), m_sideLength(sideLength) {}
  virtual ~Triangle() {}
  std::string const className()override;
  unsigned int getArea() const override;
  unsigned int getPerimeter() const override;
  Position getPosition_edge_left() const;
  unsigned int getSideLength() const;
  void draw(Image &, unsigned char) const override;
  Triangle *copy() const override;

private:
  Position m_edge_left;
  unsigned int m_sideLength;
};