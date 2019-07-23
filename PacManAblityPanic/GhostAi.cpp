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

};

void ScatterMoving ()
{

};

void IzikeMoving () 
{

}
