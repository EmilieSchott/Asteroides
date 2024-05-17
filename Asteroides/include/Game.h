#pragma once

#include "../include/Space.h"

class Game
{
public:
	Game(Space& p_space);
	void start();
	void terminate();
	inline bool isRunning() { return running; };

private:
	Space& space;
	bool running{ false };

};

