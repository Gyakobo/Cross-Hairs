cmake_minimum_required(VERSION 3.1)
project(opencv_example)

# Include OpenCV
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_library(
	3dVectors
	vect.h
	vect.cpp
)

add_library(
	3x3Matrices
	matrix.h
	matrix.cpp
)

add_library(
	Quaternions
	quaternion.h
	quaternion.cpp
)

add_library(
	Mesh
	Mesh.h
	Mesh.cpp
)

add_library(
	ExtraterrestrialBodies
	Particle.h
	Particle.cpp
)

add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})

target_link_libraries(main 3dVectors)
target_link_libraries(main 3x3Matrices)
target_link_libraries(main Quaternions)
target_link_libraries(main Mesh)
target_link_libraries(main ExtraterrestrialBodies)
