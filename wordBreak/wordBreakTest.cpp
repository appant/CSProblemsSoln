#include "wordBreak.h"
#include "priv.h"

#include <time.h>

int main(){	
	vector<string> dictionary;
	buildDictionary("wordsforproblem.txt", dictionary);
	clock_t t = clock();	
	wordBreakRecursive("militaristically", dictionary);
	cout << "Recursive cost: " << ((float)(clock() - t))/CLOCKS_PER_SEC << " secs." << endl;
	t = clock();
	wordBreak("militaristically", dictionary);	
	cout << "Iterative cost: " << ((float)(clock() - t))/CLOCKS_PER_SEC << " secs." << endl;
	return 0;	
}

