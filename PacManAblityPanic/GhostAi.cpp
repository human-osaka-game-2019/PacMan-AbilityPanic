#include"GhostStatus.h"
#include"GhostAi.h"
#include"GameSystem.h"
#include<time.h>






void RED_GHOST::RedGhostUpdate (RED_GHOST* red,int** MapChipList,int randm) {

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
			red->pos_Y = red->pos_Y - red->Speed;
		break;
	case DIRECTION_OF_TRAVEL::left:
		if (CollisionDetectionMapChipZ(red->pos_X, red->pos_Y, left, MapChipList) == Appulse)
		{
			red->Direction_of_travel = randm;
			
			break;
		}
			red->pos_X = red->pos_X - red->Speed;
		break;
	case DIRECTION_OF_TRAVEL::right:
		if (CollisionDetectionMapChipZ(red->pos_X, red->pos_Y, right, MapChipList) == Appulse)
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
		}
			red->pos_Y = red->pos_Y + red->Speed;
		break;
	}

	
};

void PINK_GHOST::PinkGhostUpdate () {
	switch (PINK_GHOST::Mode)
	{
	case NormalMode:
		PinkNormalMoving ();
		break;
	case ScatterMode:
		ScatterMoving ();
		break;
	case IzikeMode:
		IzikeMoving ();
		break;
	}
}

void PINK_GHOST::PinkNormalMoving()
{
	switch(PINK_GHOST::Direction_of_travel)
	{
	case DIRECTION_OF_TRAVEL::up:

		break;
	case DIRECTION_OF_TRAVEL::left:

		break;
	case DIRECTION_OF_TRAVEL::right:

		break;
	case DIRECTION_OF_TRAVEL::down:

		break;
	}
};

void WATERY_GHOST::WateryGhostUpdate () {
	switch (WATERY_GHOST::Mode)
	{
	case NormalMode:
		WateryNormalMoving ();
		break;
	case ScatterMode:
		ScatterMoving ();
		break;
	case IzikeMode:
		IzikeMoving ();
		break;
	}
}

void WATERY_GHOST::WateryNormalMoving()
{
	switch (WATERY_GHOST::Direction_of_travel)
	{
	case DIRECTION_OF_TRAVEL::up:

		break;
	case DIRECTION_OF_TRAVEL::left:

		break;
	case DIRECTION_OF_TRAVEL::right:

		break;
	case DIRECTION_OF_TRAVEL::down:

		break;
	}
};

void ORANGE_GHOST::OrangeGhostUpdate() {
	switch (ORANGE_GHOST::Mode)
	{
	case NormalMode:
		OrangeNormalMoving ();
		break;
	case ScatterMode:
		ScatterMoving ();
		break;
	case IzikeMode:
		IzikeMoving ();
		break;
	}
}

void ORANGE_GHOST::OrangeNormalMoving()
{
	switch (ORANGE_GHOST::Direction_of_travel)
	{
	case DIRECTION_OF_TRAVEL::up:

		break;
	case DIRECTION_OF_TRAVEL::left:

		break;
	case DIRECTION_OF_TRAVEL::right:

		break;
	case DIRECTION_OF_TRAVEL::down:

		break;
	}
};

void ScatterMoving ()
{

};

void IzikeMoving () 
{

}
