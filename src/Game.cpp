#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "../include/Game.h"
#include "../include/State.h"

int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
int mixFlags = MIX_INIT_OGG | MIX_INIT_MP3 | MIX_INIT_FLAC;

Game* Game::instance = nullptr;
Game& Game::GetInstance(){

    if(!instance) instance = new Game("Arthur - 211043610", 1200, 900);
    return *instance;

}

Game::Game(std::string title, int width, int height){
    
    if(instance == nullptr) instance = this;
    
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
    
        SDL_Log("Error: Falha ao iniciar o SDL: %s", SDL_GetError());
        exit(1);
    
    }
    
    // Inicializa processamento de imagens
    if(IMG_Init(imgFlags) != imgFlags){
    
        SDL_Log("Warning: Um ou mais formatos de imagem nao puderam ser inicializados: %s", IMG_GetError());
    
    }
    
    // Inicializa processamento de audio
    if(Mix_Init(mixFlags) != mixFlags){
    
        SDL_Log("Warning: Um ou mais formatos de audio nao puderam ser inicializados: %s", Mix_GetError());
    
    }
    
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
    
        SDL_Log("Error: Falha ao iniciar o audio: %s", Mix_GetError());
        exit(1);
    
    }
    
    Mix_AllocateChannels(32);

    // Cria janela e renderer
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    state = new State();

}

Game::~Game(){

    delete state;
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

}

State& Game::GetState(){

    return *state;

}

SDL_Renderer* Game::GetRenderer(){

    return renderer;

}

void Game::Run(){

    while(!state->QuitRequested()){

        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer); 
        SDL_Delay(33); //30fps

    }
}
