#include "room.h"
#include "player.h"

room::room() { items_ = new bag; }
room::~room() {
	exits_.empty();
	delete items_;
}

std::string room::name() { return name_; }
void room::name(std::string name) { name_ = name; }

room* room::exit(size_t numExit) {
	char choice = ' ';
	std::cout << "You are in " << name_ << ".\n";
	if (numExit == 0)
	{
		for (size_t i = 0; i<static_cast<size_t>(exits_.size()); i++) {
			if (exits_[i].open_) {
				std::cout << i + 1 << ") " << exits_[i].desc_ << "\n";
			}
		}
		std::cout << "Where would you like to go? \n";
		while (numExit < 1 || numExit > static_cast<size_t>(exits_.size())) {
			std::cout << "Enter a number: \n";
			std::cin >> choice;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			numExit = static_cast<size_t>(choice) - static_cast<size_t>('0');
		}
	}
	std::cout << "You are going to " << exits_[numExit - 1].desc_ << std::endl;
	return exits_[numExit - 1].dest_;
}
void room::exit(room* dest, std::string desc, bool open) {
	exits_.push_back(struct exit(dest, desc, open));
}

void room::open(size_t choice) {
	if (choice > 0 && choice <= static_cast<size_t>(exits_.size())) {
		exits_[choice - 1].open_ = true;
	}
}
void room::locked(size_t choice) {
	if (choice > 0 && choice <= static_cast<size_t>(exits_.size())) {
		exits_[choice - 1].open_ = false;
	}
}

std::string room::removeItems() {
	return items_ -> remove();
}
bool room::addItems(std::string s) {
	return items_->add(s);
}
void room::lookItems() {
	items_->display();
}
