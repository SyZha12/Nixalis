cmake_minimum_required(VERSION 3.30)

#[Nixalis Engine - 2D (3D) project engine for all purposes; first focus is games]
project(Nixalis VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#[Set directories and search for CMakeLists.txt files to execute]
set(DIRECTORIES
    Sandbox
)
foreach(DIR ${DIRECTORIES})
    add_subdirectory(${DIR})
endforeach()
