To build an executable for windows

```shell
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=../mingw_toolchain.cmake ..
make
```