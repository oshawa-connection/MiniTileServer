# Make sure to do "cmake -DCMAKE_C_COMPILER=/usr/bin/gcc" before running this the first time.
# after that, it _should_ be cached.


cmake_minimum_required(VERSION 3.14)



PROJECT (MiniTileServer)
set(CMAKE_VERBOSE_MAKEFILE ON)
# GoogleTest requires at least C++11
SET(CMAKE_CXX_STANDARD 11)



INCLUDE(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
SET(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  all_tests
  tests/all_tests.cc
)

target_link_libraries(
  all_tests
  gtest_main
)


include(GoogleTest)
gtest_discover_tests(all_tests)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

FIND_PACKAGE(CAIRO REQUIRED)

#main
# add_executable(
#   tileserver
#   src/point.c 
#   src/bbox.c 
#   src/cairoTesting.c
# )
# # PRIVATE so only for current target. Will probably have to add this for google tests too.
# target_include_directories(tileserver PRIVATE ${Cairo_INCLUDE_DIRS})
# target_link_libraries(tileserver PRIVATE ${Cairo_LIBS})


add_executable(
  runit
  src/draw_layer_testing.c 
  src/bbox.c 
  headers/bbox.h
  src/source.c
  headers/source.h
  src/layer.c
  headers/layer.h
  src/color.c
  headers/color.h
  headers/geometry.h
  src/point.c
  headers/point.h
  src/logging.c
  headers/logging.h
)

target_include_directories(runit PRIVATE "headers")
target_include_directories(runit PRIVATE ${Cairo_INCLUDE_DIRS})
target_link_libraries(runit PRIVATE ${Cairo_LIBS} m)