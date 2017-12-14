#include "library.h"
#include "bag.h"

library::library() {
	items_->name("Library Chest");
	items_->add("Bow of Artemis", false);
	items_->add("Golden Pen", false);
	items_->add("Casting for Dummies(book)", false);

	right_ = 0;

	riddles_.push_back(riddle("I'm so fragile that when\nyou say my name you\nbreak me",
		"silence",
		"glass",
		'a'));

	riddles_.push_back(riddle("I never was, am always be,\nNo one ever saw me, nor ever will\nAnd yet I am the confidence of all\nTo live and breathe on this terrestrial ball",
		"A shoe",
		"Tomorrow",
		'b'));

	riddles_.push_back(riddle("The beginning of eternity\nThe end of time and space\nThe beginning of every end.\n And the end of every place.",
		"A watermelon",
		"The letter E",
		'b'));

	riddles_.push_back(riddle("At night they come without being fetched.\nAnd by day they are lost without being stolen.",
		"Stars",
		"FireFlys",
		'a'));
}
bool library::enter(player* player) {
	std::cout << "\nYou are in " << name() << "\n";
	char choice = ' ';
	std::cout << "You need to answer all the riddles to unlock the library chests\n";
	std::cout << "You are " << right_ * 25 << "% right in unlocking the chest\n\n";
	if (right_ < 4) {
		std::cout << "Here is your riddle:\n";
		std::cout << riddles_[right_].riddle_ << std::endl;
		std::cout << "a) " << riddles_[right_].answer1_ << std::endl;
		std::cout << "b) " << riddles_[right_].answer2_ << std::endl;
		std::cout << "What do you choice? (a or b): ";
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		if (choice == riddles_[right_].correct) {
			right_++;
			std::cout << "That is correct. \n\n";
		}
		else {
			std::cout << "That is not correct.\n\n";
		}
		return false;
	}
	else {
		return true;
	}

}
library::~library() {

}