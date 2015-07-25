/*
 * DisplayManager.h
 *
 *  Created on: Jun 13, 2015
 *      Author: Colin
 */

#ifndef DISPLAYMANAGER_H_
#define DISPLAYMANAGER_H_

#include "Frame.h"
#include "FrameManager.h"

// abstract class
class DisplayManager
{
	public:
		DisplayManager();
		virtual ~DisplayManager();

		void displayFrame();
		void updateCurrentFrame(Frame *nextFrame);

	protected:

	private:
		
		Frame *currentFrame;
		bool frameDone;

		FrameManagerClass *FrameManager;
};

#endif /* DISPLAYMANAGER_H_ */
