/*
 * CommManager.h
 *
 *  Created on: Jun 13, 2015
 *      Author: Colin
 */

#ifndef COMMMANAGER_H_
#define COMMMANAGER_H_

//#include <Arduino.h>
#include "FrameManager.h"

enum CommStates
{
	NoFrame,
	FrameBegin,
	FrameInbound,
	FrameEnd
};

class CommManagerClass
{
	public:
		CommManagerClass(FrameManagerClass *fm);
		virtual ~CommManagerClass();

		virtual void commTask();

		virtual char *getBuffer();
		virtual bool bufferByte(char byte);
		virtual char getFrameByte();
		virtual void setByteReady(bool byteStatus);

	protected:

	private:
		FrameManagerClass *frameManager;

		CommStates CommState;
		char buffer[3];
		char bufferIdx;
		char recvFrameIdx;
		bool frameReady;
		char header;
		char footer;
		char nextSendByte;
		bool byteReady;
};


#endif /* COMMMANAGER_H_ */
