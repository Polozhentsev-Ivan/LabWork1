#LabWork #1
## Author
Положенцев Иван Денисович, группа 24.Б82-мм
## Contacts
st130976@student.spbu.ru
## Description
LabWork 1. This project involved reading, writing, rotating, and applying a Gaussian filter to a BMP image with a color depth of 24 bits. BMP files with any version of DIB header are supported. Smoothing is not supported.
## Build
make
## Run
./image

## Project Structure
- `src/`: Contains source code files (`main.cpp`, `Image.cpp`, `gausse.cpp`, `rotate.cpp`, etc.).
- `include/`: Contains header files (`BMPheader.hpp`, `Image.hpp`, `gausse.hpp`, `rotate.hpp`, etc.).
- `samples/`: Directory for input BMP images.
- `results/`: Directory for output BMP images (automatically created if it doesn't exist).

## Usage
1. Place your input BMP images into the `samples/` directory.
2. Run the executable:
   ```bash
   ./image
   ```
   The processed images will be saved in the `results/` directory.

## Parallelization
This project utilizes OpenMP for parallel processing of image manipulation tasks. Specifically, the `rotate.cpp` and `gausse.cpp` files use `#pragma omp parallel for collapse(2) schedule(static)` directives to parallelize pixel processing loops for image rotation and Gaussian filtering.

## Performance Measurement
To measure performance with different numbers of threads, you can set the `OMP_NUM_THREADS` environment variable before running the program. For example:

- **1 Thread**:
  ```bash
  OMP_NUM_THREADS=1 ./image
  ```

- **32 Threads**:
  ```bash
  OMP_NUM_THREADS=32 ./image
  ```

