#include "bag.h"

bag::bag(std::string name, size_t limit) 
:name_(name),limit_(limit){}
size_t bag::limit() {
	return limit_;
}
void bag::limit(size_t limit) {
	limit_ = limit;
}
std::string bag::name() {
	return name_;
}
void bag::name(std::string name) {
	name_ = name;
}
bool bag::add(std::string s, bool talk) {

	if (inside(s))
	{
		if (talk) std::cout << "The " << s << " is already in " << ".\n";
		std::cout << "\n";
		return false;
	}
	else if (full()) {
		if (talk) std::cout << name_ << " is full. \n";
		if (talk) std::cout << "Couldn't add " << s << " to " << name_ << ".\n";
		std::cout << "\n";
		return false;
	}
	else {
		inv_.push_back(s);
		if (talk) std::cout << "Added " << s << " to " << name_ << ".\n";
		std::cout << "\n";
		return true;
	}
}
std::string bag::remove() {
	size_t n;
	if (inv_.empty()) {
		std::cout << name_ << " is empty.";
		return "";
	}
	else {
		display();
		std::cout << static_cast<int>(inv_.size()) + 1 << ") Nothing \n";
		std::cout << "Which item do you want to remove from the " << name_ << "?\n";
		std::cout << "Enter a number: ";
		std::cin >> n;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		if (n <= static_cast<int>(inv_.size())) {
			std::string s = inv_[n - 1];
			inv_.erase(inv_.begin() + n - 1);
			std::cout << "Removed " << s << " from " << name_ << ".\n";
			return s;
		}
		else {
			return "";
		}
	}
}
void bag::display() {
	std::cout << "The " << name_ << " contains " << inv_.size()
		<< " items: \n" ;
	for (int i = 0; i<static_cast<int>(inv_.size()); i++)
		std::cout << i + 1 << ") " << inv_[i] << " \n";
}
bool bag::full() {
	if (limit_ > 0 && static_cast<size_t>(inv_.size()) >= limit_)
	{
		return true;
	}
	else {
		return false;
	}
}
bool bag::empty() {
	return inv_.empty();
}
bool bag::inside(std::string s) {
	std::vector<std::string>::iterator it;
	it = find(inv_.begin(), inv_.end(), s);
	if (it != inv_.end())
	{
		return true;
	}
	else {
		return false;
	}
}