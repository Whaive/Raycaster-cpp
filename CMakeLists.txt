cmake_minimum_required(VERSION 3.14..3.23)

project(raycaster LANGUAGES CXX)

#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKKE_CXX_STANDARD 17)

#find_package(SDL2 REQUIRED)
#include_directories(${SDL2_INCLUDE_DIR})

# rayc is the name of the executable and also the name of the CMAKE TARGET!
add_executable(rayc main.cpp)

include(FetchContent)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        bf71a834948186f4097caa076cd2663c69a10e1e
)

FetchContent_MakeAvailable(glm)

add_library(raylib 
        src/common.cpp
        src/world.cpp
        src/player.cpp)
        
target_include_directories(raylib PUBLIC include)
target_link_libraries(raylib ${SDL2_LIBRARY} glm)

target_link_libraries(rayc ${SDL2_LIBRARY} glm raylib)