#include "SDL.h"
#include "../include/State.h"
#include "../include/Sprite.h"
#include "../include/Music.h"

State::State(){

	quitRequested = false;
	LoadAssets();
	music.Play(-1);

}

State::~State(){

}

void State::LoadAssets(){

    bg.Open("../Recursos/img/Background.png");
	music.Open("../Recursos/audio/BGM.wav");

}

void State::Update(float dt){

	// verifica se a janela foi fechada 
	if(SDL_QuitRequested()) quitRequested = true;

}

void State::Render(){

    bg.Render(0, 0);

}

bool State::QuitRequested(){

	return quitRequested;

}
