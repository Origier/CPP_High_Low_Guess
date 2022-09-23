// High Low Guessing Game
// By: Aaron McDonald
// This game generates a random number between 1 - 100 that the user must guess to try to get right
// On a failed guess the game will generate a response such as, too high or too low depandent on 
// how close the guess was to the number. A correct guess wins the game

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

const int MAX_NUMBER_OF_GUESSES = 5;
const int MAX_NUMBER = 100;
const int MIN_NUMBER = 1;

// Allows the user to input a single character that is within the allowed range
char get_char(const string valid_chars) {
	string user_in;
	int length; // size of the user_in
	while (true) {
		cin >> user_in;
		length = user_in.size();
		if (length > 1) {
			cout << "Please just enter 1 character: ";
		}
		else {
			break;
		}
	}
	return user_in[0];
}

// Allows the user to input a guess, validates the inputed data
int get_guess(const string valid_chars) {
	cout << "Please make a guess between " << MIN_NUMBER << " - " << MAX_NUMBER << ": ";
	string user_in;
	int length; // size of the user in string
	bool all_num_flag;
	int user_num;
	// Infinite loop to help ensure the correct data is gathered
	while (true) {
		cin >> user_in;
		length = user_in.size();
		all_num_flag = true;

		// Checking to ensure each character of the string is part of the valid set
		for (int i = 0; i < length; i++) {
			if (valid_chars.find(user_in[i]) == string::npos) {
				cout << "Please only enter interger numbers, no decimals, no characters: ";
				all_num_flag = false;
				break;
			}
		}

		// Returns the integer converstion of the number if the number is valid
		if (all_num_flag) {
			user_num = stoi(user_in);
			// Ensuring the number is within the range provided
			if (user_num > MAX_NUMBER || user_num < MIN_NUMBER) {
				cout << "Please enter a number between the range provided (" << MIN_NUMBER << "-" << MAX_NUMBER << "): ";
			}
			else {
				return user_num;
			}
		}
	}
}

int main() {
	int rand_num;
	int user_guess;
	int user_guesses_made;
	char user_input;
	int num_range = MAX_NUMBER - (MIN_NUMBER - 1); // Calculates the range size for the random number
	// Infinite game loop to allow as many plays as desired
	while (true) {
		user_guesses_made = 0;
		rand_num = rand() % num_range + MIN_NUMBER; // Ensures that the random number is between the two constants set above

		// Infinite loop to get guesses, breaks when the user has maxed out the number of guesses they have
		while (true) {
			user_guess = get_guess("0123456789");
			user_guesses_made++;
			if (user_guess == rand_num) {
				cout << "That's correct!! You Win!!!!!" << endl;
				break;
			}
			else if (user_guess < rand_num) {
				cout << "Too low... you have : " << MAX_NUMBER_OF_GUESSES - user_guesses_made << " guesses remaining." << endl;
			}
			else {
				cout << "Too high... you have : " << MAX_NUMBER_OF_GUESSES - user_guesses_made << " guesses remaining." << endl;
			}

			if (user_guesses_made >= MAX_NUMBER_OF_GUESSES) {
				cout << "Sorry you have no more guesses available, the correct number was: " << rand_num << endl;
				break;
			}
		}

		cout << "Would you like to continue?(y/n): ";
		user_input = get_char("yn");
		if (user_input == 'y') {
			continue;
		}
		else {
			break;
		}
	}

	return 0;
}