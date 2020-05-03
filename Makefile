# Build testsort.cpp testing unit

CXX = g++
CXXFLAGS = -g
LDFLAGS=

HEADER=sorter.hpp
SOURCE=testsort.cpp
TARGET=testsort

.PHONY : all clean

all : $(SOURCE) $(HEADER) 
		$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SOURCE) -o $(TARGET)

clean :
	rm -f *.~ $(TARGET)