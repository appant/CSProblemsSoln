#include <iostream>
#include <string>

using namespace std;

// Nothing special. This is a classic problem to find the longest common subsequence. This implementation
// returns the length of the longest subsequence and the subsequence itself.

/*
int lcss(string str1, string str2, unsigned int index1, unsigned int index2, string& longestCSS);

Input Parameters. 

str1: First string to find common subsequence in. 
str2: Second string to find common subsequence in.
index1: Position of where we are at str1. 
index2: Position of where we are at str2.

Output Parameters.

longestCSS: The longest common subsequence. 
*/

int lcss(string str1, string str2, unsigned int index1, unsigned int index2, string& longestCSS){
  if(index1 >= str1.size() || index2 >= str2.size())
    return 0;
    string lcssFirst = longestCSS;
    string lcssSecond = longestCSS;
	if(str1[index1]==str2[index2]){
	  longestCSS=longestCSS+str1[index1];
		return 1+lcss(str1, str2, index1+1, index2+1, longestCSS);
	}
	else{	    
    int firstLen = lcss(str1, str2, index1+1, index2, lcssFirst);	    
    int secondLen = lcss(str1, str2, index1, index2+1, lcssSecond);
    longestCSS = firstLen > secondLen ? lcssFirst : lcssSecond;
    return max(firstLen, secondLen);		
	}
}
