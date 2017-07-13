cmake_minimum_required(VERSION 3.6)
project(i_am_synthetic_c___sfml)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-Wall)

file(GLOB_RECURSE SOURCE_FILES synthy_src
        "src/*.h"
        "src/*.cpp"
        "src/*/*.h"
        "src/*/*.cpp"
)

add_executable(i_am_synthetic_c___sfml ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Detect and add SFML
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(i_am_synthetic_c___sfml ${SFML_LIBRARIES})
endif()
set(YAMLCPP_STATIC_LIBRARY TRUE)

find_package(YamlCpp)
if(YAMLCPP_FOUND)
    include_directories(${YAMLCPP_INCLUDE_DIR})
    target_link_libraries(i_am_synthetic_c___sfml ${YAMLCPP_LIBRARY})
endif()
find_package(Boost COMPONENTS system thread filesystem REQUIRED)
target_link_libraries(i_am_synthetic_c___sfml ${Boost_LIBRARIES})

find_package(OpenGL)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
    target_link_libraries(ogl_practice ${OPENGL_LIBRARIES})
endif()

find_package(GLEW)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    target_link_libraries(ogl_practice ${GLEW_LIBRARIES})
endif()

find_package(ASSIMP)
if (ASSIMP_FOUND)
    include_directories(${ASSIMP_INCLUDE_DIRS})
    target_link_libraries(ogl_practice ${ASSIMP_LIBRARIES})
endif()