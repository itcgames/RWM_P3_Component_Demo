#include "RectangleSelectionComponent.h"
#include "Event.h"




void RectangleSelectionComponent::update(unsigned int deltaTime)
{
	int x, y;
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT)) { //is left button being pressed
		if (!m_isDragging) { // are we not in middle of dragging action? We should start one
			m_isDragging = true;
			m_startPoint.x = x;
			m_startPoint.y = y;

		}
		m_endPoint.x = x; //current mouse pos is end point of dragging
		m_endPoint.y = y;

	}
	else{// mouse button not being pressed
		if (m_isDragging)
		{ // we were in middle of dragging action, but mouse has been released, so end dragging
			m_isDragging = false;
			//send a message to make a new box
			Event e(Events::newbox);
			e.setData<SDL_Rect>(getRectanglefromPoints());

			EventHandler::getInstance().dispatch(e);
		}
	}
}

SDL_Rect RectangleSelectionComponent::getRectanglefromPoints() {
	SDL_Rect rect;
	rect.x = m_startPoint.x;
	rect.y = m_startPoint.y;
	rect.w = m_endPoint.x - m_startPoint.x;
	rect.h = m_endPoint.y - m_startPoint.y;

	return rect;

}

void RectangleSelectionComponent::render(SDL_Renderer* renderer)
{
	//only draw if we are in middle of dragging action
	if (m_isDragging) {
		SDL_Rect rect=getRectanglefromPoints();
		SDL_RenderDrawRect(renderer, &rect);
	}
}

RectangleSelectionComponent::RectangleSelectionComponent():m_isDragging(false)
{
}


RectangleSelectionComponent::~RectangleSelectionComponent()
{
}
