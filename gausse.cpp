/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#include "gausse.hpp"
Pixel applyKernel(const Image& image, const std::vector<std::vector<float>>& kernel, int x, int y)
{
    int kernelSize = kernel.size();
    int offset = kernelSize / 2;
    float sumR = 0, sumG = 0, sumB = 0;
    float sumKernel = 0;

    for (int ky = -offset; ky <= offset; ++ky)
    {
        for (int kx = -offset; kx <= offset; ++kx)
        {
            int ix = x + kx;
            int iy = y + ky;

            if (ix >= 0 && ix < image.width && iy >= 0 && iy < image.height)
            {
                int idx = iy * image.width + ix;
                float kernelValue = kernel[ky + offset][kx + offset];
                sumR += image.pixelData[idx].red * kernelValue;
                sumG += image.pixelData[idx].green * kernelValue;
                sumB += image.pixelData[idx].blue * kernelValue;
                sumKernel += kernelValue;
            }
        }
    }
    if (sumKernel == 0)
    {
        sumKernel = 1.0f;
    }

    auto clamp = [](float value) -> unsigned char {
        return static_cast<unsigned char>(std::min(std::max(value, 0.0f), 255.0f));
    };

    Pixel result;
    result.red = clamp(sumR / sumKernel);
    result.green = clamp(sumG / sumKernel);
    result.blue = clamp(sumB / sumKernel);

    return result;
}

Image filterImage(const Image& image, int kernelSize, float sigma)
{
    std::vector<std::vector<float>> kernel = createKernel(kernelSize, sigma);
    Image filteredImage = image;
    filteredImage.pixelData = std::vector<Pixel>(image.pixelData.size());

    for (int y = 0; y < image.height; ++y)
    {
        for (int x = 0; x < image.width; ++x)
        {
            int idx = y * image.width + x;
            
            filteredImage.pixelData[idx] = applyKernel(image, kernel, x, y);
        }
    }

    return filteredImage;
}
std::vector<std::vector<float>> createKernel(int size, float sigma)
{
    std::vector<std::vector<float>> kernel(size, std::vector<float>(size));
    int offset = size / 2;
    float sum = 0.0f;

    for (int y = -offset; y <= offset; ++y)
    {
        for (int x = -offset; x <= offset; ++x)
        {
            float exponent = -(x * x + y * y) / (2 * sigma * sigma);
            float value = std::exp(exponent) / (2 * M_PI * sigma * sigma);
            kernel[y + offset][x + offset] = value;
            sum += value;
        }
    }

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            kernel[y][x] /= sum;
        }
    }
    return kernel;
}
