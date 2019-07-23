#include"GhostStatus.h"
#include"GhostAi.h"

void RED_GHOST::RedGhostUpdate () {
	switch ( RED_GHOST::Mode)
	{
	case NormalMode:
		break;
	case ScatterMode:
		ScatterMoveing ();
		break;
	case IzikeMode:
		IzikeMoveing ();
		break;
	}
}

void PINK_GHOST::PinkGhostUpdate () {
	switch (PINK_GHOST::Mode)
	{
	case NormalMode:
		break;
	case ScatterMode:
		ScatterMoveing ();
		break;
	case IzikeMode:
		IzikeMoveing ();
		break;
	}
}

void WATERY_GHOST::WateryGhostUpdate () {
	switch (WATERY_GHOST::Mode)
	{
	case NormalMode:
		break;
	case ScatterMode:
		ScatterMoveing ();
		break;
	case IzikeMode:
		IzikeMoveing ();
		break;
	}
}

void ORANGE_GHOST::OrangeGhostUpdate() {
	switch (ORANGE_GHOST::Mode)
	{
	case NormalMode:
		break;
	case ScatterMode:
		ScatterMoveing ();
		break;
	case IzikeMode:
		IzikeMoveing ();
		break;
	}
}

void ScatterMoveing ()
{

};

void IzikeMoveing () 
{

}
