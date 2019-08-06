#include"GhostStatus.h"
#include"GhostAi.h"
#include"GameSystem.h"
#include<time.h>




void RED_GHOST::RedAbilityUse() 
{

}

void RED_GHOST::RedGhostUpdate (RED_GHOST* red,int** MapChipList,int randm) 
{

	switch ( RED_GHOST::Mode)
	{
	case NormalMode:
		
		RedNormalMoving (red,MapChipList,randm);
		break;
	case ScatterMode:
		ScatterMoving ();
		break;
	case IzikeMode:
		IzikeMoving ();
		break;
	}
}

void RED_GHOST::RedNormalMoving(RED_GHOST* red,int** MapChipList,int randm)
{

	switch(red->Direction_of_travel)
	{
	case DIRECTION_OF_TRAVEL::up:
	
		if (CollisionDetectionMapChipZ(red->pos_X,red->pos_Y,up, MapChipList) == Appulse)
		{
			red->Direction_of_travel = randm;
			
			break;
		}
		else 

		if (BifurcatioCheck(red->pos_X, red->pos_Y, MapChipList) == true)
		{

			red->Direction_of_travel = left;
			break;
		}
			red->pos_Y = red->pos_Y - red->Speed;
		break;
	case DIRECTION_OF_TRAVEL::left:
		if (CollisionDetectionMapChipZ(red->pos_X, red->pos_Y, left, MapChipList) == Appulse)
		{
			red->Direction_of_travel = randm;
			
			break;
		}else
		if (BifurcatioCheck(red->pos_X, red->pos_Y, MapChipList) == true)
		{
			red->Direction_of_travel = up;
			break;
		}
		
			red->pos_X = red->pos_X - red->Speed;
		break;
	case DIRECTION_OF_TRAVEL::right:
		
		if (CollisionDetectionMapChipZ(red->pos_X, red->pos_Y, right, MapChipList) == Appulse)
		{
			red->Direction_of_travel = randm;
			
			break;
		}else
		if (BifurcatioCheck(red->pos_X, red->pos_Y, MapChipList) == true)
		{
			red->Direction_of_travel = randm;
			break;
		}
			red->pos_X = red->pos_X + red->Speed;
		break;
	case DIRECTION_OF_TRAVEL::down:
		if (CollisionDetectionMapChipZ(red->pos_X, red->pos_Y, down, MapChipList) == Appulse)
		{
			red->Direction_of_travel = randm;
			
			break;
		}else
		if (BifurcatioCheck(red->pos_X, red->pos_Y, MapChipList) == true)
		{
			red->Direction_of_travel = randm;
			break;
		}
		
			red->pos_Y = red->pos_Y + red->Speed;
		break;
	}

	
};

void PINK_GHOST::PinkGhostUpdate (PINK_GHOST* pink, int** MapChipList, int randm) {
	switch (PINK_GHOST::Mode)
	{
	case NormalMode:
		PinkNormalMoving (pink,MapChipList,randm);
		break;
	case ScatterMode:
		ScatterMoving ();
		break;
	case IzikeMode:
		IzikeMoving ();
		break;
	}
}

void PINK_GHOST::PinkNormalMoving(PINK_GHOST* pink, int** MapChipList, int randm)
{
	switch(pink->Direction_of_travel)
	{
	case DIRECTION_OF_TRAVEL::up:
		if (CollisionDetectionMapChipZ(pink->pos_X, pink->pos_Y, up, MapChipList) == Appulse)
		{
			pink->Direction_of_travel = randm;

			break;
		}
		pink->pos_Y = pink->pos_Y - pink->Speed;
		break;
	case DIRECTION_OF_TRAVEL::left:
		if (CollisionDetectionMapChipZ(pink->pos_X, pink->pos_Y, left, MapChipList) == Appulse)
		{
			pink->Direction_of_travel = randm;

			break;
		}
		pink->pos_X = pink->pos_X - pink->Speed;
		break;
	case DIRECTION_OF_TRAVEL::right:
		if (CollisionDetectionMapChipZ(pink->pos_X, pink->pos_Y, right, MapChipList) == Appulse)
		{
			pink->Direction_of_travel = randm;

			break;
		}
		pink->pos_X = pink->pos_X + pink->Speed;
		break;
	case DIRECTION_OF_TRAVEL::down:
		if (CollisionDetectionMapChipZ(pink->pos_X, pink->pos_Y, down, MapChipList) == Appulse)
		{
			pink->Direction_of_travel = randm;

			break;
		}
		pink->pos_Y = pink->pos_Y + pink->Speed;
		break;
	}
};

