class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans; 
        vector<unordered_map<char, int>>str_maps;
        for(string str: strs){
            unordered_map<char, int> str_map;
            for(char c: str) str_map[c]++;
            str_maps.push_back(str_map);
        }
        unordered_map<int, bool> picked;
        for(int i=0; i<strs.size(); i++){
            vector<string> group = {strs[i]};
            if(picked.find(i) != picked.end()) continue;
            for(int j=i+1; j<strs.size(); j++){
                if(picked.find(j) != picked.end()) continue;
                if(strs[i].size() != strs[j].size()) continue;
                if(isAnagram(str_maps[i], str_maps[j])){
                    group.push_back(strs[j]);
                    picked[j] = true;
                }
            }
            picked[i] = true;
            ans.push_back(group);
        }

        return ans;
    }
    
    bool isAnagram(unordered_map<char, int> s_map, unordered_map<char, int> t_map){
        if(s_map.size() != t_map.size()) return false;
        for(auto pair: s_map){
            if(pair.second != t_map[pair.first]) return false;
        }
        return true;
    }
};
