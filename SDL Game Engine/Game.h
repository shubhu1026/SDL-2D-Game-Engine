#pragma once

#include<SDL2/SDL.h>
#include<vector>

#include "Actor.h"

class Game
{
public:
	Game();

	// Initialize the game
	bool Initialize();

	// Runs the game loop until the game is over
	void RunLoop();

	//Add and Remove Game Actors
	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);

	// Shutdown the game
	void Shutdown();

private:
	// Helper functions for the game loop
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	// Window created by SDL
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	//Window Variables
	const int mWindowH = 768;
	const int mWindowW = 1024;

	//Delta Time
	Uint32 mTicksCount;

	//Integrating Game Objects
	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;
	
	bool mUpdatingActors;

	// Game should continue to run
	bool mIsRunning;
};

