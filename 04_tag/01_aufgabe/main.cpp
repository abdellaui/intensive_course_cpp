#include <iostream>
#include "image.hpp"

int main()
{
    Image img(512, 512);

    if (img.read("lena.pgm"))
    {
        //img.set({255,255},255);
        //img.read("lena.pgm");
        img.fillRectangle({150, 5}, {400, 50}, 0);
        img.fillTriangle({210, 300}, 201, 30);
        img.fillCircle({430, 410}, 50, 0);
        img.write("output.pgm");
    }
    return 0;
}
