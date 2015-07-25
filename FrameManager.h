/*
 * FrameManager.h
 *
 *  Created on: Jun 13, 2015
 *      Author: Colin
 */

#ifndef FRAMEMANAGER_H_
#define FRAMEMANAGER_H_

#include "QueueList.h"
#include "Frame.h"
#include "CommManager.h"

class FrameManagerClass
{
	public:
		FrameManagerClass();
		FrmeManagerClass(CommManagerClass *CM);
		virtual ~FrameManagerClass();

		virtual void pushFrameToQueue();
		virtual void addByteToFrame(char frameByte);
		virtual void restartFrameRecv();
		virtual Frame giveNextFrame();
		virtual bool nextFrameReady();
		virtual int getQueueSize();
		virtual void displayFrame();
		virtual void updateCurrentFrame();

	protected:

	private:
		QueueList<Frame> frameQueue;
		char maxQueueSize;
		Frame newFrame;
		Frame *currentFrame;

		CommManagerClass *CommManager;

		virtual void 
};

#endif /* FRAMEMANAGER_H_ */
