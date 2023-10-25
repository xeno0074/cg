#!/bin/bash

script_path="$(dirname -- "${BASH_SOURCE[0]}")"

cmake -S $script_path -B $script_path/build -G Ninja

cd $script_path/build
ninja

cd Test
./Comp
