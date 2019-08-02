#include"GameSystem.h"

void CharTextureMove(Count* count, VariableNumber* var,int MapChipList[22][19])
{
	if (count->Frame < 20)
	{
		switch (var->Keystate)
		{
		case 0:
			count->Frame = 0;

			break;
		case 1:

			MapChipList[16][9] = 38;

			if (10 < count->Frame && count->Frame < 20)
			{
				MapChipList[16][9] = 36;
			}
			break;

		case 2:

			MapChipList[16][9] = 39;

			if (10 < count->Frame && count->Frame < 20)
			{
				MapChipList[16][9] = 36;
			}
			break;
		case 3:

			MapChipList[16][9] = 40;

			if (10 < count->Frame && count->Frame < 20)
			{
				MapChipList[16][9] = 36;
			}
			break;
		case 4:

			MapChipList[16][9] = 37;

			if (10 < count->Frame && count->Frame < 20)
			{
				MapChipList[16][9] = 36;
			}
			break;
		}
	}

}