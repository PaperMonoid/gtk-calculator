cmake_minimum_required(VERSION 2.6)
project(gtk-calculator)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

file(COPY views DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(gtk-calculator src/main.c)
target_link_libraries(gtk-calculator ${GTK3_LIBRARIES})
