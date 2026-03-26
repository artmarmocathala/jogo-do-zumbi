#include "SDL.h"

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
        //Music music;
        //Sprite bg;
};