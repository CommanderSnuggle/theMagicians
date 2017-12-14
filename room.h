#ifndef room_h
#define room_h
#include <iostream>
#include <string>
#include <vector>
#include "bag.h"

class player;
//class bag;

class room {
protected:
	std::string name_;
	struct exit {
		room* dest_;
		std::string desc_;
		bool open_;
		exit(room* dest, std::string desc, bool open = true) {
			dest_ = dest;
			desc_ = desc;
			open_ = open;
		}
	};
	std::vector<exit> exits_;
	bag* items_;
public:
	room();
	virtual bool enter(player* const) = 0;
	std::string name();
	void name(std::string);
	room* exit(size_t numExit = 0);
	void exit(room* dest, std::string desc, bool open = true);
	void open(size_t choice);
	void locked(size_t choice);
	std::string removeItems();
	bool addItems(std::string s);
	void lookItems();
	virtual ~room();
};
#endif // !room_h

