cmake_minimum_required(VERSION 2.8.9)
PROJECT(Library)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

add_executable(Library
	src/book.cpp
	src/magazine.cpp
	src/item.cpp
	src/menu.cpp
	src/logging.cpp
	src/login.cpp
	src/worker.cpp
	src/store.cpp
	src/main.cpp
	include/book.h
	include/magazine.h
	include/item.h
	include/menu.h
	include/logging.h
	include/login.h
	include/worker.h
	include/store.h
)


