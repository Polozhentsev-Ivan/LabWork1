#include <iostream>
#include <string>
#include "Image.hpp"
#include "bmp_io.hpp"
#include "rotate.hpp"
#include "gausse.hpp"

int main()
{
    std::string filename;
    std::cout << "Enter the name of your bmp file: ";
    std::cin >> filename;
    
    Image image = readBMP(filename);
    
    std::string c;
    std::cout << "Do you want to rotate your image? (y/n): ";
    std::cin >> c;
    if (c == "y")
    {
    
    
        double angle;
        std::cout << "Enter the angle of rotation (90, 180, 270 degrees clockwise): ";
        std::cin >> angle;
        Image rotatedImage = rotate(image, angle);
        std::string rotatedFilename = "rotated_" + filename;
        writeBMP(rotatedImage, rotatedFilename);
        std::cout << "File saved as " << rotatedFilename;
    }
    
    /*std::cout << "Do you want to apply Gausse filter on your image? (y/n): ";
    std::cin >> c;
    if (c == "y")
    {
        int kernelSize;
        double sigma;
        c::out << "Enter size of the core (3,5,7): ";
        c::in >> kernelSize;         
        c::out << "Enter the sigma value: ";
        c::in >> sigma;
        Image filteredImage = filterImage(image, kernelSize, sigma);
        std::string filteredFilename = filename + "_gausse.bmp"
        writeBMP(filteredImage, filteredFilename);
        std::cout << "File saved as " << filteredFilename;
    }*/
    return 0;
}
