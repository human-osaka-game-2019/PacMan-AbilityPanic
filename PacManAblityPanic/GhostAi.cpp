#include"GhostStatus.h"
#include"GhostAi.h"

void RED_GHOST::RedGhostUpdate (RED_GHOST* red) {
	switch ( RED_GHOST::Mode)
	{
	case NormalMode:
		RedNormalMoving (red);
		break;
	case ScatterMode:
		ScatterMoving ();
		break;
	case IzikeMode:
		IzikeMoving ();
		break;
	}
}

void RED_GHOST::RedNormalMoving(RED_GHOST* red)
{
	switch(RED_GHOST::Direction_of_travel)
	{
	case DIRECTION_OF_TRAVEL::up:

		red->pos_Y -= 1.2;
	
		break;
	case DIRECTION_OF_TRAVEL::left:

		red->pos_X -= 1.2;

		break;
	case DIRECTION_OF_TRAVEL::right:

		red->pos_X += 1.2;

		break;
	case DIRECTION_OF_TRAVEL::down:

		red->pos_Y += 1.2;

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
