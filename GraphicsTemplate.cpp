// GraphicsTemplate.cpp
// 
//////////////////////////////////////////////////////////////////////////////////////////
// includes 
//////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////////////////////
// externals 
//////////////////////////////////////////////////////////////////////////////////////////
extern cRenderClass graphics;
extern NA_MathsLib na_maths;

vector<NA_Boid> boidList; //not really a list

//////////////////////////////////////////////////////////////////////////////////////////
// renderScene() - render the scene
//////////////////////////////////////////////////////////////////////////////////////////
void renderScene()
{
	for (int i = 0; i < BOID_MAX; i++)
	{
		boidList[i].draw();
	}


	

	// render the scene
	graphics.render();
}

//////////////////////////////////////////////////////////////////////////////////////////
// update() - update function
//////////////////////////////////////////////////////////////////////////////////////////
void update()
{

	renderScene();
	cout << "first render done\n";
	// add any update code here...
	static NA_Timer fpsCap;//wait if FPS is too high (if boids move too fast)
	fpsCap.restart();


	for (int i = 0; i < BOID_MAX; i++)
	{
		boidList[i].update();
	}


	for (int i = 0; i < BOID_MAX; i++)
	{
		boidList[i].postUpdate();
	}



	//cout << "updates done, waiting\n";
	fpsCap.setDuration(1/FPS_MAX);
	fpsCap.wait();

	// always re-render the scene..
	renderScene();
	cout << " post render done\n";
}



//////////////////////////////////////////////////////////////////////////////////////////
// _tmain() - program entry point
//////////////////////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{	
	// init glut stuff..
	graphics.create(argc, argv);

	// good place for one-off initialisations and objects creation..

	//make all boids
	na_maths.seedDice();
	for (int i = 0; i < BOID_MAX; i++)
	{
		NA_Boid temp;
		temp.position.x = na_maths.dice(SCREEN_WIDTH);
		temp.position.y = na_maths.dice(SCREEN_HEIGHT);

		temp.currentVelocity.x = na_maths.dice(-10,10);
		temp.currentVelocity.y = na_maths.dice(-10, 10);

		boidList.push_back(temp);

		//cout << "POS: X: " << temp.position.x << " Y: " << temp.position.y << "\n";
		//cout << "VEL: X: " << temp.currentVelocity.x << " Y: " << temp.currentVelocity.y << "\n";

		//NA_Vector t = temp.currentVelocity;
		//t.normalise();
		//cout << "NV: X: " << t.x << " Y: " << t.y << "\n\n";


	}


	// enter game loop..
	graphics.loop();	

	return 0;
}




