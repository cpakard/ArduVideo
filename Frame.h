/*
 * Frame.h
 *
 *  Created on: Jun 14, 2015
 *      Author: Colin
 */

#ifndef FRAME_H_
#define FRAME_H_

class Frame
{
	public:
		Frame();
		Frame(char *serialFrame);
		virtual ~Frame();
		bool addToFrame(char byte);
		void restartFrame();

		char redFrame[8];
		char greenFrame[8];
		char blueFrame[8];

	protected:

	private:
		char frameIdx;
};

#endif /* FRAME_H_ */
