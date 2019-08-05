#include"class.h"
#include"CollisionDetection.h"

NowStateId CollisionDetectionMapChip (float now_x, float now_y, int push_key,int MapChipList[MAP_SIZE_HEIGHT_POS][MAP_SIZE_WIDTH_POS])
{

	if ((int)(now_x - 598) % WIDTH_POS == 0 && (int)(now_y - 120) % HEIGHT_POS == 0)
	{
		int x = (now_x - 598) / WIDTH_POS;
		int y = (now_y - 120) / HEIGHT_POS;

		switch (push_key)
		{
		case Key::Right:
			if (MapChipList[y][x + 1] != 0 && MapChipList[y][x + 1] != 12) 
			{
				return Appulse;
			}
			else return Null;

		case Key::Left:
			if (MapChipList[y][x - 1] != 0 && MapChipList[y][x - 1] != 12) 
			{
				return Appulse;
			}
			else return Null;
		case Key::Down:
			if (MapChipList[y + 1][x] != 0 && MapChipList[y + 1][x] != 12) 
			{
				return Appulse;
			}
			else return Null;
		case Key::Up:
			if (MapChipList[y - 1][x] != 0 && MapChipList[y - 1][x] != 12) 
			{
				return Appulse;
			}
			else return Null;
		}
	}
	else return NowMove;
}