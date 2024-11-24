/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#include "rotate.hpp"
#include <stdexcept>
#include <cassert>



Image rotate(const Image& image, int angle)
{
    angle = angle % 360;
    if (angle != 90 & angle != 270)
    {
        throw std::runtime_error("Unsupported angle: " + angle);
    }
    int newWidth = image.height;
    int newHeight = image.width;
    Image rotatedImage = image;
    rotatedImage.width = newWidth;
    rotatedImage.height = newHeight;
    rotatedImage.pixelData = std::vector<Pixel>(image.pixelData.size());
    for (int y = 0; y < image.height; ++y)
    {
        for (int x = 0; x < image.width; ++x)
        {
            int srcIndex = y * image.width + x;
            if (angle == 270)
            {
                int destIndex = x * newWidth + (newWidth - y - 1);
                rotatedImage.pixelData[destIndex] = image.pixelData[srcIndex];
            }
            else if (angle == 90)
            {
                int destIndex = (newHeight - x - 1) * newWidth + y;
                rotatedImage.pixelData[destIndex] = image.pixelData[srcIndex];
            }
        }
    }

    std::visit([&](auto& header)
    {
        header.biWidth = newWidth;
        header.biHeight = newHeight;
    }, rotatedImage.DIBHeader);
    return rotatedImage;
}
