#include "Image.hpp"
#include "bmp_io.hpp"

Image ReadBMP(const string& filename)
{
    Image image;
    image.filename = filename;
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    file.read(reinterpret_cast<char*>(&image.fileHeader), sizeof(BITMAPFILEHEADER));
    
    if(image.fileHeader.bfType != 0x4D42)
    {
        throw std::runtime_error("Your file isn't BMP format")
    }
    
    uint32_t dibHeaderSize;
    file.read(reinterpret<char*>(&dibHeaderSize), sizeof(dibHeaderSize));
    file.seekg(-static_cast<int>(sizeof(dibHeaderSize), std::ios::cur));
    
    switch (dibHeaderSize) 
    {
        case 12:
            BITMAPCOREHEADER coreHeader;
            file.read(reinterpret_cast<char*>(&coreHeader), sizeof(BITMAPCOREHEADER));
            image.DIBHeader = coreHeader;
            
            image.width = coreHeader.bcWidth;
            image.height = coreHeader.bcHeight;
            
            uint16_t bitCount = core.Header.bcBitCount;
            
            break;
        case 48:
            BITMAPINFOHEADER infoHeader;
            file.read(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));
            image.DIBHeader = infoHeader;
            
            image.width = infoHeader.biWidth;
            image.height = infoHeader.biHeight;
            
            uint16_t bitCount = infoHeader.biBitCount;
            
            break;
        case 52:
            BITMAPV2INFOHEADER v2infoHeader;
            file.read(reinterpret_cast<char*>(&v2infoHeader), sizeof(BITMAPV2INFOHEADER));
            image.DIBHeader = v2infoHeader;
            
            image.width = v2infoHeader.biWidth;
            image.height = v2infoHeader.biHeight;
            
            uint16_t bitCount = v2infoHeader.biBitCount;
            
            break;
        case 56:
            BITMAPV3INFOHEADER v3infoHeader;
            file.read(reinterpret_cast<char*>(&v3infoHeader), sizeof(BITMAPV3INFOHEADER));
            image.DIBHeader = v3infoHeader;
            
            image.width = v3infoHeader.biWidth;
            image.height = v3infoHeader.biHeight;
            
            uint16_t bitCount = v3infoHeader.biBitCount;
            
            break;
        case 108:
            BITMAPV4HEADER v4infoHeader;
            file.read(reinterpret_cast<char*>(&v4infoHeader), sizeof(BITMAPV4HEADER));
            image.DIBHeader = v4infoHeader;
            
            image.width = v4infoHeader.biWidth;
            image.height = v4infoHeader.biHeight;
            
            uint16_t bitCount = v4infoHeader.biBitCount;
            
            break;
        case 124:
            BITMAPV5HEADER v5infoHeader;
            file.read(reinterpret_cast<char*>(&v5infoHeader), sizeof(BITMAPV5HEADER));
            image.DIBHeader = v5infoHeader;
            
            image.width = v5infoHeader.biWidth;
            image.height = v5infoHeader.biHeight;
            
            uint16_t bitCount = v5infoHeader.biBitCount;
            
            break;
        default:
            throw std::runtime_error("Unknown size of DIB header of BMP file")
            break;
    }
    
}
