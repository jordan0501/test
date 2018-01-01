#pragma comment(lib,"winmm.lib")
#include <windows.h>
#include <mmsystem.h>
#define FREQ_CNT 7 
#define QUARTER_SPEED 200  
	void Train(void);

	int main()

	{
		Train();

		return 0;
	}
	void Train(void)
	{

		const DWORD Freq[FREQ_CNT + 1] = { 0, 524, 588, 660, 698, 784, 880, 1976 };

		const DWORD Train_Freq[] =
		{
			5, 5, 3, 1, 5, 5, 3, 1, 2, 3, 4, 4, 3, 4, 5, 5, 5, 3, 5, 3, 2, 3, 1, 4, 2, 2, 2, 3, 1, 1, 1, 4, 2, 2, 2, 3, 1, 1, 1, 2, 4, 3, 2, 1, 2, 1
		};

		const DWORD Train_Tempo[] =
		{
			3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
			2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
			2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2

		};

		int i;

		for (i = 0; i != sizeof(Train_Freq) / sizeof(Train_Freq[0]); ++i)
		{
			if (Train_Tempo[i] == Freq[0]) Sleep(Train_Tempo[i] * QUARTER_SPEED);
			else Beep(Freq[Train_Freq[i]], Train_Tempo[i] * QUARTER_SPEED);
		}
	}