#ifndef dungeon_h
#define dungeon_h
#include <iostream>
#include "room.h"

class dungeon : public room {
public:
	dungeon();
	bool enter(player* const);
	~dungeon();
private:
	bool lightOn;
};
#endif // !dungeon_h

