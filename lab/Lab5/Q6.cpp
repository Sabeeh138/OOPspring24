/*
Name: Muhammad Sabeeh
id:23k-0002
*/

#include <iostream>
#include <string>

using namespace std;

// Graphics Rendering Engine
class GraphicsRenderingEngine {
public:
    void render() {
        cout<<"Graphics engine is rendering graphics." << endl;
    }
};

class InputHandler {
public:
    void handleInput() {
        cout << "Input handler is processing user input." << endl;
    }
};

class PhysicsEngine {
public:
    void simulatePhysics() {
        cout << "Physics engine is simulating physics." << endl;
    }
};

class GameEngine {
//association being used
private:
    GraphicsRenderingEngine graphicsEngine;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;

public:
    void start() {
        cout << "the Graphics engine is starting." << endl;
        graphicsEngine.render();
        inputHandler.handleInput();
        physicsEngine.simulatePhysics();
        cout << "Game engine has started" << endl;
    }
};

int main() {
    GameEngine gameEngine;
    gameEngine.start();
    return 0;
}
