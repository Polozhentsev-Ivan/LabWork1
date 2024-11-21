#include "Image.hpp"
Image::Image() : width(0), height(0) {}
Image::Image(int width, int height) : width(width), height(height) {}
Image::Image(const Image& other) : width(other.width), height(other.height), pixelData(other.pixelData), fileHeader(other.fileHeader), DIBHeader(other.DIBHeader), biSize(other.biSize), bitcount(other.bitcount)
{
}


Image& Image::operator=(const Image& other)
{
    if (this == &other){
        return *this;
    }
    width = other.width;
    height = other.height;
    pixelData = other.pixelData;
    fileHeader = other.fileHeader;
    DIBHeader = other.DIBHeader;
    biSize = other.biSize;
    bitcount = other.bitcount;
    return *this;
}

