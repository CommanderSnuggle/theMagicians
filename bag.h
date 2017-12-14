#ifndef bag_h
#define bag_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class room;
class player;

class bag {
public:
	bag(std::string name = "bag", size_t limit = 0);
	size_t limit();
	void limit(size_t limit);
	std::string name();
	void name(std::string name);
	bool add(std::string s, bool talk = true);
	std::string remove();
	void display();
	bool full();
	bool empty();
	bool inside(std::string s);
private:
	size_t limit_;
	std::vector<std::string> inv_;
	std::string name_;
};
#endif // !bag_h

