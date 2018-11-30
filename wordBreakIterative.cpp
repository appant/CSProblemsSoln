/*
wordBreak: Check if a string can be constructed by concatenating words in a dictionary. 
Input Parameters:
s: String to be checked if it can be formed from words in a dictionary. 
wordDict: list of words
*/

bool wordBreakUtility(string s, unordered_set<string> dictionary){
      int size = s.size();
      bool* flag = (bool*) malloc(sizeof(bool)*(size+1));  
      memset(flag, false, size+1);
      flag[0] = true;
      for(int i=0; i<size; i++){
        if(flag[i]){
            for(int j=i+1; j<=size;j++){
                if(dictionary.find(s.substr(i, j-i))!=dictionary.end())
                    flag[j] = true;
                if(flag[size]==true) // Early return. No need to search further cause we have already found a possibility
                    return true;
            }
        }
      }
      return flag[size];    
  }

  bool wordBreak(string s, vector<string>& wordDict) {
      if(s.empty())
          return true;
      if(wordDict.size()==0)
          return false;
      unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
      return wordBreakUtility(s, dictionary);        
  }
