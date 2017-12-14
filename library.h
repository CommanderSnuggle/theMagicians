#ifndef library_h
#define library_h
#include <iostream>
#include "room.h"

class library : public room {
public:
	library();
	bool enter(player* const player);
	~library();
private:
	size_t right_;
	struct riddle {
		std::string riddle_;
		std::string answer1_;
		std::string answer2_;
		char correct;
		riddle(std::string r, std::string a1,std::string a2, char c) {
			riddle_ = r;
			answer1_ = a1;
			answer2_ = a2;
			correct = c;
		}
	};
	std::vector<riddle> riddles_;

};
#endif // !library_h
