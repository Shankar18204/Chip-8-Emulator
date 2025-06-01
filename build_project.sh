#!/bin/bash

# Delete the build directory if it exists
if [ -d "build" ]; then
  echo "Removing existing build directory..."
  rm -rf build
fi

# Create a new build directory
echo "Creating new build directory..."
mkdir build

# Change into the build directory
cd build

# Run cmake to configure the project
echo "Configuring the project with cmake ..."
cmake ..

# Build the project
echo "Building the project..."
cmake --build .

echo "Build complete."
