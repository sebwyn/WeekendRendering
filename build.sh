#!/bin/bash

cd build
cmake ..
cmake --build .

cd ..
cmake --install build
