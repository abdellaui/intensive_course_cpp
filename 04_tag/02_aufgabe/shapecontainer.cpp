#include "shapecontainer.hpp"
struct lessArea
{
    inline bool operator()(Shape *const shape1, Shape *const shape2)
    {
        return (shape1->getArea() < shape2->getArea());
    }
};
struct lessPerimiter
{
    inline bool operator()(Shape *const shape1, Shape *const shape2)
    {
        return (shape1->getPerimeter() < shape2->getPerimeter());
    }
};
ShapeContainer::ShapeContainer(std::vector<Shape *> elements)
{
    m_elements = elements;
}

ShapeContainer::~ShapeContainer()
{
    for (size_t i = 0; i < m_elements.size(); i++)
        delete m_elements.at(i);
    m_elements.clear();
}
//Copyconstructor
ShapeContainer::ShapeContainer(const ShapeContainer &copy)
{
    //m_elements = std::vector<Shape *>(copy.m_elements.size());
    for(size_t i = 0; i<copy.m_elements.size(); i++)
        m_elements.push_back(copy.m_elements.at(i)->copy());
}

void ShapeContainer::addElement(Shape *insert)
{
    m_elements.push_back(insert);
}

void ShapeContainer::removeElement(Shape *remove_item)
{
    m_elements.erase(std::remove(m_elements.begin(), m_elements.end(), remove_item), m_elements.end());
}
void ShapeContainer::generateImage(unsigned int height, unsigned int width, unsigned char color) const
{
    Image img(height, width);
    img.fill(255);
    for (int i = 0; i < m_elements.size(); i++)
        m_elements.at(i)->draw(img, color);
    img.write("output.pgm");
}
void ShapeContainer::printSortedContent(SORTBY type)  
{
    if (type == AREA)
    {
        std::sort(m_elements.begin(), m_elements.end(), lessArea());
        for (int i = 0; i < m_elements.size(); i++)
        {
            std::cout<< m_elements.at(i)->className() << " Fleacheninhalt: " << m_elements.at(i)->getArea()<<std::endl;
        }
    }
    else
    {
        std::sort(m_elements.begin(), m_elements.end(), lessPerimiter());
        for (int i = 0; i < m_elements.size(); i++)
        {
            std::cout << m_elements.at(i)->className() << " Umfang: " << m_elements.at(i)->getPerimeter()<<std::endl;
        }
    }
}
void ShapeContainer::printCircles() const
{
    for (int i = 0; i < m_elements.size(); i++)
    {
        Circle *pCurrentCircle = dynamic_cast<Circle *>(m_elements.at(i));
        if (pCurrentCircle)
        {
            std::cout << "Kreis mit Flaecheninhalt: " << pCurrentCircle->getArea() << ", ";
            std::cout << "Umfang: " << pCurrentCircle->getPerimeter() << ", ";
            std::cout << "Radius: " << pCurrentCircle->getRadius() << " ";
            std::cout << "an der Position: (" << pCurrentCircle->getPosition().x << ", " << pCurrentCircle->getPosition().y << ") " << std::endl;
        }   
    }
}
