#include"class.h"
#include"CollisionDetection.h"

NowStateId CollisionDetectionMapChip (MapChipData mapchip,float now_x, float now_y, int push_key,int MapChipList[MAP_SIZE_HEIGHT][MAP_SIZE_WIDTH])
{

	if ((int)now_x % (int)mapchip.MapChipWidht == 0 && (int)now_y % (int)mapchip.MapChipHeight == 0) 
	{
		int x = now_x / mapchip.MapChipWidht;
		int y = now_y / mapchip.MapChipHeight;

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