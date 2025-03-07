cmake_minimum_required(VERSION 3.24)
project(SFML_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML_Game
        Include/ResourceHolder.hpp
        Include/ResourceHolder.inl
        src/Main.cpp
        src/Entity.cpp
        Include/ResourceIdentifiers.hpp
        Include/Aircraft.hpp
        src/Aircraft.cpp
        Include/SceneNode.hpp
        src/SceneNode.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/libs/sfml/lib/cmake/SFML)
find_package(SFML COMPONENTS window graphics audio REQUIRED)

include_directories(C:/libs/sfml/include/SFML)
target_link_libraries(SFML_Game sfml-window sfml-graphics sfml-audio)
