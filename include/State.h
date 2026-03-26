#ifndef STATE_H
#define STATE_H

#include "SDL.h"
#include "./Sprite.h"
#include "./Music.h"

class State{

    public:

        State();
        ~State();

        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();

    private:

        bool quitRequested;
        Music music;
        Sprite bg;
        
};

    #endif