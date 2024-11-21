#include "bmp_io.hpp"

void writeBMP(const Image& image, const std::string& filename)
{
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<const char*>(&image.fileHeader), sizeof(image.fileHeader));
    uint32_t dibHeaderSize = image.biSize;
    file.write(reinterpret_cast<const char*>(&dibHeaderSize), sizeof(dibHeaderSize));
    file.write(reinterpret_cast<const char*>(&image.DIBHeader), sizeof(image.DIBHeader));
    std::streampos currentPos = file.tellp();
    std::cout << currentPos << "\n";
    int paddingToData = image.fileHeader.bfOffBits - currentPos;
    if (paddingToData > 0) 
    {
        std::vector<uint8_t> padding(paddingToData, 0);
        file.write(reinterpret_cast<const char*>(padding.data()), paddingToData);
    }
    file.seekp(image.fileHeader.bfOffBits, std::ios::beg);
    int width = image.width;
    int height = image.height;
    uint16_t bitCount = image.bitcount;


    int bytes = bitCount / 8;
    int row_padded = (width * bytes + 3) & (~3);
    int paddingSize = row_padded - width * bytes;
    size_t pixelIndex = 0;


    std::vector<uint8_t> padding1(paddingSize, 0);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            file.write(reinterpret_cast<const char*>(&image.pixelData[pixelIndex].red), 1);
            file.write(reinterpret_cast<const char*>(&image.pixelData[pixelIndex].green), 1);
            file.write(reinterpret_cast<const char*>(&image.pixelData[pixelIndex++].blue), 1);
        }

        if (paddingSize > 0)
        {
            file.write(reinterpret_cast<const char*>(padding1.data()), paddingSize);
        }
    }
}
