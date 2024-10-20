cmake_minimum_required(VERSION 3.27)

project(EarthDefender
    LANGUAGES C CXX
)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall -Wextra -Wpedantic -Wconversion -Werror -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -Wextra -Wpedantic -Wconversion -Werror -march=native -flto")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
set(SFML_LIB_NAME SFML)

FetchContent_Declare(
    ${SFML_LIB_NAME}
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
)

set(BUILD_SHARED_LIBS OFF)
set(SFML_BUILD_GRAPHICS ON)
set(SFML_BUILD_WINDOW ON) 
set(SFML_BUILD_AUDIO ON)
set(SFML_BUILD_SYSTEM ON)
set(SFML_BUILD_NETWORK OFF)

FetchContent_MakeAvailable(${SFML_LIB_NAME})

add_executable(${PROJECT_NAME} 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-graphics)