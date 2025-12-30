rmdir /s /q build
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/Users/JHCat/Downloads/vcpkg-master/vcpkg-master/scripts/buildsystems/vcpkg.cmake -A x64
cmake --build .