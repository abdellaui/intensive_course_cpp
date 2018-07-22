#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "shape.hpp"
#include "circle.hpp"
enum SORTBY
{
  AREA,
  PREMITER
};
class ShapeContainer
{
public:
  //Default Konstruktor
  ShapeContainer(std::vector<Shape *>);
  ShapeContainer(){}
  ~ShapeContainer();
  //Kopierkonstruktor
  ShapeContainer(const ShapeContainer &copy);
  //Zuweisungsoperator
  ShapeContainer & operator=(ShapeContainer other){swap(*this, other); return *this;};
  friend void swap(ShapeContainer &lhs, ShapeContainer &rhs) noexcept;
  void addElement(Shape *);
  void removeElement(Shape *);
  void generateImage(unsigned int height, unsigned int width, unsigned char color) const;
  void printSortedContent(SORTBY);
  void printCircles() const;

private:
  std::vector<Shape *> m_elements;
};

inline void swap(ShapeContainer &lhs, ShapeContainer &rhs) noexcept
{
    using std::swap;
    swap(lhs.m_elements, rhs.m_elements);;
}
