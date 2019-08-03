#include"GhostStatus.h"
#include"GhostAi.h"

void RED_GHOST::RedGhostUpdate () {
	switch ( RED_GHOST::Mode)
	{
	case NormalMode:
		RedNormalMoving ();
		break;
	case ScatterMode:
		ScatterMoving ();
		break;
	case IzikeMode:
		IzikeMoving ();
		break;
	}
}

void RED_GHOST::RedNormalMoving()
{
	switch(RED_GHOST::Direction_of_travel)
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
