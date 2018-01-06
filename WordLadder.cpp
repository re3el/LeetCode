class Solution {
public:
    void addNextWords(string beginWord, unordered_set<string>& wordDict, queue<string>& toVisit)
    {
        wordDict.erase(beginWord);
        for(int i=0; i<beginWord.size(); i++)
        {
            char letter = beginWord[i];
            for(int j=0; j<26; j++)
            {
                beginWord[i] = 'a'+j;
                if(wordDict.find(beginWord) != wordDict.end())
                    toVisit.push(beginWord);
            }
            beginWord[i] = letter;
        }
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> wordDict(wordList.begin(),wordList.end());
        queue<string> toVisit;
        //for(auto i:wordList) wordDict.insert(i);        
        wordList.push_back(beginWord);
        addNextWords(beginWord,wordDict,toVisit);
        
        int dist = 2;        
        while(toVisit.size() != 0)
        {
            int n = toVisit.size();
            for(int i=0; i<n; i++)
            {                
                string check = toVisit.front();
                toVisit.pop();
                if(check == endWord) return dist;
                addNextWords(check,wordDict,toVisit);
            }
            dist++;
        }
        return 0;
    }
};