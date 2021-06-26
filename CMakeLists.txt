cmake_minimum_required(VERSION 3.1)
project(triangulum VERSION 0.1.0 LANGUAGES CXX)


add_library(${PROJECT_NAME} STATIC
        src/Application.cpp
        src/Utils/FpsCounter.cpp
        src/Utils/FpsCounter.h
        src/EventHandler/EventHandler.cpp
        src/EventHandler/EventHandler.h
        src/EventHandler/EventCallback.h
        src/EventHandler/BasicEventCallback.h)


#Set C++17
#set(CMAKE_CXX_STANDARD 20)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/modules)

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES INTERFACE_INCLUDE_DIRECTORIES /sfml-triangulum/include/)

#Set flags
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4)
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall -Wextra -pedantic)  #Warning flags
endif ()

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )


find_package(SFML 2.5 COMPONENTS graphics window system CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)
