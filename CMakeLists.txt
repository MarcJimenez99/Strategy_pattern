CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11) 

ADD_EXECUTABLE(lab
	main.cpp
)

ADD_EXECUTABLE(test
	unit_test.cpp
	VectorContainer.cpp
	ListContainer.cpp
	bubble.cpp
	SelectionSort.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
