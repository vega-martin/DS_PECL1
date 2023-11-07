#include <random>
using namespace std;

thread_local mt19937 gen(random_device{}());

// This method randomizes a one-digit number:
int randNumber(){
    uniform_int_distribution<int> distribution(0, 9);
    int randomNumber = distribution(gen);
    return randomNumber;
}

// This method randomizes a letter from the English alphabet:
char randLetter(){
	uniform_int_distribution<int> distribution(0, 25);
	int randomIndex = distribution(gen);
	char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char letter = alphabet[randomIndex];
	return letter;
}