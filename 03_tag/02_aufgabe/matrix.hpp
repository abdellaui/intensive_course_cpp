#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_
#include <iostream>
class Matrix
{
public:
  Matrix();
  Matrix(const double a, const double b, const double c, const double d);

  void inversion();
  void pow(const int);
  void add(const Matrix& );
  void minus(Matrix&);
  void mult(const double skalar);
  void mult(const Matrix& );

  bool operator==(const Matrix&) const;
  void operator=(const Matrix&);
  void operator+=(const Matrix&);
  void operator-=(Matrix&);
  void operator*=(const Matrix&);

  double determinante() const;
  void output() const;

  void setByIndex(const int index, const double value);
  void setAll(const double a, const double b, const double c, const double d);

private:
  //    | a | b |
  //    | c | d |
  double a = 0.0;
  double b = 0.0;
  double c = 0.0;
  double d = 0.0;
};

#endif