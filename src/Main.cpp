#include "../Include/Game.hpp"
#include "../Include/Application.hpp"
#include <iostream>
int main(){
    try{
        Application app;
        app.run();
    }
    catch (std::exception& e){
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
}