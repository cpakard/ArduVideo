/*
 * CommManager.cpp
 *
 *  Created on: Jun 13, 2015
 *      Author: Colin
 */

#include "CommManager.h"

CommManagerClass::CommManagerClass()
{
	// TODO Auto-generated constructor stub
	header = 0xAA;
	footer = 0x77;

	frameReady = false;
	byteReady = false;

	buffer[0] = 0;
	buffer[1] = 0;
	buffer[2] = 0;

	CommState = NoFrame;
	nextSendByte = 0;

	bufferIdx = 0;
	recvFrameIdx = 0;
}

CommManagerClass::~CommManagerClass()
{
	// TODO Auto-generated destructor stub
}

bool CommManagerClass::bufferByte(char byte)
{
	//TODO: handle bad frame
	bool retVal = false;
	if(byteReady)
	{
		nextSendByte = buffer[bufferIdx];
		buffer[bufferIdx] = byte;

		switch(CommState)
		{
			case NoFrame:
				if((buffer[0] == header) && (buffer[1] == header) && (buffer[2] == header))
				{
					CommState = FrameBegin;
					bufferIdx = -1;
				}
				break;

			case FrameBegin:
				if(bufferIdx == 2)
				{
					CommState = FrameInbound;
				}
				break;

			case FrameInbound:
				if((buffer[0] == footer) && (buffer[1] == footer) && (buffer[2] == footer))
				{
					CommState = FrameEnd;	
				}
				retVal = true;
				break;

			case FrameEnd:
				buffer[0] = 0;
				buffer[1] = 0;
				buffer[2] = 0;
				bufferIdx = 0;
				break;
		}
		byteReady = false;
	}

	if(++bufferIdx > 2)
	{
		bufferIdx = 0;
	}

	return retVal;
}

char *CommManagerClass::getBuffer()
{
	return buffer;
}

char CommManagerClass::getFrameByte()
{
	return nextSendByte;
}

void CommManagerClass::setByteReady(bool byteStatus)
{
	byteReady = byteStatus;
}

//ISR(USART_RX_vect, ISR_NOBLOCK)
//{
//
//};
