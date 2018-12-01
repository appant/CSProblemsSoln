#include "priv.h"

bool wordBreak(string s, vector<string>& wordDict);
bool wordBreakRecursive(string s, vector<string>& wordDict);


void buildDictionary(string filePath, vector<string>& dict){	
	ifstream is(filePath);
	string word;	
	while (getline(is, word) && !is.eof()) {			
			word = word.substr(0, word.size()-1);			
			dict.push_back(word);			
	}
	is.close();	
}

