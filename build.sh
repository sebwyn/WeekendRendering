#!/bin/bash

cd build/run
cmake ../..
cmake --build .

cd ../..
cmake --install build/run
