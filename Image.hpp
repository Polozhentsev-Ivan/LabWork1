/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
LabWork 1 project
*/
#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstint>
#include <vector>
#include <iostream>
#include <string>
#include "BMPheader.hpp"
#include <variant>
#include <fstream>

struct Pixel
{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
}

class Image
{
public:
    std::string filename
    BITMAPFILEHEADER fileHeader
    std::variant <BITMAPCOREHEADER, BITMAPINFOHEADER, BITMAPV2INFOHEADER, BITMAPV3INFOHEADER, BITMAPV4HEADER, BITMAPV5HEADER> DIBHeader
    int width;
    int height;
    std::vector<std::vector<Pixel>> dataOfImage;
    Image();
    Image(int width, int height);
    
    
}
#endif
