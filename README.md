# SFML Game Development Project

## Overview
This project is an implementation of a game based on concepts and techniques covered in the book *SFML Game Development*. The project showcases my ability to build a 2D game using the Simple and Fast Multimedia Library (SFML) and has deepened my understanding of C++, applying game development best practices and design patterns.

## Features
- **Game Engine Architecture**: Implemented a structured game loop with clear separation of concerns.
- **State Management**: Created a flexible state-based system to manage different screens (menu, gameplay, pause, etc.).
- **Entity-Component System (ECS)**: Designed an entity management system to enhance game scalability.
- **Resource Management**: Optimized loading and handling of textures, fonts, and sounds.
- **Event Handling**: Implemented user input handling for keyboard and mouse interactions.
- **Physics and Collision Detection**: Developed movement and collision logic for smooth gameplay.
- **Rendering System**: Utilized SFML’s rendering capabilities for sprite-based graphics.
- **Game AI and Behavior**: Integrated basic AI for NPC movement and behavior.

## Technologies Used
- **Programming Language**: C++
- **Game Framework**: SFML (Simple and Fast Multimedia Library)
- **Development Tools**: CLion

## What I Learned
By implementing this project, I gained hands-on experience with:
- **Game Development Fundamentals**: Understanding core concepts such as the game loop, rendering pipeline, and input handling.
- **Design Patterns**: Applying patterns such as Singleton, State, and Command to structure the code effectively.
- **Performance Optimization**: Managing resources efficiently and ensuring smooth frame rates.
- **Software Engineering Principles**: Writing maintainable and scalable code using modular programming techniques.
- **Advanced C++ Mastery**: Strengthened my proficiency in C++ through practical implementation, mastering memory management, object-oriented design, and modern C++ features.

## How to Run the Project
1. Install SFML on your system.
2. Clone this repository:
   ```sh
   git clone github.com/mykola-derevianko/wing-commander.git
   ```
3. Navigate to the project directory and build using CMake:
   ```sh
   cmake .
   make
   ```
4. Run the executable:
   ```sh
   ./Main
   ```

## Future Improvements
- Implement multiplayer functionality to enable online and local cooperative gameplay.
- Add networking features to synchronize game states between players.
- Enhance graphics and animations.

## Acknowledgments
- Inspired by *SFML Game Development* by Jan Haller, Henrik Vogelius Hansson, and Artur Moreira. [Available on Amazon](https://www.amazon.com/SFML-Game-Development-Jan-Haller/dp/1849696845).
