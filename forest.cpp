#include "forest.h"
#include "player.h"
forest::forest() {
	items_->name("tress");
}
bool forest::enter(player* const player) {
	std::cout << "\nYou have reached " << name() <<"\n";
	if (player->inBag("Brisingamen") &&
		player->inBag("Torch of Hecate") &&
		player->inBag("Bow of Artemis") &&
		player->inBag("Fire of Prometheus")) {
		std::cout << "You have all the items to restore magic to the world!\n";
		return true;
	}
	else {
		std::cout << "You do not have the right items to restore magic to the world.\n";
		return false;
	}
}
forest::~forest(){}