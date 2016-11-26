//Test game

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;



int main() {
	int NUMBER_OF_ROUNDS = 3;

	vector<string> wordList;

	ifstream infile;
	infile.open("file.dat", ios::in);

	//Reads a file of words into a wordList
	char wordReader[100];
	infile.getline(wordReader,100);
	while(wordReader[0] != '\0' && !infile.eof()) {
		infile.getline(wordReader, 100);
		infile.peek();
		wordList.push_back(wordReader);
	}

	//Chooses a random word from the wordList
	srand( time(NULL) );
	int randomWord = rand() % wordList.size();
	string word = wordList.at(randomWord);

	cout << word << endl;
	cout << "It is a " << word.length() << " letter word." << endl;


	//Start the rounds of guessing
	bool correctGuess = false;
	for(int rounds = 0; rounds < NUMBER_OF_ROUNDS && !correctGuess; rounds++) {

		cout << "Please enter a character as your guess" << endl;

		//Accepts a single char for the users guess
		string userGuess;
		getline(cin, userGuess);

		int bulls = 0;
		int cows = 0;
		vector <bool>matches;
		matches.resize(word.length());
		for(int i = 0; i < matches.size(); i++) {
			matches.at(i) = false;
		}

		//Count Bulls (letters in exact place) and Cows (right letters, wrong place)
		for(unsigned int it = 0; it < userGuess.length(); it++) {
			for(unsigned int i = 0; i < word.length(); i++) {
				if(word.at(i) == userGuess.at(it) && !matches.at(i)) {
					matches.at(i) = true;
					if(i == it) {
						bulls++;
					} else {
						cows++;

					}
					//cout << "it: " << it << userGuess.at(it) << " at: " << i << endl;
				}
			}
		}

		//Show results
		cout << "Cows: " << cows << endl;
		cout << "Bulls: " << bulls << endl;
		if(word == userGuess) {
			correctGuess = true;
			cout << "Congrats, you were 100% correct. Winner!" << endl;
		}
	}


	//Clean up
	infile.close();

	return 0;
}
