/*
 * FrameManager.cpp
 *
 *  Created on: Jun 13, 2015
 *      Author: Colin
 */

#include "FrameManager.h"
#include "Frame.h"

FrameManagerClass::FrameManagerClass()
{
	// TODO Auto-generated constructor stub
}

FrameManagerClass::~FrameManagerClass()
{
	// TODO Auto-generated destructor stub
}

Frame FrameManagerClass::giveNextFrame()
{
	return frameQueue.pop();
}

void FrameManagerClass::pushFrameToQueue()
{
	frameQueue.push(newFrame);
}

void FrameManagerClass::addByteToFrame(char frameByte)
{
	newFrame.addToFrame(frameByte);
}

void FrameManagerClass::restartFrameRecv()
{
	newFrame.restartFrame();
}

bool FrameManagerClass::nextFrameReady()
{
	if(getQueueSize() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int FrameManagerClass::getQueueSize()
{
	return frameQueue.count();
}