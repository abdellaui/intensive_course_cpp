#include "rectangle.hpp"

Rectangle::Rectangle(Position edge_1, Position edge_2)
{
    if (edge_1.x == edge_2.x || edge_1.y == edge_2.y)
    {
        exit(0);
    }
    if (edge_1.x > edge_2.x && edge_1.y < edge_2.y)
    {
        std::swap(edge_2.x, edge_1.x);
    }
    if (edge_1.x < edge_2.x && edge_1.y > edge_2.y)
    {
        std::swap(edge_2.y, edge_1.y);
    }

    m_edge_1 = edge_1;
    m_edge_2 = edge_2;
}

unsigned int Rectangle::getArea() const 
{
    return ((m_edge_2.x - m_edge_1.x) * (m_edge_2.y - m_edge_1.y));
}
unsigned int Rectangle::getPerimeter() const 
{
    return (2 * (m_edge_2.x - m_edge_1.x) + 2 * (m_edge_2.y - m_edge_1.y));
}
void Rectangle::draw(Image &img, unsigned char v) const
{
    img.fillRectangle(m_edge_1, m_edge_2, v);
}

Position Rectangle::getPosition_edge_1() const
{
    return m_edge_1;
}
Position Rectangle::getPosition_edge_2() const
{
    return m_edge_2;
}

Rectangle * Rectangle::copy() const
{
    return new Rectangle(*this);   
}

std::string const Rectangle::className()
{
    return "Rechteck";
}
