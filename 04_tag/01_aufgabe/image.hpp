#pragma once
#include <cstdio>
#include <string>
#include <iostream>
#include <utility>
#include "pgmIO.h"
#include <cmath>
#include <cstdlib>
struct Position
{
  unsigned int x;
  unsigned int y;
};

class Image
{
private:
  unsigned int m_width;
  unsigned int m_height;
  unsigned char *mp_data;

public:
  Image() : m_width(0), m_height(0), mp_data(nullptr) {}
  Image(unsigned int width, unsigned int height);
  ~Image() { delete[] mp_data; }
  Image(const Image &rhs);
  Image &operator=(Image rhs);
  friend void swap(Image &lhs, Image &rhs);

  unsigned int getWidth() const { return m_width; }
  unsigned int getHeight() const { return m_height; }

  void fill(unsigned char v);
  void set(Position p, unsigned char v);
  void fillCircle(Position center, unsigned int radius, unsigned char v);
  void fillRectangle(Position edge_1, Position edge_2, unsigned char v);
  void fillTriangle(Position edge_left, unsigned int sideLength, unsigned char v);

  bool read(const char *filename);
  bool write(const char *filename);
};