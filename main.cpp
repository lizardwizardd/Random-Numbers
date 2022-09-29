#include <iostream>
#include <stdlib.h>

void main() {
	int target;
	int current = -1;
	int attempts = 0;
	int border_lower = 1;
	int border_upper = 1000;
	int game;

	std::cout << "Enter 1 if you want to guess a number or 2 if you want to pick.\n";
	std::cin >> game;
	std::cout << "\n";

	if (game == 1) {
		std::cout << "Guess a number in range from 1 to 1000.\n";
		srand( time(0) );
		target = ( 1 +  rand() ) % 1001;

		while (current != target)
		{
			attempts++;
			std::cout << "Enter a number: ";
			std::cin >> current;
			std::cout << "\n";

			if (current > target) { 
				if (current > 1000) { std::cout << "This number is out of range. "; }
				std::cout << "Try a lower number.\n"; }
			else {
				if (current < target) {
					if (current < 1) { std::cout << "This number is out of range. "; }
					std::cout << "Try a higher number.\n"; }
				else {
					std::cout << "You guessed the number correctly!\nIt took you " << attempts << " attempts.\n"; }
			}
		}
	}


	if (game == 2) {
		std :: cout << "Pick a number from 0 to 1000 and "
	}

}