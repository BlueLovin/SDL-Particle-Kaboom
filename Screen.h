#pragma once
#include <SDL.h>
#include <iostream>
#define SCREENSIZE 720//SCREENSIZE
class Screen
{
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
public:
	Screen();
	bool init();
	bool userQuit();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void cleanup();
	void clear();
	void update();
};

