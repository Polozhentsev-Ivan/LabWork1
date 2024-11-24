/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#include "bmp_io.hpp"

void writeBMP(const Image& image, const std::string& filename)
{
    std::ofstream file(filename, std::ios::binary);
    file.write(reinterpret_cast<const char*>(&image.fileHeader), sizeof(image.fileHeader));
    uint32_t dibHeaderSize = image.biSize;
    file.write(reinterpret_cast<const char*>(&dibHeaderSize), sizeof(dibHeaderSize));
    file.write(reinterpret_cast<const char*>(&image.DIBHeader), sizeof(image.DIBHeader));
    std::streampos currentPos = file.tellp();
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
    
    std::vector<uint8_t> rowBuffer(row_padded); 

    for (int y = 0; y < height; ++y)
    {
        size_t rowStartIndex = y * width; 

        for (int x = 0; x < width; ++x)
        {
            size_t pixelIndex = rowStartIndex + x;

            
            rowBuffer[x * bytes + 0] = image.pixelData[pixelIndex].red;
            rowBuffer[x * bytes + 1] = image.pixelData[pixelIndex].green;
            rowBuffer[x * bytes + 2] = image.pixelData[pixelIndex].blue;
        }

        
        if (paddingSize > 0)
        {
            std::fill(rowBuffer.begin() + width * bytes, rowBuffer.end(), 0);
        }

        
        file.write(reinterpret_cast<const char*>(rowBuffer.data()), row_padded);
    }
}
