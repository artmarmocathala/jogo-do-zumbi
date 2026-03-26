#include "SDL.h"
#include "SDL_image.h"
#include "../include/Sprite.h"
#include "../include/Game.h"

Sprite::Sprite(){
    
    // ponteiro vazio pra chamar open em outro lugar
    texture = nullptr;

}

Sprite::Sprite(std::string file){

    texture = nullptr;
    Open(file);

}

Sprite::~Sprite(){

    if(texture) SDL_DestroyTexture(texture);

}

void Sprite::Open(std::string file){

    if(texture) SDL_DestroyTexture(texture);
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    
    if(texture == nullptr){

        SDL_Log("Error: Falha ao carregar a imagem %s: %s", file.c_str(), IMG_GetError());
        exit(1);

    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);

}

void Sprite::SetClip(int x, int y, int w, int h){

    // so renderiza parte da textura 
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;

}

void Sprite::Render(int x, int y){

    // posicao onde o recorte da textura eh renderizado
    SDL_Rect dstRect = {x, y, clipRect.w, clipRect.h};
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect);

}

int Sprite::GetWidth(){

    return width;

}

int Sprite::GetHeight(){

    return height;

}

bool Sprite::IsOpen(){

    return texture != nullptr;

}