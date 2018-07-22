#include "shapecontainer.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
int main()
{

    Circle * v = new Circle({70,70},40);
    std::vector<Shape *> elements = {
       new Circle({70,270},40),
       new Circle({345,170},34),
       new Circle({250,120},56),
       new Triangle({430,340},38),

    };
    ShapeContainer a(elements);
    ShapeContainer b(a);

    // a.addElement(new Triangle({170,170}, 50));
    // a.addElement(new Rectangle({370,370},{470,470}));
    a.addElement(v);
    a.generateImage(512, 512, 0);
    a.printCircles();
    a.printSortedContent(PREMITER);
    b.printSortedContent(PREMITER);

    return 0;
}
