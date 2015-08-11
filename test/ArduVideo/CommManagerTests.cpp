#include "gtest/gtest.h"

#include "CommManager.h"



TEST(CommManager_bufferByte, checkInputSerialFrame)
{
    CommManagerClass CM;
	for(int i=0; i<3; i++)
	{
		CM.setByteReady(true);
		EXPECT_EQ(false, CM.bufferByte(0xaa));
	}
	CM.setByteReady(true);
	EXPECT_EQ(false, CM.bufferByte(0x55));

	CM.setByteReady(true);
	EXPECT_EQ(false, CM.bufferByte(0x77));
	
	CM.setByteReady(true);
	EXPECT_EQ(false, CM.bufferByte(0x77));

	CM.setByteReady(true);
	EXPECT_EQ(true, CM.bufferByte(0x77));

	char sendByte = CM.getFrameByte();
	EXPECT_EQ(0x55, sendByte);

}

TEST(CommManager_getFrameByte, checkByteRecv)
{
    CommManagerClass CM;

	CM.setByteReady(true);
	CM.bufferByte(0x55);
	CM.setByteReady(true);
	CM.bufferByte(0);
	CM.setByteReady(true);
	CM.bufferByte(0);
	CM.setByteReady(true);
	CM.bufferByte(0);
	EXPECT_EQ(0x55, CM.getFrameByte());
}