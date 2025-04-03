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
        src/SceneNode.cpp
        Include/SpriteNode.hpp
        src/SpriteNode.cpp
        Include/World.hpp
        src/World.cpp
        Include/Game.hpp
        src/Game.cpp
        Include/Utility.hpp
        Include/Utility.inl
        Include/Command.hpp
        src/Command.cpp
        Include/Category.hpp
        Include/CommandQueue.hpp
        src/CommandQueue.cpp
        Include/Player.hpp
        src/Player.cpp
        Include/State.hpp
        src/StateStack.cpp
        Include/StateIdentifiers.hpp
        src/State.cpp
        Include/Application.hpp
        src/Application.cpp
        src/TitleState.cpp
        src/MenuState.cpp
        src/PauseState.cpp
        src/GameState.cpp
        src/Utility.cpp
        Include/Component.hpp
        src/Component.cpp
        Include/Container.hpp
        src/Container.cpp
        Include/Button.hpp
        src/Button.cpp
        Include/SettingsState.hpp
        src/SettingsState.cpp
        Include/Label.hpp
        src/Label.cpp
        Include/DataTables.hpp
        src/DataTables.cpp
        Include/TextNode.hpp
        src/TextNode.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/libs/sfml/lib/cmake/SFML)
find_package(SFML COMPONENTS window graphics audio REQUIRED)

include_directories(C:/libs/sfml/include/SFML)
target_link_libraries(SFML_Game sfml-window sfml-graphics sfml-audio)
