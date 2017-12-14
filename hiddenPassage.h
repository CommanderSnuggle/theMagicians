#ifndef hiddenPassage_h
#define hiddenPassage_h

#include "room.h"

class hiddenPassage : public room {
public:
	hiddenPassage();
	bool enter(player* const player);
	~hiddenPassage();
private:
	size_t stones_;
};
#endif // !hiddenPassage_h
