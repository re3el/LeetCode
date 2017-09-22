class Solution {
public:
    int count = 0;
    unordered_map<string,string>hashT;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        ++count;        
        string shortUrl = "http://tinyurl.com/"+ to_string(count);                
        hashT[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        if (hashT.find(shortUrl) != hashT.end())
            return hashT[shortUrl];
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));