class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> memo;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return dfs(s, wordSet, 0, memo);
    }

    bool dfs(string s, unordered_set<string>& wordSet, int idx, unordered_map<int,bool>& memo){
        if(memo.count(idx)) return memo[idx];
        if(idx == s.length()) return true; 
        for(int j = idx; j <= s.length(); j++){
            if(wordSet.find(s.substr(idx, j - idx + 1)) != wordSet.end()){
                if(dfs(s, wordSet, j+1 , memo)){
                    memo[idx] = true; 
                    return true; 
                }
            }            
        }
        memo[idx] = false;
        return memo[idx]; 
    }
};
