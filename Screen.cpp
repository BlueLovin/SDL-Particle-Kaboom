#include "Screen.h"

Screen::Screen() : m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
{
	
}

bool Screen::init()
{
	m_window = SDL_CreateWindow("Particle Kaboom", SDL_WINDOWPOS_CENTERED,//CREATE WINDOW
		SDL_WINDOWPOS_CENTERED, SCREENSIZE, SCREENSIZE, SDL_WINDOW_ALLOW_HIGHDPI);


	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);//RENDERER
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,//TEXTURE
		SDL_TEXTUREACCESS_STATIC, SCREENSIZE, SCREENSIZE);

	m_buffer = new Uint32[SCREENSIZE * SCREENSIZE];//BUFFER OF MEMORY

	memset(m_buffer, 0, SCREENSIZE * SCREENSIZE * sizeof(Uint32));//SET MEMORY OF PIXELS


	//for (int i = 0; i < (SCREENSIZE * SCREENSIZE); i++)//ALSO SETTING MEMORY
	//	m_buffer[i] = 0xFFFFF00;

	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREENSIZE * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
	return true;
}

bool Screen::userQuit()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) 
		if (event.type == SDL_QUIT)
			return false;

	return true;
}



void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	if (x < 0 || x >= SCREENSIZE || y < 0 || y >= SCREENSIZE) return;//error checking

	Uint32 color = 0;

	color += red; color <<= 8;//set red value, shift to the right
	color += green; color <<= 8;
	color += blue; color <<= 8;
	color += 0xFF;//add alpha value at beginning

	m_buffer[(y * SCREENSIZE) + x] = color;
}

void Screen::cleanup()
{
	delete [] m_buffer;
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	//std::cout << "YOU DONE SON! i play with my assHOLE a lot\n";
	SDL_Quit();
}

void Screen::clear()
{
	memset(m_buffer,0,(SCREENSIZE*SCREENSIZE * sizeof(Uint32)));
}

void Screen::update()
{
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREENSIZE * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}
