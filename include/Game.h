#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include <string>

class State;

class Game {
    
    public:

        ~Game();
        static Game& GetInstance();
        void Run();
        State& GetState();
        SDL_Renderer* GetRenderer();

    private:

        Game(std::string title, int width, int height);
        static Game* instance;
        State* state;
        SDL_Window* window;
        SDL_Renderer* renderer;    

}; 

    #endif