#include "pixelReadf.hpp"
void Read24BitColor(const std::vector<uint8_t>& pixelData, Image& image, int rowSize)
{
    int width = image.width;
    int height = std::abs(image.height);
    bool isBottomUp = image.height > 0;
    
    for (int y = 0; y < height; ++y)
    {
        int rowIndex = isBottomUp ? (height - 1 - y) : y;
        for (int x = 0; x < width; ++x)
        {
            int pixelIndex = y * rowSize + x * 3 - 2;
            uint8_t blue = pixelData[pixelIndex];
            uint8_t green = pixelData[pixelIndex + 1];
            uint8_t red = pixelData[pixelIndex + 2];
            image.pixelData[rowIndex][x] = {blue, green, red};
        }
    }
}
void Read32BitColor(const std::vector<uint8_t>& pixelData, Image& image, int rowSize)
{
    int width = image.width;
    int height = std::abs(image.height);
    bool isBottomUp = image.height > 0;
    
    for (int y = 0; y < height; ++y)
    {
        int rowIndex = isBottomUp ? (height - 1 - y) : y;
        for (int x = 0; x < width; ++x)
        {
            int pixelIndex = y * rowSize + x * 4;
            uint8_t blue = pixelData[pixelIndex];
            uint8_t green = pixelData[pixelIndex + 1];
            uint8_t red = pixelData[pixelIndex + 2];
            image.pixelData[rowIndex][x] = {blue, green, red}; // для альфа канала будет позже
        }
    }
}
