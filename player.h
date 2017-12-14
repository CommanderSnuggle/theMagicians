#ifndef player_h
#define player_h

#include <iostream>
class bag;
class room;

class player {
public:
	player();
	room* location();
	room* lastLocation();
	void location(room* newLoc);
	std::string removeBag();
	bool addBag(std::string s);
	bool inBag(std::string s);
	void lookBag();
	void lookAround();
	void decide();
	void move();
	void pickUp();
	void putDown();
	~player();
private:
		room* location_;      
		room* last_;            
		bag* bag_;
};
#endif // !player_h
