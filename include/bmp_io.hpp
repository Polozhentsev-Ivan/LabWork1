/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#ifndef BMP_IO_HPP
#define BMP_IO_HPP
#include "Image.hpp"
#include "pixelReadf.hpp"
#include <cstdint>
#include <vector>
#include <iostream>
#include <string>
#include <variant>
#include <fstream>

Image readBMP(const std::string& filename);
void writeBMP(const Image& image,const std::string& filename);

#endif
