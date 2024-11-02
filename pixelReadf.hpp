#ifndef PIXELREADF_HPP
#define PIXELREADF_HPP
#include "Image.cpp"

void PixelData(std::ifstream& file, Image& image, uint16_t bitCount);
void Read24BitColor(const std::vector<uint8_t>& pixelData, Image& image, int rowSize);
void Read32BitColor(const std::vector<uint8_t>& pixelData, Image& image, int rowSize);

#endif
