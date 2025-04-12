#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

const size_t TOTAL_WORDS = 466550;
const size_t CAPACITY = 466553; // cel mai optim numar care am reusit sa-l aleg

using namespace std;

struct node {
	string data = {};
	node* next = 0;
};

struct dictionary{
	node* m[CAPACITY] = {};
};

size_t getIdx(string); // djb2a
void newDictionary(dictionary*&);

void showPerformance(dictionary*);

string tolowerString(const std::string&);
bool isCorrect(string, dictionary*);