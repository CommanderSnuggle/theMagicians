#include "game.h"

int main() {
	game game;
	char choice = ' ';

	game.theme();
	game.map();


	std::cout << "What would you like to do? " << std::endl;
	std::cout << "p) Play game" << std::endl;
	std::cout << "s) Solution" << std::endl;
	std::cout << "Enter p or s: ";
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	switch (choice) {
	case 'p':
		game.play();
		break;
	case 's':
		game.solution();
		break;
	default:
		break;
	}
	return 0;
}