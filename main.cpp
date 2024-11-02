#include <iostream>
#include <string>
#include "Image.hpp"
#include "bmp-io.hpp"
#include "rotate.hpp"
#include "gausse.hpp"

int main()
{
    std::string filename;
    std::cout << "Enter the name of your bmp file: ";
    std::cin >> filename;
    
    Image image = readBMP(filename);
    
    char c;
    std::cout << "Do you want to rotate your image? (y/n): "
    std::cin >> c;
    if (c == "y")
    {
    
    
        double angle;
        c::out << "Enter the angle of rotation: ";
        c::in >> angle
        Image rotatedImage = rotateImage(image, angle);
        std::string rotatedFilename = filename + "_rotated.bmp"
        writeBMP(rotatedImage, rotatedFilename);
        std::cout << "File saved as " << rotatedFilename;
    }
    
    std::cout << "Do you want to apply Gausse filter on your image? (y/n): ";
    std::cin >> c;
    if (c == "y")
    {
        int kernelSize;
        double sigma;
        c::out << "Enter size of the core (3,5,7): ";
        c::in >> kernelSize;         
        c::out << "Enter the sigma value: ";
        c::in >> sigma;
        Image filteredImage = filterImage(image, angle);
        std::string filteredFilename = filename + "_gausse.bmp"
        writeBMP(filteredImage, filteredFilename);
        std::cout << "File saved as " << filteredFilename;
    }
    return 0;
}
