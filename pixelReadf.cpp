/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#include "pixelReadf.hpp"
#include <iostream>

void PixelDataR(std::ifstream& file, Image& image, uint16_t bitCount)
{
    std::cout << image.fileHeader.bfOffBits << "\n";

    file.seekg(image.fileHeader.bfOffBits, std::ios::beg);

    int width = image.width;
    int height = image.height;

    int bytes = bitCount / 8;
    std::cout << "width in bytes = " << width*bytes << "\n";
    std::cout << "height in bytes = " << height*bytes << "\n";
    int padding = (width * bytes + 3) & (~3);
    std::cout << "padding = " << padding << "\n";


    std::vector<uint8_t> data(padding * height);
    file.read(reinterpret_cast<char*>(data.data()), data.size());

    image.pixelData.resize(width * height);
    std::cout << "data size: " << data.size() << "\n";
    size_t dataIndex = 0;

    size_t pixelIndex = 0;
    int padding1 = padding % 4;


    for (int y = 0; y < height; ++y)
    {

        for (int x = 0; x < width; ++x)
        {
            uint8_t blue = data[dataIndex++];
            uint8_t green = data[dataIndex++];
            uint8_t red = data[dataIndex++];


            image.pixelData[pixelIndex++] = Pixel{red, green, blue, 255};
        }

        dataIndex += padding1;

    }

}

