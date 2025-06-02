/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#include "Image.hpp"
Image::Image() : width(0), height(0) {}
Image::Image(int width, int height) : width(width), height(height) {}
Image::Image(const Image& other) : 
    biSize(other.biSize),
    filename(other.filename),
    fileHeader(other.fileHeader),
    DIBHeader(other.DIBHeader),
    width(other.width),
    height(other.height),
    pixelData(other.pixelData),
    bitcount(other.bitcount)
{
}

Image& Image::operator=(const Image& other)
{
    if (this == &other)
    {
        return *this;
    }
    biSize = other.biSize;
    filename = other.filename;
    fileHeader = other.fileHeader;
    DIBHeader = other.DIBHeader;
    width = other.width;
    height = other.height;
    pixelData = other.pixelData;
    bitcount = other.bitcount;
    return *this;
}

