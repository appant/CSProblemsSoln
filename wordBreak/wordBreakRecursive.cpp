#include "priv.h"

bool wordBreakUtility(string s, unordered_set<string> dictionary){
    if(dictionary.find(s)!=dictionary.end())
        return true;
    for(int i=1;i<=s.size(); i++){
        //We can't return the result from any one of the branch. Only if it succeeds should we return true. Else
        //We have to check each branches and if they all fail, we break out and then return false;
        if(dictionary.find(s.substr(0,i))!=dictionary.end() && wordBreakUtility(s.substr(i),dictionary))
            return true;
    }
    return false;
}

bool wordBreakRecursive(string s, vector<string>& wordDict) {
    if(s.empty())
        return true;
    if(wordDict.size()==0)
        return false;
    unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
    return wordBreakUtility(s, dictionary);        
}
