CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = src/Library.cpp src/main.cpp
OUT = library_app

all:
    $(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
    rm -f $(OUT)
