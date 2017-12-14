#ifndef game_h
#define game_h
#include <iostream>
#include "cellar.h"
#include "courtyard.h"
#include "dungeon.h"
#include "forest.h"
#include "hiddenPassage.h"
#include "library.h"
#include "player.h"


class game {
public:
	game();
	void theme();
	void map();
	void solution();
	void play();
	~game();
private:
	cellar* cellar_;
	courtyard* courtyard_;
	dungeon* dungeon_;
	forest* forest_;
	hiddenPassage* hiddenPassage_;
	library* library_;
	player* player_;
};
#endif // !game_h
