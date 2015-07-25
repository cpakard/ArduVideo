#include "gtest/gtest.h"
#include "FrameManager.h"
#include "Frame.h"

TEST(FrameManager, addByteToFrame)
{
	FrameManagerClass FM;
	EXPECT_EQ(0, FM.getQueueSize());
	for(char i=0; i<24; i++)
	{
		FM.addByteToFrame(i);
	}
	
	FM.pushFrameToQueue();
	EXPECT_EQ(1, FM.getQueueSize());

	Frame f;
	f = FM.giveNextFrame();
	EXPECT_EQ(0, FM.getQueueSize());
	for(char i=0; i<8; i++)
	{
		EXPECT_EQ(i, f.redFrame[i]);
		EXPECT_EQ(i+8, f.greenFrame[i]);
		EXPECT_EQ(i+16, f.blueFrame[i]);
	}
}