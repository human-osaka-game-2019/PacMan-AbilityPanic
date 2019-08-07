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

NOW_STATE_ID CollisionDetectionMapChip(float now_x, float now_y, int push_key, int MapChipList[22][19])
{

	if ((int)(now_x - 598) % WIDTH_POS == 0 && (int)(now_y - 120) % HEIGHT_POS == 0)
	{
		int x = (int)(now_x - 598) / WIDTH_POS;
		int y = (int)(now_y - 120) / HEIGHT_POS;

		switch (push_key)
		{
		case 1:
			if (MapChipList[y - 1][x] != Road && MapChipList[y - 1][x] != Cookie)
			{
				return Appulse;
			}
			else return Null;

		case 2:
			if (MapChipList[y + 1][x] != Road && MapChipList[y + 1][x] != Cookie)
			{
				return Appulse;
			}
			else return Null;
		case 3:
			if (MapChipList[y][x + 1] != Road && MapChipList[y][x + 1] != Cookie)
			{
				return Appulse;
			}
			else return Null;
		case 4:
			if (MapChipList[y][x - 1] != Road && MapChipList[y][x - 1] != Cookie)
			{
				return Appulse;
			}
			else return Null;
		}
	}
	else return NowMove;
}

bool BifurcatioCheck(float char_x, float char_y, int** MapChipList)
{
	if ((int)(char_x - 598) % WIDTH_POS == 0 && (int)(char_y - 120) % HEIGHT_POS == 0)
	{
		int x = (int)(char_x - 598) / WIDTH_POS;
		int y = (int)(char_y - 120) / HEIGHT_POS;
		int bifurcatio_count = 0; //! 道を数えている

		if (MapChipList[y - 1][x] == Road || MapChipList[y - 1][x] == Cookie)
		{
			bifurcatio_count++;
		}

		if (MapChipList[y + 1][x] == Road || MapChipList[y + 1][x] == Cookie)
		{
			bifurcatio_count++;
		}

		if (MapChipList[y][x + 1] == Road || MapChipList[y][x + 1] == Cookie)
		{
			bifurcatio_count++;
		}

		if (MapChipList[y][x - 1] == Road || MapChipList[y][x - 1] == Cookie)
		{
			bifurcatio_count++;
		}

		// 3つ以上分かれ道があるかどうかをここで判断
		if (bifurcatio_count >= 3)
		{
			return true;
		}
		else return false;

	}
	return false;
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

NOW_STATE_ID CollisionDetectionMapChipZ(float now_x, float now_y, int push_key, int** MapChipList)
{

	if ((int)(now_x - 598) % WIDTH_POS == 0 && (int)(now_y - 120) % HEIGHT_POS == 0)
	{
		int x = (int)(now_x - 598) / WIDTH_POS;
		int y = (int)(now_y - 120) / HEIGHT_POS;

		switch (push_key)
		{
		case UP:
			if (MapChipList[y - 1][x] != Road && MapChipList[y - 1][x] != Cookie)
			{
				return Appulse;
			}
			else return Null;

		case DOWN:
			if (MapChipList[y + 1][x] != Road && MapChipList[y + 1][x] != Cookie)
			{
				return Appulse;
			}
			else return Null;
		case RIGHT:
			if (MapChipList[y][x + 1] != Road && MapChipList[y][x + 1] != Cookie)
			{
				return Appulse;
			}
			else return Null;
		case LEFT:
			if (MapChipList[y][x - 1] != Road && MapChipList[y][x - 1] != Cookie)
			{
				return Appulse;
			}
			else return Null;
		}
	}
	else return NowMove;
}


class answer
{
public:
	int Pos_x;
	int Pos_y;
	int Pos_RIGHTx;
	int Pos_LEFTx;
	int Pos_UPy;
	int Pos_DOWNy;
};

answer ans;
void EatCookie(VariableNumber* var, PLAYER* Pac_man, int MapChipList[22][19])
{
	ans.Pos_x = (int)(Pac_man->pos_X - 598) / 40;
	ans.Pos_y = (int)(Pac_man->pos_Y - 120) / 40;
	ans.Pos_LEFTx  = (int)(Pac_man->pos_X - 618) / 40;
	ans.Pos_RIGHTx = (int)(Pac_man->pos_X - 578) / 40;
	ans.Pos_UPy  = (int)(Pac_man->pos_Y - 140) / 40;
	ans.Pos_DOWNy = (int)(Pac_man->pos_Y - 100) / 40;
	int ax = (int)(Pac_man->pos_X - 598) % 40;
	int ay = (int)(Pac_man->pos_Y - 120) % 40;

	if (ax == 20 || ay == 20)
	{
		switch (var->Keystate)
		{
		case 0:
			break;
		case UP:
			MapChipList[ans.Pos_UPy][ans.Pos_x ] = 0;
			break;
		case DOWN:
			MapChipList[ans.Pos_DOWNy][ans.Pos_x ] = 0;
			break;
		case RIGHT:
			MapChipList[ans.Pos_y ][ans.Pos_RIGHTx] = 0;
			break;
		case LEFT:
			MapChipList[ans.Pos_y ][ans.Pos_LEFTx] = 0;
			break;
		}

	}
	else
	{
		MapChipList[ans.Pos_y][ans.Pos_y];
	}
}



 


 


 