#include "image.hpp"

Image::Image(const Image &rhs) : m_width(rhs.m_width), m_height(rhs.m_height)
{
    mp_data = new unsigned char[m_width * m_height];
    memcpy(mp_data, rhs.mp_data, m_width * m_height * sizeof(unsigned char));
}
Image::Image(unsigned int width, unsigned int height) : m_width(width), m_height(height)
{
    mp_data = new unsigned char[m_width * m_height];
}
Image &Image::operator=(Image rhs)
{
    swap(*this, rhs);
    return *this;
}
void Image::fill(unsigned char v)
{
    for (int i = 0; i < m_width * m_height; i++)
        mp_data[i] = v;
}
void Image::set(Position pos, unsigned char v)
{
    if (pos.x < m_width && pos.y < m_height)
        mp_data[m_width * pos.y + pos.x] = v;
}

void Image::fillCircle(Position p, unsigned int radius, unsigned char v)
{ //
    if (radius < 1 || (p.x < radius) || (p.y < radius) ||
        ((p.x + radius) > m_width) || (p.y + radius) > m_height)
        return;
    unsigned int durchmesser = 2 * radius;
    for (int i = 0; i <= durchmesser; i++)
    {
        for (int j = 0; j <= durchmesser; j++)
        {
            Position currentPosition = {(p.x - radius) + i, (p.y - radius) + j};
            if (((currentPosition.x - p.x) * (currentPosition.x - p.x) + (currentPosition.y - p.y) * (currentPosition.y - p.y)) <= radius * radius)
            {
                set(currentPosition, v);
            }
        }
    }
}

void Image::fillRectangle(Position edge_1, Position edge_2, unsigned char v)
{
    if (edge_1.x > m_width || edge_1.y > m_height || edge_2.y > m_width || edge_2.x > m_height || edge_1.x == edge_2.x || edge_1.y == edge_2.y)
        return;

    if (edge_1.x > edge_2.x && edge_1.y < edge_2.y)
    {
        std::swap(edge_2.x, edge_1.x);
    }
    if (edge_1.x < edge_2.x && edge_1.y > edge_2.y)
    {
        std::swap(edge_2.y, edge_1.y);
    }

    unsigned int x = edge_1.x;
    unsigned int y2 = (edge_2.y - edge_1.y);
    for (int i = 0; i < y2; i++)
    {
        while (x < edge_2.x && x++)
        {
            set({x, (edge_1.y + i)}, v);
        }
        x = edge_1.x;
    }
}

void Image::fillTriangle(Position edge_left, unsigned int sideLenght, unsigned char v)
{
    unsigned int height = static_cast<unsigned int>(sqrt(3) * (sideLenght / 2));
    unsigned int halfSideLength = static_cast<unsigned int>(sideLenght / 2);
    Position edge_right = {edge_left.x + sideLenght, edge_left.y};
    Position edge_top = {edge_left.x + halfSideLength, edge_left.y - height};

    if (edge_right.x > m_width || edge_right.y > m_height || edge_left.x > m_width || edge_left.y > m_height ||
        edge_top.x > m_width || edge_top.y > m_height)
        return;

    int aX = static_cast<int>(edge_left.x);
    int aY = static_cast<int>(edge_left.y);

    int bX = static_cast<int>(edge_top.x);
    int bY = static_cast<int>(edge_top.y);

    for (int currX = 0; currX <= halfSideLength; currX++)
    {
        for (int currY = 0; currY < height; currY++)
        {
            Position currentPosition = {currX + edge_left.x, edge_left.y - currY};
            int cX = static_cast<int>(currentPosition.x);
            int cY = static_cast<int>(currentPosition.y);
            if ((((bX - aX) * (cY - aY) - (bY - aY) * (cX - aX)) > 0))
            {
                set(currentPosition, v);
                set({2 * (edge_left.x + halfSideLength) - currentPosition.x, currentPosition.y}, v);
            }
        }
    }
}

bool Image::read(const char *filename)
{
    return readPGM(filename, &mp_data, &m_width, &m_height);
}

bool Image::write(const char *filename)
{
    return writePGM(filename, mp_data, m_width, m_height);
}

void swap(Image &lhs, Image &rhs)
{
    using std::swap;
    swap(lhs.m_width, rhs.m_width);
    swap(lhs.m_height, rhs.m_height);
    swap(lhs.mp_data, rhs.mp_data);
}