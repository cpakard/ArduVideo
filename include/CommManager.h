/*
 * CommManager.h
 *
 *  Created on: Jun 13, 2015
 *      Author: Colin
 */

#ifndef COMMMANAGER_H_
#define COMMMANAGER_H_

//#include <Arduino.h>

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
		CommManagerClass();
		virtual ~CommManagerClass();
		virtual char *getBuffer();
		virtual bool bufferByte(char byte);
		virtual char getFrameByte();
		virtual void setByteReady(bool byteStatus);

	protected:

	private:
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
