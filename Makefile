PROJECT = image
LIBPROJECT = lib$(PROJECT).a
CXX = g++
A = ar
AFLAGS = rsv
CXXFLAGS = -Iinclude -std=c++17 -Wall -g -fPIC -Werror -Wpedantic -fopenmp
LDXXFLAGS = $(CXXFLAGS) -L. -l:$(LIBPROJECT) -fopenmp
DEPS = $(wildcard include/*.hpp)
OBJ = src/main.o src/Image.o src/readBMP.o src/pixelReadf.o src/writeBMP.o src/rotate.o src/gausse.o 
.PHONY: default clean cleanall
default: $(PROJECT)
src/%.o: src/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^
$(PROJECT): src/main.o $(LIBPROJECT)
	$(CXX) -o $@ src/main.o $(LDXXFLAGS); \
	rm -f $(OBJ) src/main.o $(LIBPROJECT)
all : $(PROJECT)

clean:
	rm -f src/*.o
cleanall: clean
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)
	rm -f rotated*.bmp gausse*.bmp
	rm -rf results
