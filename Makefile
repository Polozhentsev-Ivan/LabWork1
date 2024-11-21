PROJECT = image
LIBPROJECT = lib$(PROJECT).a
CXX = g++
A = ar
AFLAGS = rsv
CXXFLAGS = -I. -std=c++17 -Wall -g -fPIC -Werror -Wpedantic
LDXXFLAGS = $(CXXGLAGS) -L. -l:$(LIBPROJECT)
DEPS = $(wildcard *.hpp)
OBJ = maintest.o Image.o readBMP.o  pixelReadf.o writeBMP.o 
.PHONY: default clean cleanall
default: $(PROJECT)
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXGLAGS)
$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^
$(PROJECT): maintest.o $(LIBPROJECT)
	$(CXX) -o $@ maintest.o $(LDXXFLAGS); \
	rm -f $(OBJ) maintest.o $(LIBPROJECT)
all : $(PROJECT)

clean:
	rm -f *.o
cleanall: clean
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)
