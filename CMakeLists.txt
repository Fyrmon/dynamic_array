cmake_minimum_required(VERSION 3.20)
project(dyn_arr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)
add_subdirectory(tests)

add_executable(dyn_arr_app ${CMAKE_CURRENT_SOURCE_DIR}/app/main.cpp)

target_link_libraries(dyn_arr_app
   PRIVATE
   dyn_arr_lib
)
