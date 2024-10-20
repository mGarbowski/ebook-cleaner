# mingw_toolchain.cmake

# Target Windows 64-bit (or modify for 32-bit if needed)
set(CMAKE_SYSTEM_NAME Windows)

# Specify the compiler and tools to use
set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)

# Optional: Set the path for Windows libraries and executables
# set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)

# Prevent CMake from automatically looking for programs and libraries on the host system
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
