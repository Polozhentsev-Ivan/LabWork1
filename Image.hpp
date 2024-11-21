/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
LabWork 1 project
*/
#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstdint>
#include <vector>
#include <iostream>
#include <string>
#include "BMPheader.hpp"
#include <variant>
#include <fstream>
#pragma pack(push, 1)
struct Pixel
{
    uint8_t blue = 0;
    uint8_t green = 0;
    uint8_t red = 0;
    uint8_t alpha = 0;
};
#pragma pack(pop)
class Image
{
public:
    Image();
    Image(int width, int height);
    #pragma pack(push, 1)
    uint32_t biSize;
    #pragma pack(pop)
    std::string filename;
    BITMAPFILEHEADER fileHeader;
    std::variant <BITMAPCOREHEADER, BITMAPINFOHEADER, BITMAPV2INFOHEADER, BITMAPV3INFOHEADER, BITMAPV4HEADER, BITMAPV5HEADER> DIBHeader;
    int width;
    int height;
    std::vector<Pixel> pixelData;
    uint16_t bitcount;

    
    
};
#endif
