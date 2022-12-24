cmake_minimum_required(VERSION 3.0)

project(PIG3)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Book)
add_subdirectory(Date)
add_subdirectory(Month)
add_subdirectory(Isbn)

target_include_directories(Book PUBLIC Date Month Isbn)

target_include_directories(Date PUBLIC Month)

target_include_directories(${PROJECT_NAME} PUBLIC Book Date Month Isbn)

target_link_libraries(${PROJECT_NAME} Book Date Month Isbn)



