#include "helperFunctions.h"
#include <cctype>
using namespace std;


string helperFunctions::upperAllString(string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}

	return str;
}

string helperFunctions::lowerAllString(string str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}

	return str;
}