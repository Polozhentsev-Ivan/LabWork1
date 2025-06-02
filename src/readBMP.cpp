/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#include "bmp_io.hpp"


Image readBMP(const std::string& filename)
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
        throw std::runtime_error("Your file isn't BMP format");
    }

    std::cout << "Data size: " << image.fileHeader.bfSize << "\n";

    uint32_t dibHeaderSize;
    file.read(reinterpret_cast<char*>(&dibHeaderSize), sizeof(dibHeaderSize));
    image.biSize = dibHeaderSize;
    // Try to implement template function
    switch (dibHeaderSize)
    {
    case 12:
    {
        BITMAPCOREHEADER coreHeader;
        file.read(reinterpret_cast<char*>(&coreHeader), sizeof(BITMAPCOREHEADER));
        image.DIBHeader = coreHeader;

        image.width = coreHeader.biWidth;
        image.height = coreHeader.biHeight;

        uint16_t bitCount = coreHeader.biBitCount;
        image.bitcount = bitCount;
        PixelDataR(file, image, bitCount);
        break;
    }
    case 48:
    {
        BITMAPINFOHEADER infoHeader;
        file.read(reinterpret_cast<char*>(&infoHeader), sizeof(BITMAPINFOHEADER));
        image.DIBHeader = infoHeader;

        image.width = infoHeader.biWidth;
        image.height = infoHeader.biHeight;

        uint16_t bitCount = infoHeader.biBitCount;
        image.bitcount = bitCount;
        PixelDataR(file, image, bitCount);
        break;
    }
    case 52:
    {
        BITMAPV2INFOHEADER v2infoHeader;
        file.read(reinterpret_cast<char*>(&v2infoHeader), sizeof(BITMAPV2INFOHEADER));
        image.DIBHeader = v2infoHeader;

        image.width = v2infoHeader.biWidth;
        image.height = v2infoHeader.biHeight;

        uint16_t bitCount = v2infoHeader.biBitCount;
        image.bitcount = bitCount;
        PixelDataR(file, image, bitCount);
        break;
    }
    case 56:
    {
        BITMAPV3INFOHEADER v3infoHeader;
        file.read(reinterpret_cast<char*>(&v3infoHeader), sizeof(BITMAPV3INFOHEADER));
        image.DIBHeader = v3infoHeader;

        image.width = v3infoHeader.biWidth;
        image.height = v3infoHeader.biHeight;

        uint16_t bitCount = v3infoHeader.biBitCount;
        image.bitcount = bitCount;
        PixelDataR(file, image, bitCount);
        break;
    }
    case 108:
    {
        BITMAPV4HEADER v4infoHeader;
        file.read(reinterpret_cast<char*>(&v4infoHeader), sizeof(BITMAPV4HEADER));
        image.DIBHeader = v4infoHeader;

        image.width = v4infoHeader.biWidth;
        image.height = v4infoHeader.biHeight;

        uint16_t bitCount = v4infoHeader.biBitCount;
        image.bitcount = bitCount;
        PixelDataR(file, image, bitCount);
        break;
    }
    case 124:
    {
        BITMAPV5HEADER v5infoHeader;
        file.read(reinterpret_cast<char*>(&v5infoHeader), sizeof(BITMAPV5HEADER));
        image.DIBHeader = v5infoHeader;
        image.width = v5infoHeader.biWidth;
        image.height = v5infoHeader.biHeight;

        uint16_t bitCount = v5infoHeader.biBitCount;
        image.bitcount = bitCount;
        PixelDataR(file, image, bitCount);
        break;
    }
    default:
        throw std::runtime_error("Unknown size of DIB header of BMP file");
        break;
    }
    file.close();
    std::cout << "Чтение прошло успешно" << "\n";
    return image;

}
