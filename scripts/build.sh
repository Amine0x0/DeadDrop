#!/bin/bash

set -e

if [ -d "build" ]; then
    echo "Cleaning old build artifacts..."
    rm -rf build
fi

mkdir build
cd build

echo "Configuring with CMake"
cmake ..

echo "Compiling..."
make

echo "Build Successful!"
clear
./deaddrop_core