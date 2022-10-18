cmake_minimum_required(VERSION 3.14...3.22)

# This is set so CMake can find where the packages are being stored
set(CMAKE_TOOLCHAIN_FILE "/mnt/d/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(Example)

find_package(PROJ)

add_executable(example_out main.cpp)

target_link_libraries(example_out PRIVATE PROJ::proj)