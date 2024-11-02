/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
LabWork 1 project
*/
#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <cstint>
#include <vector>
#include <iostream>
#include <string>

#pragma pack(push, 1)

struct BITMAPFILEHEADER
{
    uint16_t bfType; //Всегда BM
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};

struct BITMAPINFOHEADER
{
    uint32_t bfSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t  biPlanes;
    uint16_t biBitCount; //1, 4, 8, 16, 24, 32
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};

struct BMPHeader
{
    BITMAPFILEHEADER fileHeader
    BITMAPINFOHEADER infoHeader
};

#pragma pack(pop)

#endif
