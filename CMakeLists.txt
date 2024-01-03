cmake_minimum_required(VERSION 3.10)

project(FDM)

include_directories(start)
include_directories(algebra)

# Here we need to include all of the compiling .cpp files

set(FDM_SOURCES 
        ${PROJECT_SOURCE_DIR}/start/main.cpp
        ${PROJECT_SOURCE_DIR}/algebra/details/UniformMesh.cpp
        ${PROJECT_SOURCE_DIR}/algebra/details/Mesh1d.cpp
        ${PROJECT_SOURCE_DIR}/algebra/details/matrix.cpp
        ${PROJECT_SOURCE_DIR}/equation/details/equation.cpp
        ${PROJECT_SOURCE_DIR}/solver/details/solver.cpp
        ${PROJECT_SOURCE_DIR}/solver/details/sweep_method.cpp
        )

add_executable(FDM ${FDM_SOURCES})