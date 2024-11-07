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
    const uint32_t rowSize = ((image.bitcount * image.width + 31)/32) * 4;
    int height = std::abs(image.height);
    bool isBottomUp = image.height > 0;
    
    for (int i = 0; i < height; ++i)
    {
        int rowIndex = isBottomUp ? (height - 1 - i) : i;
        if (image.pixelData[rowIndex].size() < rowSize)
        {
            std::vector<Pixel> paddedRow = image.pixelData[rowIndex];
            paddedRow.resize(rowSize);
            file.write(reinterpret_cast<const char*>(paddedRow.data()), rowSize);
            
        } 
        else 
        {
            file.write(reinterpret_cast<const char*>(image.pixelData[rowIndex].data()), rowSize);
        }
    }
    file.close();
    
}
