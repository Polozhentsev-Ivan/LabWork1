PROJECT = image
LIBPROJECT = lib$(PROJECT).a
CXX = g++
A = ar
AFLAGS = rsv
CXXFLAGS = -I. -std=c++17 -Wall -g -fPIC -Werror -Wpedantic
LDXXFLAGS = $(CXXGLAGS) -L. -l:$(LIBPROJECT)
DEPS = $(wildcard *.hpp)
OBJ = main.o Image.o readBMP.o  pixelReadf.o writeBMP.o rotate.o gausse.o 
.PHONY: default clean cleanall
default: $(PROJECT)
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXGLAGS)
$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^
$(PROJECT): main.o $(LIBPROJECT)
	$(CXX) -o $@ main.o $(LDXXFLAGS); \
	rm -f $(OBJ) main.o $(LIBPROJECT)
all : $(PROJECT)

clean:
	rm -f *.o
cleanall: clean
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)
