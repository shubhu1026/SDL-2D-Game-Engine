#pragma once

#include <SDL2/SDL.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <SDL2/SDL_image.h>

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

	SDL_Texture* GetTexture(const std::string& fileName);

	//Handle Image Loading
	//SDL_Texture* LoadTexture(const char* fileName);
	void AddSprite(SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	// Shutdown the game
	void Shutdown();

private:
	// Helper functions for the game loop
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();

	//Map of loaded textures
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	// Window created by SDL
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	//Window Variables
	const int mWindowH = 768;
	const int mWindowW = 1024;

	//Delta Time
	Uint32 mTicksCount;

	//All actors in game
	std::vector<class Actor*> mActors;

	//All pending actors
	std::vector<class Actor*> mPendingActors;

	//All the sprite components drawn
	std::vector<class SpriteComponent*> mSprites;
	
	bool mUpdatingActors;

	// Game should continue to run
	bool mIsRunning;

	// Track if we're updating actors right now
	bool mUpdatingActors;
};

