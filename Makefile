SHELL := /bin/bash

ifndef CXX
CXX := g++
endif


CPP_INCLUDE := -I../ChaiScript/include/ -I.
CPP_LINK    := -ldl -pthread

CPP_SOURCES := $(shell ls *.cpp)
CPP_OBJECTS := $(CPP_SOURCES:.cpp=.o)
CPP_BIN     := native

all: $(CPP_SOURCES) $(CPP_OBJECTS) $(CPP_BIN)

%.o: %.cpp
	$(CXX) -c -std=c++14 $(CPP_INCLUDE) $^ -o $@

native: $(CPP_OBJECTS)
	$(CXX) -std=c++14 $(CPP_LINK) $^ -o $@

clean:
	rm -rf $(CPP_OBJECTS)
	rm -rf `find . -name "*.o"`
	rm -rf `find . -name "*.so"`

.PHONY: all clean
