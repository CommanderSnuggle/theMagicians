#include "game.h"

game::game() {
	cellar_ = new cellar;
	courtyard_ = new courtyard;
	dungeon_ = new dungeon;
	forest_ = new forest;
	hiddenPassage_ = new hiddenPassage;
	library_ = new library;

	cellar_->name("the cellar");
	cellar_->exit(dungeon_, "go to the dungeon.");
	cellar_->exit(forest_, "sneak through the front gate.");
	cellar_->exit(library_, "go to the library.");
	cellar_->exit(cellar_, "stay in the cellar.");
	cellar_->exit(courtyard_, "go to the courtyard.\n");

	courtyard_->name("the courtyard");
	courtyard_->exit(dungeon_, "go to the dungeon.");
	courtyard_->exit(library_, "go to the library.");
	courtyard_->exit(cellar_, "go to the cellar.");
	courtyard_->exit(courtyard_, "stay in the courtyard.");
	courtyard_->exit(hiddenPassage_, "enter hidden passage.\n", false);

	dungeon_->name("Dungeon ");
	dungeon_->exit(dungeon_, "stay in the dungeon.");
	dungeon_->exit(forest_, "climb over the castle wall fence.");
	dungeon_->exit(library_, "go to the library.");
	dungeon_->exit(cellar_, "go to the cellar.");
	dungeon_->exit(courtyard_, "go to the courtyard.\n");

	forest_->name("the forest");
	forest_->exit(dungeon_, "Captured, return to dungeons.");
	forest_->exit(library_, "Captured, return to the library.");
	forest_->exit(cellar_, "Captured, return to cellar.");
	forest_->exit(hiddenPassage_, "change mind, return to hidden passage.\n");

	hiddenPassage_->name("the hidden passage");
	hiddenPassage_->exit(hiddenPassage_, "stay in the hidden passage.");
	hiddenPassage_->exit(courtyard_, "climb out onto the courtyard.");
	hiddenPassage_->exit(forest_, "climb out into the forest.\n", false);

	library_->name("the library");
	library_->exit(dungeon_, "go to the dungeon.");
	library_->exit(forest_, "stow away in a merchants wagon.");
	library_->exit(library_, "stay in the library.");
	library_->exit(cellar_, "go to the cellar.");
	library_->exit(courtyard_, "go to the courtyard.\n");

	player_ = new player;
	player_->location(dungeon_);
}
void game::theme() {
	std::cout << "################################################################################\n";
	std::cout << "  _______ _    _ ______   __  __          _____ _____ _____ _____          _   _  _____ \n";
	std::cout << " |__   __| |  | |  ____| |  \\/  |   /\\   / ____|_   _/ ____|_   _|   /\\   | \\ | |/ ____|\n";
	std::cout << "    | |  | |__| | |__    | \\  / |  /  \\ | |  __  | || |      | |    /  \\  |  \\| | (___  \n";
	std::cout << "    | |  |  __  |  __|   | |\\/| | / /\\ \\| | |_ | | || |      | |   / /\\ \\ | . ` |\___ \\ \n";
	std::cout << "    | |  | |  | | |____  | |  | |/ ____ \\ |__| |_| || |____ _| |_ / ____ \\| |\\  |____) |\n";
	std::cout << "    |_|  |_|  |_|______| |_|  |_/_/    \\_\\_____|_____\\_____|_____/_/    \\_\\_| \\_|_____/ \n";
	std::cout << "################################################################################\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "################### The Magicians ########################" << std::endl;
	std::cout << "  The Magician King has stolen all the magic in the land\n";
	std::cout << "  and as one of the very last magicians left alive you  \n";
	std::cout << "  plan to return it. You have been disguise as prisoner \n";
	std::cout << "    in the kings dungeon. Word is that the King has     \n";
	std::cout << "  trapped all the magic in four unique items in the     \n";
	std::cout << "  castle. You have a bag that can only carry four items.\n"; 
	std::cout << "  You have casted a dummy spell to take you place in    \n";
	std::cout << "  your cell it only last for 24 hrs. Your main objective\n";
	std::cout << "  gather the four items and escape the castle without   \n";
	std::cout << "  getting caught. You only have 24hrs before the spell  \n";
	std::cout << "  runs out and you can not escape without the items. n  \n";
	std::cout << "##########################################################" << std::endl;
	std::cout << std::endl;
}
void game::map() {
	std::cout << "                                                        " << std::endl;
	std::cout << "                      The Magicians                        " << std::endl;
	std::cout << "                                                        " << std::endl;
	std::cout << " ###################################################### " << std::endl;
	std::cout << " #                                   Castle Wall      # " << std::endl;
	std::cout << " #     --------------          -----------            # " << std::endl;
	std::cout << " #     |             |         |          |           # " << std::endl;
	std::cout << " #     | Dungeon     |         | Cellar   |           # " << std::endl;
	std::cout << " #     |             |         |          |           # " << std::endl;
	std::cout << " #      -------------          -----------            # " << std::endl;
	std::cout << " #                                                    # " << std::endl;
	std::cout << " #     -----------      --------------------------    # " << std::endl;
	std::cout << " #     |          |     |         |Horse Stable|  |   # " << std::endl;
	std::cout << " #     | Library  |     |Courtyard                |   # " << std::endl;
	std::cout << " #     |          |     |         __________      |   # " << std::endl;
	std::cout << " #      -----------     |        |Water Well|     |   # " << std::endl;
	std::cout << " #                      --------------------------|   # " << std::endl;
	std::cout << " ###################################################### " << std::endl;
	std::cout << "      *      *           *       *      *    *   *      " << std::endl;
	std::cout << "        *         *   Forest   *    *      *       *    " << std::endl;
	std::cout << "                                                        " << std::endl;
}
void game::solution() {
	std::cout << std::endl;
	std::cout << "In order to restore magic and leave the castle you need\n";
	std::cout << "these items in your bag:\n";
	std::cout << "1) Fire of Prometheus\n";
	std::cout << "2) Brisingamen\n";
	std::cout << "3) Torch of Hecate\n";
	std::cout << "4) Bow of Artemis\n";
	std::cout << "and enter the forest by the hidden passageway.\n\n";
}
void game::play() {
	bool escaped = false;
	std::string item = "";
	int time = 0;

	while (!escaped && time < 24) {

		time++;
		std::cout << "The time is " << time << ":00." << std::endl;

		if (player_->location() == forest_) {
			forest_->locked(1);
			forest_->locked(2);
			forest_->locked(3);
			forest_->locked(4);

			if (player_->lastLocation() == hiddenPassage_) {
				if (player_->location()->enter(player_)) {
					std::cout << "You have escaped and restored magic to the land." << std::endl;
					std::cout << "##############################################\n";
					std::cout << "  _______ _    _ ______   ______ _   _ _____  \n";
					std::cout << " |__   __| |  | |  ____| |  ____| \\ | |  __ \\ \n";
					std::cout << "    | |  | |__| | |__    | |__  |  \\| | |  | |\n";
					std::cout << "    | |  |  __  |  __|   |  __| | . ` | |  | |\n";
					std::cout << "    | |  | |  | | |____  | |____| |\\  | |__| |\n";
					std::cout << "    |_|  |_|  |_|______| |______|_| \\_|_____/ \n";
					std::cout << "##############################################\n";
					std::cout << "\n";
					escaped = true;
				}
				else {
					std::cout << "Go back and try again."<< std::endl;
					forest_->open(4);
				}
			}
			else {
				std::cout << "You have been captured" << std::endl;
				if (player_->lastLocation() == dungeon_) {
					forest_->open(1);
				}
				else if (player_->lastLocation() == library_) {
					forest_->open(2);
				}
				else if (player_->lastLocation() == cellar_) {
					forest_->open(3);
				}
			}
			if (!escaped) {
				player_->move();
			}
		}
		else { 
			if (player_->location()->enter(player_)) {
				player_->lookAround();
				player_->lookBag();
				player_->decide();
			}
			player_->move();
		}
	} 
	if (!escaped) {
		std::cout << "Your dummy spell has reach its limit. You have been caught" << std::endl;
		std::cout << "##############################################\n";
		std::cout << "  _______ _    _ ______   ______ _   _ _____  \n";
		std::cout << " |__   __| |  | |  ____| |  ____| \\ | |  __ \\ \n";
		std::cout << "    | |  | |__| | |__    | |__  |  \\| | |  | |\n";
		std::cout << "    | |  |  __  |  __|   |  __| | . ` | |  | |\n";
		std::cout << "    | |  | |  | | |____  | |____| |\\  | |__| |\n";
		std::cout << "    |_|  |_|  |_|______| |______|_| \\_|_____/ \n";
		std::cout << "##############################################\n";
		std::cout << "\n";
	}
}
game::~game() {
	delete cellar_;
	delete courtyard_;
	delete dungeon_;
	delete forest_;
	delete hiddenPassage_;
	delete library_;
	delete player_;
}