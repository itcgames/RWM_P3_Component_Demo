#pragma once
#include<memory>
#include "SDL.h"
#include "EventListener.h"


class RectangleSelectionComponent
{
	bool m_isDragging; //true if dragging the mouse (i.e. in middle of selecting a rectangle region
	SDL_Point m_startPoint;
	SDL_Point m_endPoint;

public:

	void update(unsigned int);
	SDL_Rect getRectanglefromPoints();
	void render(SDL_Renderer * renderer);


	RectangleSelectionComponent();
	~RectangleSelectionComponent();
};

