#include"GameSystem.h"
#include"GameScene.h"

void CharTextureMove(Count* count, VariableNumber* var,int MapChipList[22][19], PLAYER* Pac_man)
{
	if (count->Frame < 20)
	{
		switch (var->Keystate)
		{
		case 0:
			count->Frame = 0;

			break;
		case 1:

			Pac_man->pos_Tu = (float)0.03125 + Pac_man->TuTvSize * 2;

			if (10 < count->Frame && count->Frame < 20)
			{
				Pac_man->pos_Tu = 0.03125;
			}
			break;

		case 2:

			Pac_man->pos_Tu = (float)0.03125 + Pac_man->TuTvSize * 3;

			if (10 < count->Frame && count->Frame < 20)
			{
				Pac_man->pos_Tu = 0.03125;
			}
			break;
		case 3:

			Pac_man->pos_Tu = (float)0.03125 + Pac_man->TuTvSize * 4;

			if (10 < count->Frame && count->Frame < 20)
			{
				Pac_man->pos_Tu = 0.03125;
			}
			break;
		case 4:

			Pac_man->pos_Tu = (float)0.03125 + Pac_man->TuTvSize * 1;

			if (10 < count->Frame && count->Frame < 20)
			{
				Pac_man->pos_Tu = 0.03125;
			}
			break;
		}
	}

}

void Pac_Mon_Move(VariableNumber* var, PLAYER* Pac_man)
{
	switch (var->Keystate)
	{
	case 0:
		break;
	case 1:
		Pac_man->pos_Y = Pac_man->pos_Y - var->MoveSpeed;
		break;
	case 2:
		Pac_man->pos_Y = Pac_man->pos_Y + var->MoveSpeed;
		break;
	case 3:
		Pac_man->pos_X = Pac_man->pos_X + var->MoveSpeed;
		break;
	case 4:
		Pac_man->pos_X = Pac_man->pos_X - var->MoveSpeed;
		break;
	}
}