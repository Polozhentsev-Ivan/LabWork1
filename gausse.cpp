#include "gausse.hpp"
Image filterImage(const Image& image, int kernelSize, float sigma) {
    std::vector<std::vector<float>> kernel = createKernel(kernelSize, sigma);

    std::vector<Pixel> newPixelData(image.pixelData.size());

    int offset = kernelSize / 2;

    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            float sumR = 0, sumG = 0, sumB = 0;
            float sumKernel = 0;

            for (int ky = -offset; ky <= offset; ++ky) {
                for (int kx = -offset; kx <= offset; ++kx) {
                    int ix = x + kx;
                    int iy = y + ky;

                    if (ix >= 0 && ix < image.width && iy >= 0 && iy < image.height) {
                        int idx = iy * image.width + ix;
                        float kernelValue = kernel[ky + offset][kx + offset];
                        sumR += image.pixelData[idx].red * kernelValue;
                        sumG += image.pixelData[idx].green * kernelValue;
                        sumB += image.pixelData[idx].blue * kernelValue;
                        sumKernel += kernelValue;
                    }
                }
            }

            int idx = y * image.width + x;
            newPixelData[idx].red = static_cast<unsigned char>(sumR / sumKernel);
            newPixelData[idx].green = static_cast<unsigned char>(sumG / sumKernel);
            newPixelData[idx].blue = static_cast<unsigned char>(sumB / sumKernel);
        }
    }
    Image filteredImage = image;
    
    filteredImage.pixelData = newPixelData;
    return filteredImage;
}
std::vector<std::vector<float>> createKernel(int size, float sigma) {
    std::vector<std::vector<float>> kernel(size, std::vector<float>(size));
    int offset = size / 2;
    float sum = 0.0f;

    for (int y = -offset; y <= offset; ++y) {
        for (int x = -offset; x <= offset; ++x) {
            float exponent = -(x * x + y * y) / (2 * sigma * sigma);
            float value = std::exp(exponent) / (2 * M_PI * sigma * sigma);
            kernel[y + offset][x + offset] = value;
            sum += value;
        }
    }

    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            kernel[y][x] /= sum;
        }
    }
    return kernel;
}
