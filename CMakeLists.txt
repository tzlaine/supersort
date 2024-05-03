cmake_minimum_required(VERSION 3.25)

project(super_sort)

################################################## 
# C++ standard version selection
################################################## 
set(CXX_STD 14 CACHE STRING "Set to X to enable C++X builds.")
message("-- Using -std=c++${CXX_STD}")

if (MSVC)
  add_compile_options(/Zc:__cplusplus)
endif()

##################################################
# Sanitizers
##################################################
set(USE_ASAN false CACHE BOOL "Set to true to enable -fsanitize=address when building tests.") 
set(USE_UBSAN false CACHE BOOL "Set to true to enable -fsanitize=undefined when building tests.")
if (USE_ASAN AND USE_UBSAN)
    message(FATAL_ERROR "USE_ASAN and USE_UBSAN must not be enabled at the same time")
elseif (USE_ASAN)
    set(compile_flags -fsanitize=address)
    set(link_flags -fsanitize=address)
    message("-- Using -fsanitize=address") 
elseif (USE_UBSAN)
    set(compile_flags -fsanitize=undefined)
    set(link_flags -fsanitize=undefined)
    message("-- Using -fsanitize=undefined")
endif()


##################################################
# Code coverage
##################################################
if (UNIX)
    set(BUILD_COVERAGE false CACHE BOOL "Set to true to enable code coverage when building tests.  Only Linux and Mac are supported.")
    if (BUILD_COVERAGE)
        message("-- Building for code coverage; disabling any sanitizers")
        if (APPLE)
            set(compile_flags -fprofile-arcs -ftest-coverage)
            set(CMAKE_BUILD_TYPE Debug)
            set(link_flags --coverage)
        else ()
            set(compile_flags --coverage)
            set(CMAKE_BUILD_TYPE Debug)
            set(link_flags --coverage)
        endif ()
    endif ()
endif ()

##################################################
# library
##################################################
add_library(super_sort INTERFACE)

target_include_directories(super_sort INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)
install(TARGETS super_sort DESTINATION lib)

if (link_flags)
    target_link_libraries(super_sort INTERFACE ${link_flags})
    target_compile_options(super_sort INTERFACE ${compile_flags})
endif ()
if (NOT MSVC)
    target_compile_options(super_sort INTERFACE -Wall)
endif ()


add_subdirectory(test)
