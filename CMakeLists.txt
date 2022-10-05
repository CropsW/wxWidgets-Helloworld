cmake_minimum_required(VERSION 3.19)
project(helloworld)

set(CMAKE_CXX_STANDARD 14)

add_executable(helloworld main.cpp)

set(wxWidgets_ROOT_DIR E:\\sdk\\wxWidgets-3.2.1)
set(wxWidgets_LIB_DIR E:\\Dwonloads\\wxWidgets-3.2.1\\lib\\gcc810_dll)
find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)


include(${wxWidgets_USE_FILE})
target_link_libraries(helloworld ${wxWidgets_LIBRARIES})