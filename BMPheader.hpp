#ifndef BMPHEADER_HPP
#define BMPHEADER_HPP

#pragma pack(push, 1)

struct BITMAPFILEHEADER
{
    uint16_t bfType; //Всегда BM
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};

struct BITMAPCOREHEADER
{
    uint16_t biWidth;
    uint16_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount; //1, 4, 8, 24
};
struct BITMAPINFOHEADER
{
    int32_t biWidth;
    int32_t biHeight; // если + -- "bottom-uo", если - -- "top-down"
    uint16_t biPlanes; //1
    uint16_t biBitCount; //1, 4, 8, 16, 24, 32
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};
struct BITMAPV2INFOHEADER
{
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount; //1, 4, 8, 16, 24, 32
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
    uint32_t bV4RedMask;
    uint32_t bV4GreenMask;
    uint32_t bV4BlueMask;
    
};
struct BITMAPV3INFOHEADER
{
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount; //1, 4, 8, 16, 24, 32
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
    uint32_t bV4RedMask;
    uint32_t bV4GreenMask;
    uint32_t bV4BlueMask;
    uint32_t bV4AlphaMask;
};
struct BITMAPV4HEADER
{
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
    uint32_t bV4RedMask;
    uint32_t bV4GreenMask;
    uint32_t bV4BlueMask;
    uint32_t bV4AlphaMask;
    uint32_t bV4CSType;
    int32_t bV4Endpoints[9];
    uint32_t bV4GammaRed;
    uint32_t bV4GammaGreen;
    uint32_t bV4GammaBlue;
};
struct BITMAPV5HEADER
{
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
    uint32_t bV4RedMask;
    uint32_t bV4GreenMask;
    uint32_t bV4BlueMask;
    uint32_t bV4AlphaMask;
    uint32_t bV4CSType;
    int32_t bV4Endpoints[9];
    uint32_t bV4GammaRed;
    uint32_t bV4GammaGreen;
    uint32_t bV4GammaBlue;
    uint32_t bV5Intent;
    uint32_t bV5ProfileData;
    uint32_t bV5ProfileSize;
    uint32_t bV5Reserved; // 0
};

#pragma pack(pop)

#endif
