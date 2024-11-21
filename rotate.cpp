/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#include "rotate.hpp"
#include <stdexcept>
#include <cassert>



Image rotate(const Image& image, int angle)
{

    angle = angle % 360;  // Нормализуем угол
    if (angle == 270)
    {
        int newWidth = image.height;
        int newHeight = image.width;
        std::vector<Pixel> newPixelData(image.pixelData.size());

        for (int y = 0; y < image.height; ++y)
        {
            for (int x = 0; x < image.width; ++x)
            {
                int srcIndex = y * image.width + x;
                int destIndex = x * newWidth + (newWidth - y - 1);
                newPixelData[destIndex] = image.pixelData[srcIndex];
            }
        }
        Image rotatedImage = image;
        rotatedImage.width = newWidth;
        rotatedImage.height = newHeight;
        rotatedImage.pixelData = newPixelData;
        std::visit([&](auto& header)
        {
            header.biWidth = newWidth;
            header.biHeight = newHeight;
        }, rotatedImage.DIBHeader);
        return rotatedImage;
    }
    if (angle == 90)
    {
        int newWidth = image.height;
        int newHeight = image.width;
        std::vector<Pixel> newPixelData(image.pixelData.size());

        for (int y = 0; y < image.height; ++y)
        {
            for (int x = 0; x < image.width; ++x)
            {
                int srcIndex = y * image.width + x;
                int destIndex = (newHeight - x - 1) * newWidth + y;
                newPixelData[destIndex] = image.pixelData[srcIndex];
            }
        }
        Image rotatedImage = image;
        rotatedImage.width = newWidth;
        rotatedImage.height = newHeight;
        rotatedImage.pixelData = newPixelData;
        std::visit([&](auto& header)
        {
            header.biWidth = newWidth;
            header.biHeight = newHeight;
        }, rotatedImage.DIBHeader);
        return rotatedImage;
    }
    else {
        throw std::runtime_error("Unsupported angle: " + angle);
    }
}
