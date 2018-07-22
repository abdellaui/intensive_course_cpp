#include "target.h"

target::target(float posX, float posY) : m_posX(posX), m_posY(posY)
{}

target::~target()
{}

const float target::getPosX() const
{
	return m_posX;
}

const float target::getPosY() const
{
	return m_posY;
}


