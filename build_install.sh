cd build
rm -r *
cmake ..
make -j8 -l8
make install
rm -r *
