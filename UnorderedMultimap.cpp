// extract values having the same key 
unordered_multimap<int,int> hashT;
auto range = hashT.equal_range(key);
for (auto it=range.first; it != range.second; it++)
{      
	int val = it->second;
	if (abs(i - val) <= k)
		return true;                    
}               