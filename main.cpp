#include <iostream>
#include <string>
#include "Image.hpp"
#include "bmp_io.hpp"
#include "rotate.hpp"
#include "gausse.hpp"

int main()
{
    std::cout << "Automatically or not? (y/n): ";
    std::string c;
    std::cin >> c;
    if (c == "y")
    {
        std::string filename;
        std::cout << "Enter the name of your bmp file: ";
        std::cin >> filename;

        Image image = readBMP(filename);
        Image rotatedImage = rotate(image, 270);
        std::string rotatedFilename = "rotated270_" + filename;
        writeBMP(rotatedImage, rotatedFilename);
        std::cout << "File saved as " << rotatedFilename << "\n";
        rotatedImage = rotate(image, 90);
        rotatedFilename = "rotated90_" + filename;
        writeBMP(rotatedImage, rotatedFilename);
        std::cout << "File saved as " << rotatedFilename << "\n";
        Image filteredImage = filterImage(rotatedImage, 3, 1);
        std::string filteredFilename = "gausse(3x3, 1.0f)_" + filename;
        writeBMP(filteredImage, filteredFilename);
        std::cout << "File saved as " << filteredFilename;

    }
    else if (c == "n")
    {

        std::string filename;
        std::cout << "Enter the name of your bmp file: ";
        std::cin >> filename;

        Image image = readBMP(filename);


        std::cout << "Do you want to rotate your image? (y/n): ";
        std::cin >> c;
        if (c == "y")
        {
            double angle;
            std::cout << "Enter the angle of rotation (90, 270 degrees clockwise): ";
            std::cin >> angle;
            Image rotatedImage = rotate(image, angle);
            std::string rotatedFilename = "rotated_" + filename;
            writeBMP(rotatedImage, rotatedFilename);
            std::cout << "File saved as " << rotatedFilename;
        }

        std::cout << "Do you want to apply Gausse filter on your image? (y/n): ";
        std::cin >> c;
        if (c == "y")
        {
            int kernelSize;
            float sigma;
            std::cout << "Enter size of the core (3,5,7): ";
            std::cin >> kernelSize;
            std::cout << "Enter the sigma value: ";
            std::cin >> sigma;
            Image filteredImage = filterImage(image, kernelSize, sigma);
            std::string filteredFilename = "gausse_" + filename;
            writeBMP(filteredImage, filteredFilename);
            std::cout << "File saved as " << filteredFilename;
        }
    }
    return 0;
}
