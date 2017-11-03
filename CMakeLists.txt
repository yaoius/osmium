cmake_minimum_required(VERSION 3.7)
project(osmium VERSION 0.1 LANGUAGES CXX)

# Required Libraries
set(CMAKE_PREFIX_PATH "/Users/dillon/projects/shared/originals/SFML-2.4.2-osx-clang/lib " ${CMAKE_PREFIX_PATH})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules; ${CMAKE_MODULE_PATH}")
find_package(SFML 2 REQUIRED network audio graphics window system)

# Define Osmium
add_library(osmium
        src/core/viewport/viewport.cpp include/osmium/core/viewport.h)

target_include_directories(osmium PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE src)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(osmium ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

include(GNUInstallDirs)
# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS osmium EXPORT osmiumConfig
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT osmiumConfig DESTINATION share/osmium/cmake)

#add_executable(testlib
#        test/testlib.cpp)
#
#target_link_libraries(testlib
#        lib)
#
#add_test(testlib testlib)