#include <iostream>
#include <stdlib.h>

void main() {
	int target;
	int guess_state;
	int current = -1;
	int attempts = 0;
	int border_lower = 1;
	int border_upper = 1000;
	int game;

	std::cout << "Enter [1] if you want to guess a number or [2] if you want to pick.\n";
	std::cin >> game;
	std::cout << "\n";

	if (game == 1) {
		std::cout << "Try to guess a number in range from 1 to 1000.\n";
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
		int last_highest = 1000;
		int last_lowest = 0;
		current = 500;
		attempts = 1;
		std::cout << "Pick a number from 1 to 1000 and the program will try to guess it.\n";
		std::cout << "After program's each attempt, enter [1] if the number you've picked is lower, [2] if it's higher, [3] if this is the picked number.\n";
		while (game == 2)
		{
			std::cout << "Is " << current << " the number you've picked?\n";
			std::cout << "Enter: ";
			std::cin >> guess_state;
			std::cout << "\n";
			switch (guess_state)
			{
			case 1: {
				last_highest = current;
				current = (int)((current + last_lowest) / 2);
				attempts++;
				break; }
			case 2: {
				last_lowest = current;
				current = (int)((current + last_highest) / 2);
				attempts++;
				break; }
			case 3: {
				std::cout << "Great! It took me " << attempts << " attempts to guess the number.\n"; game = 0;  break; }
			}
		}
	}

}