void WATERY_GHOST::WateryGhostUpdate (WATERY_GHOST* watery, int** MapChipList, int randm) {
	switch (WATERY_GHOST::Mode)
	{
	case NormalMode:
		WateryNormalMoving (watery,MapChipList,randm);
		break;
	case ScatterMode:
		ScatterMoving ();
		break;
	case IzikeMode:
		IzikeMoving ();
		break;
	}
}

void WATERY_GHOST::WateryNormalMoving(WATERY_GHOST* watery, int** MapChipList, int randm)
{
	switch (watery->Direction_of_travel)
	{
	case DIRECTION_OF_TRAVEL::up:
		if (CollisionDetectionMapChipZ(watery->pos_X, watery->pos_Y, up, MapChipList) == Appulse)
		{
			watery->Direction_of_travel = randm;

			break;
		}
		watery->pos_Y = watery->pos_Y - watery->Speed;
		break;
	case DIRECTION_OF_TRAVEL::left:
		if (CollisionDetectionMapChipZ(watery->pos_X, watery->pos_Y, left, MapChipList) == Appulse)
		{
			watery->Direction_of_travel = randm;

			break;
		}
		watery->pos_X = watery->pos_X - watery->Speed;
		break;
	case DIRECTION_OF_TRAVEL::right:
		if (CollisionDetectionMapChipZ(watery->pos_X, watery->pos_Y, right, MapChipList) == Appulse)
		{
			watery->Direction_of_travel = randm;

			break;
		}
		watery->pos_X = watery->pos_X + watery->Speed;
		break;
	case DIRECTION_OF_TRAVEL::down:
		if (CollisionDetectionMapChipZ(watery->pos_X, watery->pos_Y, down, MapChipList) == Appulse)
		{
			watery->Direction_of_travel = randm;

			break;
		}
		watery->pos_Y = watery->pos_Y + watery->Speed;
		break;
	}
};

void ORANGE_GHOST::OrangeGhostUpdate(ORANGE_GHOST* orange, int** MapChipList, int randm) {
	switch (ORANGE_GHOST::Mode)
	{
	case NormalMode:
		OrangeNormalMoving ( orange,MapChipList, randm);
		break;
	case ScatterMode:
		ScatterMoving ();
		break;
	case IzikeMode:
		IzikeMoving ();
		break;
	}
}

void ORANGE_GHOST::OrangeNormalMoving(ORANGE_GHOST* orange, int** MapChipList, int randm)
{
	switch (orange->Direction_of_travel)
	{
			case DIRECTION_OF_TRAVEL::up:
				if (CollisionDetectionMapChipZ(orange->pos_X, orange->pos_Y, up, MapChipList) == Appulse)
				{
					orange->Direction_of_travel = randm;

					break;
				}
				orange->pos_Y = orange->pos_Y - orange->Speed;
				break;
			case DIRECTION_OF_TRAVEL::left:
				if (CollisionDetectionMapChipZ(orange->pos_X, orange->pos_Y, left, MapChipList) == Appulse)
				{
					orange->Direction_of_travel = randm;

					break;
				}
				orange->pos_X = orange->pos_X - orange->Speed;
				break;
			case DIRECTION_OF_TRAVEL::right:
				if (CollisionDetectionMapChipZ(orange->pos_X, orange->pos_Y, right, MapChipList) == Appulse)
				{
					orange->Direction_of_travel = randm;

					break;
				}
				orange->pos_X = orange->pos_X + orange->Speed;
				break;
			case DIRECTION_OF_TRAVEL::down:
				if (CollisionDetectionMapChipZ(orange->pos_X, orange->pos_Y, down, MapChipList) == Appulse)
				{
					orange->Direction_of_travel = randm;

					break;
				}
				orange->pos_Y = orange->pos_Y + orange->Speed;
				break;
	}
};



void ScatterMoving ()
{

};

void IzikeMoving () 
{

}
