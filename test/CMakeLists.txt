include_directories(${CMAKE_HOME_DIRECTORY})

include(CTest)

enable_testing()

add_custom_target(super_sort_check COMMAND ${CMAKE_CTEST_COMMAND} -j4 -C ${CMAKE_CFG_INTDIR})
if (NOT TARGET check)
    add_custom_target(check DEPENDS super_sort_check)
else()
    add_dependencies(check super_sort_check)
endif()

set(warnings_flag)
if (NOT MSVC)
    set(warnings_flag -Wall)
endif ()

macro(add_test_executable name)
    add_executable(${name} ${name}.cpp)
    target_compile_options(${name} PRIVATE ${warnings_flag})
    target_link_libraries(${name} super_sort)
    set_property(TARGET ${name} PROPERTY CXX_STANDARD ${CXX_STD})
    add_test(${name} ${CMAKE_CURRENT_BINARY_DIR}/${name})
    if (clang_on_linux)
        target_link_libraries(${name} c++)
    endif ()
endmacro()

add_test_executable(test_super_sort)
