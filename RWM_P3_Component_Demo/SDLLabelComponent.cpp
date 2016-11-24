#include "SDLLabelComponent.h"

#include <iostream>


void SDLLabelComponent::render(SDL_Renderer * renderer)
{
	//get size of text in current font
	int w, h;
	TTF_SizeText(m_font, m_text.c_str(), &w, &h);

	m_rect.h = h;
	m_rect.w = w;


	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(m_font, m_text.c_str(), m_colour); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); //now you can convert it into a texture

	
	SDL_RenderCopy(renderer, Message, NULL, &m_rect); 

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
}

void SDLLabelComponent::onEvent(std::string)
{
}

void SDLLabelComponent::setPos(int x, int y)
{
	m_rect.x = x;
	m_rect.y = y;
}

SDLLabelComponent::SDLLabelComponent()
{
	//Initialize SDL_ttf
	if (!TTF_WasInit() && TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError();

	}

	m_font = TTF_OpenFont("trebuc.ttf", 72); //this opens a font style and sets a size
	if (m_font == NULL)
	{
		std::cout << "Failed to load trebuc.ttf font! SDL_ttf Error: "<< TTF_GetError();
	}

	m_colour = { 255, 255, 255 };
	
	m_text = "SDL_label Text";

	m_rect.x = 0;
	m_rect.y = 0;

}


SDLLabelComponent::~SDLLabelComponent()
{
}
