#include "hiddenPassage.h"
#include "bag.h"
hiddenPassage::hiddenPassage() {
	items_->name("drainage pipe");
	stones_ = 2;
}
bool hiddenPassage::enter(player* const player) {
	std::cout << std::endl << "You are in " << name() << std::endl;

	char choice = ' ';
	if (stones_ > 0) {
		std::cout << "There are " << stones_ << " stones left on the "
			<< name() << "\n" ;
		std::cout << "Would you like to move them? (y or n) ";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "\n";
		if (choice == 'y') {
			stones_--;
		}
		locked(3); // exit to forest is blocked
		return false;
	}
	else {
		std::cout << "You have cleared " << name() << std::endl;
		open(3);
		return true;
	}
}
hiddenPassage::~hiddenPassage() {

}