bool oneEditAway(string word1, string word2){
    if(word1.size() != word2.size())
        return false;
    int editsCount = 0;
    for(int i=0; i<word1.size(); i++){
        if(word1[i] != word2[i]){
            editsCount++;
            if(editsCount > 1)
                return false;                
        }            
    }    
    return true;
}    

int ladderLength(string beginWord, string endWord, vector<string>& wordList) { 
    vector<bool> visited(wordList.size()); //we don't want to go back to the words that we have already visited                                                //to avoid a loop and return wrong value.       
    queue<string> q;
    q.push(beginWord);	
    int minEdit = INT_MAX; //Holds the minimum transformation length from begin word to end word. 
    int currMin = 0;

    while(!q.empty()){ //Loop until queue is not empty. We are using breath first traversal. 			
        int size = q.size();
        while(size>0){
            size--;
            string currWord = q.front();						
            q.pop();
            if(currWord == endWord){ // During the course of finding such path from begin to end word, if end                                            // word is found, return the current min value.
                currMin++;
                minEdit = min(minEdit, currMin);
                return minEdit;				
            }			
            for(int i=0; i<wordList.size(); i++)
            {				
                if(oneEditAway(currWord, wordList[i]) && !visited[i]){
                    q.push(wordList[i]);
                    visited[i] = true;
                }
            }
        }
        currMin++;
    }
    return 0;	
}
    
int main()
{
    vector<string> dict; 
    D.push_back("poon"); 
    D.push_back("plee"); 
    D.push_back("same"); 
    D.push_back("poie"); 
    D.push_back("plie"); 
    D.push_back("poin"); 
    D.push_back("plea"); 
    string start = "toon"; 
    string target = "plea";
    cout << ladderLength(start, target, dict) << endl;
}
