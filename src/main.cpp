/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#include <iostream>
#include <string>
#include <filesystem> // Для работы с файловой системой
#include "Image.hpp"
#include "bmp_io.hpp"
#include "rotate.hpp"
#include "gausse.hpp"
#include <chrono>
#include <omp.h>

int main()
{
    // Создаем директорию results, если она не существует
    if (!std::filesystem::exists("results")) {
        std::filesystem::create_directory("results");
    }
    std::cout << "Automatically or not? (y/n): ";
    std::string c;
    std::cin >> c;
    if (c == "y")
    {
        std::string filename;
        std::cout << "Enter the name of your bmp file (from samples/): ";
        std::cin >> filename;
        std::string fullPath = "samples/" + filename;
        Image image = readBMP(fullPath);
        auto t0 = std::chrono::steady_clock::now();
        Image rotatedImage = rotate(image, 270);
        std::string rotatedFilename = "results/rotated270_" + filename;
        auto dt = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - t0).count();
        std::cout << "Rotation 270 elapsed: " << dt << " ms\n";
        writeBMP(rotatedImage, rotatedFilename);
        std::cout << "File saved as " << rotatedFilename << "\n";
        t0 = std::chrono::steady_clock::now();
        rotatedImage = rotate(image, 90);
        rotatedFilename = "results/rotated90_" + filename;
        dt = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - t0).count();
        std::cout << "Rotation 90 elapsed: " << dt << " ms\n";
        writeBMP(rotatedImage, rotatedFilename);
        std::cout << "File saved as " << rotatedFilename << "\n";
        t0 = std::chrono::steady_clock::now();
        Image filteredImage = filterImage(rotatedImage, 3, 1);
        std::string filteredFilename = "results/gausse(3x3, 1.0f)_" + filename;
        dt = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - t0).count();
        std::cout << "Filter elapsed: " << dt << " ms\n";
        writeBMP(filteredImage, filteredFilename);
        std::cout << "File saved as " << filteredFilename << std::endl;
    }
    else if (c == "n")
    {

        std::string filename;
        std::cout << "Enter the name of your bmp file (from samples/): ";
        std::cin >> filename;
        std::string fullPath = "samples/" + filename;
        Image image = readBMP(fullPath);


        std::cout << "Do you want to rotate your image? (y/n): ";
        std::cin >> c;
        if (c == "y")
        {
            double angle;
            std::cout << "Enter the angle of rotation (90, 270 degrees clockwise): ";
            std::cin >> angle;
            Image rotatedImage = rotate(image, angle);
            std::string rotatedFilename = "results/rotated_" + filename;
            writeBMP(rotatedImage, rotatedFilename);
            std::cout << "File saved as " << rotatedFilename << "\n";
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
            std::string filteredFilename = "results/gausse_" + filename;
            writeBMP(filteredImage, filteredFilename);
            std::cout << "File saved as " << filteredFilename << std::endl;
        }
    }
    return 0;
}
