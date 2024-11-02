#include "Image.hpp"

std::ifstream file("image.bmp", std::ios::binary);

BMPHeader bmpHeader;

file.read(reinterpret_cast<char*>(&bmpHeader.fileHeader), sizeof(BITMAPFILEHEADER));

file.read(reinterpret_cast<char*>(&bmpHeader.infoHeader), sizeof(BITMAPFILEHEADER));

