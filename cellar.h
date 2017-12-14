#ifndef cellar_h
#define cellar_h
#include "room.h"

class cellar : public room {
public:
	cellar();
	bool enter(player* const player);
	~cellar();
};
#endif // !cellar_h
