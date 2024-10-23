cmake_minimum_required(VERSION 3.27)

project(EarthDefender
    LANGUAGES C CXX
)

if (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "/Od /Zi /Wall /WX /EHsc")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /Wall /WX /EHsc")
else()
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall -Wextra -Wpedantic -Wconversion -Werror -fno-omit-frame-pointer")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -Wextra -Wpedantic -Wconversion -Werror -march=native -flto")
endif()

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

    ${CMAKE_CURRENT_SOURCE_DIR}/include/GameConfig.hpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/Application.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/include/ui/Text.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/Text.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/ui/MenuHUD.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/MenuHUD.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/ui/EndGameHUD.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/EndGameHUD.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/ui/GamePlayHUD.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/GamePlayHUD.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/ui/MainMenuHUD.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/MainMenuHUD.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/AssetManager.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/AssetManager.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/Timer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Timer.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/include/Game.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Game.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-graphics)

set(RESOURCE_FOLDER_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_FOLDER_NAME}")

add_custom_command(
	TARGET ${CMAKE_PROJECT_NAME}
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_directory
	${RESOURCE_SRC_DIR}
	$<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/${RESOURCE_FOLDER_NAME}
)

configure_file(
	"config.hpp.in"
	"${CMAKE_CURRENT_SOURCE_DIR}/include/ConfigAssetPath.hpp" ESCAPE_QUOTES
)