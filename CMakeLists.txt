project(cugwas)
cmake_minimum_required(VERSION 2.6)

add_library(${CMAKE_PROJECT_NAME}
    lib/gwas_leastsquares.c
    lib/gwas_leastsquares.h
)

include_directories("${PROJECT_SOURCE_DIR}/")
include_directories("${PROJECT_SOURCE_DIR}/lib")

add_executable(${CMAKE_PROJECT_NAME}-bin
    src/main.cpp
    dep/pgetopt.h
    dep/pgetopt.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME}-bin ${CMAKE_PROJECT_NAME})
set_target_properties(${CMAKE_PROJECT_NAME}-bin PROPERTIES OUTPUT_NAME ${CMAKE_PROJECT_NAME})
