//Test game

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

int sizeCharArray (char myArray[]) {
	char* chrPtr = &myArray[0];

	int count = 0;
	while (*chrPtr != NULL) {
		count++;
		chrPtr++;
	}

	return count;
}


int main() {

	char word[100];
	vector<pair<string,int> > wordList;

	ifstream infile;
	infile.open("file.dat", ios::in);

	infile.getline(word,100);
	while(word[0] != '\0' && !infile.eof()) {
		infile.getline(word, 100);
		infile.peek();
		wordList.push_back(make_pair(word, sizeCharArray(word)));
	}

	srand( time(NULL) );
	int randomWord = rand() % wordList.size();
	cout << randomWord << " " << wordList.size();
	cout << "Your random word is: " << wordList.at(randomWord).first << ", which is length of: " << wordList.at(randomWord).second << endl;

	//Clean up
	infile.close();

	return 0;
}
