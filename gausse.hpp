/* Polozhentsev Ivan iv.poloz.wdesd@mail.ru
first LabWork project
*/
#ifndef GAUSSE_HPP
#define GAUSSE_HPP
#include "Image.hpp"
#include <cmath>
Image filterImage(const Image& image, int kernelSize, float sigma);
std::vector<std::vector<float>> createKernel(int size, float sigma);

#endif
