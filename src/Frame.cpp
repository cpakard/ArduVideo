/*
 * Frame.cpp
 *
 *  Created on: Jun 14, 2015
 *      Author: Colin
 */

#include "Frame.h"

Frame::Frame()
{
	frameIdx = 0;
}

Frame::Frame(char *serialFrame)
{
	// TODO Auto-generated constructor stub
	for(char i=0; i<8; i++)
	{
		redFrame[i] = serialFrame[i];
		greenFrame[i] = serialFrame[i+8];
		blueFrame[i] = serialFrame[i+16];
	}
	frameIdx = 0;
}

Frame::~Frame()
{
	// TODO Auto-generated destructor stub
}

bool Frame::addToFrame(char byte)
{
	if(frameIdx < 8)
	{
		redFrame[frameIdx] = byte;
	}
	else if(frameIdx < 16)
	{
		greenFrame[frameIdx-8] = byte;
	}
	else
	{
		blueFrame[frameIdx-16] = byte;
	}
	if(++frameIdx >= 24)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Frame::restartFrame()
{
	frameIdx = 0;
}