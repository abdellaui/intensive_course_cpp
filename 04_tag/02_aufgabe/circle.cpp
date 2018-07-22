#include "circle.hpp"

unsigned int Circle::getArea() const
{
    return (M_PI * m_radius * m_radius);
}
unsigned int Circle::getPerimeter() const
{
    return (M_PI * m_radius * 2);
}
void Circle::draw(Image &img, unsigned char v) const
{
    img.fillCircle(m_position, m_radius, v);
}

Position Circle::getPosition() const
{
    return m_position;
}

unsigned int Circle::getRadius() const
{
    return m_radius;
}

Circle * Circle::copy() const
{
    return new Circle(*this);   
}

std::string const Circle::className()
{
    return "Kreis";
}