#ifndef forest_h
#define forest_h

#include <iostream>
#include "room.h"

class forest : public room {
public:
	forest();
	bool enter(player* const player);
	~forest();
};
#endif // !forest_h
