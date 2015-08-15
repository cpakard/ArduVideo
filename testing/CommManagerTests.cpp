#include "gtest/gtest.h"

#include "CommManager.h"


// Test that when a byte is ready, it is stored in the byte buffer

// Test that when a message is recieved, it is routed properly

// Test that if a message times out it is handled properly

// Test that the comm manager correctly handles the message size

//  Test



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