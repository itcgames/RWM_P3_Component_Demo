#pragma once
#include"SDL.h"
#include "SDL_ttf.h"
#include<string>

class SDLLabelComponent
{
	std::string m_text;

	TTF_Font* m_font;
	SDL_Color m_colour;
	SDL_Rect m_rect;

public:
	void setText(std::string& s) { m_text = s; }
	void setText(const char * const s) { m_text = s; }

	void render(SDL_Renderer*);

	void onEvent(std::string);

	void setPos(int x, int y);

	SDLLabelComponent();
	~SDLLabelComponent();
};

