#include "matrix.hpp"

Matrix::Matrix(const double a, const double b, const double c, const double d) : a(a), b(b), c(c), d(d)
{
}
Matrix::Matrix(){}

double Matrix::determinante() const
{
    return ((this->a * this->d) - (this->b * this->c));
}

void Matrix::inversion()
{
    if (this->determinante() == 0.)
    {
        std::cout << "Inversion nicht moeglich!" << std::endl;
    }
    double det = this->determinante();
    double helpA = this->a;
    this->a = this->d / det;
    this->b /= (-1 * det);
    this->c /= (-1 * det);
    this->d = helpA / det;
};

void Matrix::setAll(const double a, const double b, const double c, const double d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

void Matrix::setByIndex(const int index, const double value)
{
    switch (index)
    {
    case 11:
        this->a = value;
        break;
    case 12:
        this->b = value;
        break;
    case 21:
        this->c = value;
        break;
    case 22:
        this->d = value;
        break;
    default:
        std::cout << "Gueltige Indexe: '11', '12', '21' '22'!" << std::endl;
        break;
    }
}

void Matrix::add(const Matrix &other)
{
    this->setAll((this->a + other.a), (this->b + other.b),
                 (this->c + other.c), (this->d + other.d));
}
void Matrix::minus(Matrix & other)
{
    other.setAll((-1 * other.a), (-1 * other.b), (-1 * other.c), (-1 * other.d));
    this->add(other);
    other.setAll((-1 * other.a), (-1 * other.b), (-1 * other.c), (-1 * other.d));

   
}
void Matrix::mult(const Matrix &other)
{
    double new_a = this->a * other.a + this->b * other.c;
    double new_b = this->a * other.b + this->b * other.d;
    double new_c = this->c * other.a + this->d * other.c;
    double new_d = this->c * other.b + this->d * other.d;

    this->setAll(new_a, new_b, new_c, new_d);
}

void Matrix::mult(const double skalar)
{
    this->setAll((this->a * skalar), (this->b * skalar), (this->c * skalar), (this->d * skalar));
}

void Matrix::pow(int const skalar)
{   
    Matrix hilf;
    hilf = *this;

    Matrix * temp = this;
    temp->output();
    if (skalar == 0)
        this->setAll(1.0, 0.0, 0.0, 1.0);
    else if (skalar < 0)
    {
        this->inversion();
        this->pow((-1 * skalar));  // A^-x = (A^-1)^x
    }
    else
    {
        for (int i = 0; i < skalar - 1; i++)
        {
            //*temp *= *temp;
            temp->mult(hilf);
        }
    }
}

void Matrix::output() const
{
    std::cout << "| " << this->a << "\t" << this->b << " |" << std::endl;
    std::cout << "| " << this->c << "\t" << this->d << " |" << std::endl
              << std::endl;
}

void Matrix::operator=(const Matrix &other)
{
    this->setAll(other.a, other.b, other.c, other.d);
}

bool Matrix::operator==(const Matrix &other) const
{
    if (this->a != other.a || this->b != other.b || this->c != other.c || this->d != other.d)
        return false;
    else
        return true;
}

void Matrix::operator+=(const Matrix &other)
{
    this->add(other);
}

void Matrix::operator-=(Matrix &other)
{
    other.setAll((-1 * other.a), (-1 * other.b), (-1 * other.c), (-1 * other.d));
    this->add(other);
    other.setAll((-1 * other.a), (-1 * other.b), (-1 * other.c), (-1 * other.d));
}

void Matrix::operator*=(const Matrix &other)
{
    this->mult(other);
}
