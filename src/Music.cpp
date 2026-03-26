#include "SDL.h"
#include "SDL_mixer.h"
#include "../include/Music.h"

Music::Music(){

    // ponteiro vazio pra chamar open em outro lugar
    music = nullptr;

}

Music::Music(std::string file){

    music = nullptr;
    Open(file);

}

void Music::Play(int times){

    if(music) Mix_PlayMusic(music, times);

}

void Music::Stop(int msToStop){

    // para a musica gradualmente 
    Mix_FadeOutMusic(msToStop);

}

void Music::Open(std::string file){

    if(music) Mix_FreeMusic(music);
    music = Mix_LoadMUS(file.c_str());
    
    if(music == nullptr){

        SDL_Log("Error: Falha ao carregar a musica %s: %s", file.c_str(), Mix_GetError());
        exit(1);

    }

}

bool Music::IsOpen(){

    return music != nullptr;

}

Music::~Music(){

    if(music){

        Stop();
        Mix_FreeMusic(music);
    
    }

}