cmake_minimum_required(VERSION 3.6)
project(i_am_synthetic_c___sfml)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/IResources.h src/LocalResources.cpp src/LocalResources.h src/Locator.cpp src/Locator.h)
add_executable(i_am_synthetic_c___sfml ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(i_am_synthetic_c___sfml ${SFML_LIBRARIES})
endif()
add_definitions("-Wall")
FIND_PACKAGE(Boost COMPONENTS system thread filesystem REQUIRED)
TARGET_LINK_LIBRARIES(i_am_synthetic_c___sfml ${Boost_LIBRARIES})