#include "has.h"

int main() {
	dictionary *D = new dictionary;
	newDictionary(D);
	cout << endl;
	showPerformance(D);
	cout << endl;
	cout << endl;
	string s = "I want to be a doctor";
	cout << s << ": ";
	if (isCorrect(s, D))
		cout << "Is correct" << endl;
	else
		cout << "Is'nt correct" << endl;
	return 0;
}