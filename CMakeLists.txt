# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project ("EffectiveCPP")

# Include sub-projects.
add_subdirectory ("DeducingTypes")
add_subdirectory ("Auto")
find_package(Boost) 
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
endif()

