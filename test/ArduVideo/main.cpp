#include "FrameManager.h"
#include "DisplayManager.h"
#include "CommManager.h"
#include "Frame.h"

#include "gtest/gtest.h"

int main(int argc, char** argv) 
{ 
    testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS(); 
    std::getchar(); // keep console window open until Return keystroke
}

/*int main()
{
	FrameManagerClass FrameManager;
	DisplayManager dm;
	CommManagerClass CommManager;

	char *serialFrame = new char[24];
	serialFrame[0] = 0x55;
	serialFrame[1] = 0x55;
	serialFrame[2] = 0x55;
	serialFrame[3] = 0x55;
	serialFrame[4] = 0x55;
	serialFrame[5] = 0x55;
	serialFrame[6] = 0x55;
	serialFrame[7] = 0x55;
	serialFrame[8] = 0xaa;
	serialFrame[9] = 0xaa;
	serialFrame[10] = 0xaa;
	serialFrame[11] = 0xaa;
	serialFrame[12] = 0xaa;
	serialFrame[13] = 0xaa;
	serialFrame[14] = 0xaa;
	serialFrame[15] = 0xaa;
	serialFrame[16] = 0xff;
	serialFrame[17] = 0xff;
	serialFrame[18] = 0xff;
	serialFrame[19] = 0xff;
	serialFrame[20] = 0xff;
	serialFrame[21] = 0xff;
	serialFrame[22] = 0xff;
	serialFrame[23] = 0xff;

	FrameManager.addFrame(serialFrame);
	FrameManager.addFrame(serialFrame);
	FrameManager.addFrame(serialFrame);
	Frame *f = FrameManager.giveNextFrame();

	return 0;
}*/