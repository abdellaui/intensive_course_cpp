#include "triangle.hpp"
unsigned int Triangle::getArea() const
{
    unsigned int height = static_cast<unsigned int>(sqrt(3) * (m_sideLength / 2));

    return ( m_sideLength * height / 2);
}
unsigned int Triangle::getPerimeter()const
{
    return (3*m_sideLength);
}
void Triangle::draw(Image &img, unsigned char v) const
{
    img.fillTriangle(m_edge_left, m_sideLength, v);
}

unsigned int Triangle::getSideLength() const
{
    return m_sideLength;
}

Position Triangle::getPosition_edge_left() const
{
    return m_edge_left;
}

Triangle * Triangle::copy() const
{
    return new Triangle(*this);   
}

std::string const Triangle::className()
{
    return "Dreieck";
}
