#include "cellar.h"
#include "bag.h"

cellar::cellar(){
	items_->name("Wine Barrel");
	items_->add("Gold Coin", false);
	items_->add("Brisingamen", false);
	items_->add("Old Wooden Wand", false);
	items_->add("Broken Wine Glass", false);
}
bool cellar::enter(player* const player){
	std::cout << std::endl << "You are in " << name() << "\n";
	char choice = ' ';
	std::cout << "You find a shady guard that will let you entry for a shiny ruby. \n";
	std::cout << "Do you have any to trade?\n";
	std::cout << "y) yes\n";
	std::cout << "n) no\n";
	std::cout << "Enter y or n: ";
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	if (choice == 'y') {
		return true;
	}
	else {
		return false;
	}
}
cellar::~cellar(){}