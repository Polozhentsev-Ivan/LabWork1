#include "pixelReadf.hpp"
void PixelData(std::ifstream& file, Image& image, uint16_t bitCount)
{
    file.seekg(image.fileHeader.bfOffBits, std::ios::beg);
    int rowSize = ((image.width * bitCount + 31) / 32) * 4;
    int dataSize = rowSize * std::abs(image.height);
    std::vector<uint8_t> pixelData(dataSize);
    file.read(reinterpret_cast<char*>(pixelData.data()), dataSize);
    image.data.resize(std::abs(image.height), std::vector<Pixel>(image.width));
    switch (bitCount)
    {
        case 1:
            throw std::runtime_error("Temporary that color depth (1) isn't supported");
            break;
        case 4:
            throw std::runtime_error("Temporary that color depth (4) isn't supported");
            break;
        case 8:
            throw std::runtime_error("Temporary that color depth (8) isn't supported");
            break;
        case 16:
            throw std::runtime_error("Temporary that color depth (16) isn't supported");
            break;
        case 24:
            Read24BitColor(pixelData, image, rowSize);
            break;
        case 32:
            Read32BitColor(pixelData, image, rowSize);
            break;
        default:
            throw std::runtime_error("Unsupported color depth: " + std::to_string(bitCount));
            break;
    }
}
