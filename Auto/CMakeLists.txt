# CMakeList.txt : CMake project for Arrays, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost) 
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(UnderstandingAuto UnderstandingAuto.h UnderstandingAuto.cpp ../Utilities/functiondefs.h)
    target_link_libraries(UnderstandingAuto ${Boost_LIBRARIES})
endif()