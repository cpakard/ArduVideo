
#ifndef TESTFRAME_H_
#define TESTFRAME_H_

class TestFrame
{
	public:
		TestFrame();
		TestFrame(char *serialFrame)
		{
			redFrame = serialFrame[0];
			greenFrame = serialFrame[1];
			blueFrame = serialFrame[2];
		}
		virtual ~TestFrame();
	protected:

	private:
		char redFrame;
		char greenFrame;
		char blueFrame;
}

#endif