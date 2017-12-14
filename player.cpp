#include"player.h"
#include "room.h"
#include "bag.h"

player::player() {
	bag_ = new bag("bag", 4);
	bag_->add("shiny ruby", false);
}
room* player::location() {
	return location_;
}
room* player::lastLocation() {
	return last_;
}
void player::location(room* newLoc) {
	last_ = location_;
	location_ = newLoc;
}
std::string player::removeBag() {
	return bag_->remove();
}
bool player::addBag(std::string s) {
	return bag_->add(s);
}
bool player::inBag(std::string s) {
	return bag_->inside(s);
}
void player::lookBag() {
	bag_->display();
}
void player::lookAround() {
	location()->lookItems();
}
void player::decide() {
	char choice;
	std::cout << "\n";
	std::cout << "What do you want to do?\n";
	std::cout << "u) pick up an item\n";
	std::cout << "d) put down an item\n";
	std::cout << "s) switch two items\n";
	std::cout << "m) move on\n";
	std::cout << "Enter u, d, s, or m: ";
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cout << "\n";
	switch (choice) {
	case 'u':
		pickUp();
		break;
	case 'd':
		putDown();
		break;
	case 's':
		putDown();
		pickUp();
		break;

	default:
		std::cout << "Moving on.\n";
		break;
	}
}
void player::move() {
	location(location()->exit());
}
void player::pickUp() {
	bool add = true;
	std::string item;
	item = location()->removeItems();
	add = true;
	if (item != "") {
		add = addBag(item);
	}
	if (!add) {
		removeBag();
		addBag(item);
	}
}
void player::putDown() {
	std::string item;
	item = removeBag();
	if (item != "")
		location()->addItems(item);
}
player::~player() {
	delete bag_;
}