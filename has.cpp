#include "has.h"

string tolowerString(const std::string& str) {
	string result = str;
	for (char& ch : result) {
		ch = tolower(ch);
	}
	return result;
}

size_t getIdx(string key) {
	size_t h = 5381;
	for (char c : key)
		h = h * 33 ^ c;
	return h % CAPACITY;
}

void newDictionary(dictionary*& d) {
	ifstream file("words.data");
	string line;
	if (!file.is_open()) {
		cerr << "Can't open file!" << std::endl;
		return;
	}

	if (!d)
		d = new dictionary;

	cout << "Creating table..." << endl;
	while (getline(file, line)) {
		string word = tolowerString(line);
		size_t idx = getIdx(word);
		node* p = new node;
		p->data = word;
		if (d->m[idx])
			p->next = d->m[idx];
		d->m[idx] = p;
	}

	cout << "The table has been created!" << endl;
}

void showPerformance(dictionary* t) {
	if (!t)
		return;
	int max = 0;
	int emp = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		int s = 0;
		node* temp = t->m[i];
		while (temp) {
			s++;
			temp = temp->next;
		}
		if (s > max)
			max = s;
		if (s == 0)
			emp++;
	}
	cout << "Total number of elements: " << TOTAL_WORDS << endl;
	cout << "Total capacity: " << CAPACITY << endl;
	cout << "Max nr of elements with one index: " << max << endl;
	cout << "Unused indexes: " << emp << endl;
	cout << (CAPACITY - emp + 0.0f) / (CAPACITY) * 100 << "% of table is used" << endl;
}

bool isCorrect(string s, dictionary *d) {
	bool b;
	stringstream ss(s);
	string word;
	while (ss >> word) {
		b = 0;
		word = tolowerString(word);
		//cout << word << endl;
		size_t idx = getIdx(word);
		node* temp = d->m[idx];
		while (temp) {
			//cout << temp->data << " ";
			if (word == temp->data) {
				b = 1;
				break;
			}
			temp = temp->next;
		}
		//cout << endl;
		if (b == 0)
			return 0;
	}
	return 1;
}