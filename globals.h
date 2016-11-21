#include "stdafx.h"
#pragma once

//////////////////////////////////////////////////////////////////////////////////////////
// externals 
//////////////////////////////////////////////////////////////////////////////////////////
extern void winReshapeFunc(GLint w, GLint h);
extern void renderScene();
extern void update();

//////////////////////////////////////////////////////////////////////////////////////////
// constants 
//////////////////////////////////////////////////////////////////////////////////////////
const int SCREEN_WIDTH	= 500;
const int SCREEN_HEIGHT = 500;

const int FPS = 60;//anything bigger than 60 fps is pointless on most machines

const int BOID_MAX = 20;

//////////////////////////////////////////////////////////////////////////////////////////
// structures 
//////////////////////////////////////////////////////////////////////////////////////////
struct sRGB
{
	float r, g, b;
};
