#ifndef BMP-IO_HPP
#define BMP-IO_HPP
#include "Image.hpp"

Image ReadBMP(const string& filename);
bool WriteBMP(Image image, filename);

#endif
