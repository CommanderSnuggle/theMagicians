#include "courtyard.h"
#include "bag.h"

courtyard::courtyard() {
	items_->name("Water Well");
	items_->add("Torch of Hecate", false);
}
bool courtyard::enter(player* const player) {
	std::cout << std::endl << "You are in " << name() << std::endl;
	char choice = ' ';
	std::cout << "Where would you like to go" << std::endl;
	std::cout << "h) Horse Stable \n";
	std::cout << "w) Water Well\n";
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cout << "\n";
	if (choice == 'w') {
		std::cout << "You hide in the water well and find the \n";
		std::cout << "trapdoor to access to the hidden passageway.\n";
		open(5);
		return true;
	}
	else {
		std::cout << "There is nothing in the Horse Stable but horses\n";
		locked(5);
		return false;
	}
}
courtyard::~courtyard(){}