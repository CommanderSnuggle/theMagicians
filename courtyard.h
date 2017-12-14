#ifndef courtyard_h
#define courtyard_h
#include "room.h"

class courtyard : public room {
public:
	courtyard();
	bool enter(player* const player);
	~courtyard();
};
#endif // !courtyard_h
