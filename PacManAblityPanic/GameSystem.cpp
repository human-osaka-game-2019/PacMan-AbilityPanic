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

/*NowStateId CollisionDetectionMapChip(float now_x, float now_y, float x, float y, int MapChipList[22][19])
{

	if ((int)(now_x - 598) % WIDTH_POS == 0 && (int)(now_y - 120) % HEIGHT_POS == 0)
	{
		int x = (now_x - 598) / WIDTH_POS;
		int y = (now_y - 120) / HEIGHT_POS;

		if (now_x < x&&now_y==y)
		{
			if (MapChipList[y][x + 1] != 0 && MapChipList[y][x + 1] != 12)
			{
				return Appulse;
			}
			else return Null;
		}

		if (now_x > x&&now_y==y)
		{
			if (MapChipList[y][x - 1] != 0 && MapChipList[y][x - 1] != 12)
			{
				return Appulse;
			}
			else return Null;
		}

		if (now_y < y&&now_x==x)
		{
			if (MapChipList[y + 1][x] != 0 && MapChipList[y + 1][x] != 12)
			{
				return Appulse;
			}
			else return Null;
		}

		if (now_y > y==now_x==x)
		{
			if (MapChipList[y - 1][x] != 0 && MapChipList[y - 1][x] != 12)
			{
				return Appulse;
			}
			else return Null;
		}
		if (now_x == x && now_y == y) {
			return Null;
		}
	}
	else return NowMove;
}*/

NowStateId CollisionDetectionMapChip(float now_x, float now_y, int push_key, int MapChipList[22][19])
{

	if ((int)(now_x - 598) % WIDTH_POS == 0 && (int)(now_y - 120) % HEIGHT_POS == 0)
	{
		int x = (int)(now_x - 598) / WIDTH_POS;
		int y = (int)(now_y - 120) / HEIGHT_POS;

		switch (push_key)
		{
		case 1:
			if (MapChipList[y - 1][x] != 0 && MapChipList[y - 1][x] != 12)
			{
				return Appulse;
			}
			else return Null;

		case 2:
			if (MapChipList[y + 1][x] != 0 && MapChipList[y + 1][x] != 12)
			{
				return Appulse;
			}
			else return Null;
		case 3:
			if (MapChipList[y][x + 1] != 0 && MapChipList[y][x + 1] != 12)
			{
				return Appulse;
			}
			else return Null;
		case 4:
			if (MapChipList[y][x - 1] != 0 && MapChipList[y][x - 1] != 12)
			{
				return Appulse;
			}
			else return Null;
		}
	}
	else return NowMove;
}

// パックマンの操作先座標指定
void Pac_Mon_Move(VariableNumber* var, PLAYER* Pac_man,int MapChipList[22][19])
{
	switch (var->Keystate)
	{
	case 0:
		break;
	case 1:
		if(CollisionDetectionMapChip(Pac_man->pos_X, Pac_man->pos_Y, var->Keystate, MapChipList)==Appulse)
		{
			break;
		}

		Pac_man->pos_Y = Pac_man->pos_Y - var->MoveSpeed;
		break;

	case 2:
		if (CollisionDetectionMapChip(Pac_man->pos_X, Pac_man->pos_Y, var->Keystate, MapChipList) == Appulse)
		{
			break;
		}

		Pac_man->pos_Y = Pac_man->pos_Y + var->MoveSpeed;
		break;

	case 3:
		if (CollisionDetectionMapChip(Pac_man->pos_X, Pac_man->pos_Y, var->Keystate, MapChipList) == Appulse) 
		{
			break;
		}

		Pac_man->pos_X = Pac_man->pos_X + var->MoveSpeed;
		break;

	case 4:
		if (CollisionDetectionMapChip(Pac_man->pos_X, Pac_man->pos_Y, var->Keystate, MapChipList) == Appulse) 
		{
			break;
		}

		Pac_man->pos_X = Pac_man->pos_X - var->MoveSpeed;
		break;
	}
	
}