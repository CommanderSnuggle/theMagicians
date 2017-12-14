#include "dungeon.h"
#include "bag.h"

dungeon::dungeon() {
	items_->name("Dungeon Chest");
	items_->add("Rusty Nail", false);
	items_->add("Stale Bread", false);
	items_->add("Fire of Prometheus", false);
	items_->add("Stone of Resurrection", false);
	lightOn = false;
}
bool dungeon::enter(player* player) {
	std::cout << std::endl << "You are in " << name() <<"\n";

	char choice = ' ';
	if (lightOn) {
		std::cout << "The light is on. \n";
		std::cout << "Do you want to turn it off (y or n)? ";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		if (choice == 'y') {
			lightOn = false;
			return false;
		}
		else {
			return true;
		}
	}
	else {
		std::cout << "The light is off.\n";
		std::cout << "Do you want to turn it on (y or n)? ";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "\n";
		if (choice == 'y') {
			lightOn = true;
			return true;
		}
		else {
			return false;
		}
	}
}
dungeon::~dungeon() {}