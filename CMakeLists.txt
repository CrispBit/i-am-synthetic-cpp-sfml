cmake_minimum_required(VERSION 3.6)
project(i_am_synthetic_c___sfml)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall)

set(SOURCE_FILES src/main.cpp src/resources/IResources.h src/resources/LocalResources.cpp src/resources/LocalResources.h src/Locator.cpp src/Locator.h src/resources/NullResources.h src/resources/NullResources.cpp src/buttons/Button.cpp src/buttons/Button.h src/buttons/PlayButton.cpp src/buttons/PlayButton.h src/buttons/MainMenuButton.cpp src/buttons/MainMenuButton.h src/buttons/MainMenuTextures.cpp src/buttons/MainMenuTextures.h src/buttons/CreditsButton.cpp src/buttons/CreditsButton.h src/scenes/CreditsScene.cpp src/scenes/CreditsScene.h src/scenes/Scene.cpp src/scenes/Scene.h src/scenes/MainMenuScene.cpp src/scenes/MainMenuScene.h src/game-objects/GameObject.cpp src/game-objects/GameObject.h src/scenes/PlayScene.cpp src/scenes/PlayScene.h src/Data.cpp src/Data.h)
add_executable(i_am_synthetic_c___sfml ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
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
