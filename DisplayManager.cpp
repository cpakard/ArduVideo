/*
 * DisplayManager.cpp
 *
 *  Created on: Jun 13, 2015
 *      Author: Colin
 */

#include "DisplayManager.h"

DisplayManager::DisplayManager()
{
	// TODO Auto-generated constructor stub
	currentFrame = 0;
	frameDone = false;
}

DisplayManager::~DisplayManager()
{
	// TODO Auto-generated destructor stub
}


void DisplayManager::updateCurrentFrame(Frame *nextFrame)
{
	currentFrame = nextFrame;
}

void DisplayManager::displayFrame()
{

}