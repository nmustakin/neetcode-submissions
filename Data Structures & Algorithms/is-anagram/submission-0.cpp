class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map, t_map;
        for(char c: s) s_map[c]++;
        for(char c: t) t_map[c]++; 

        if (s_map.size() != t_map.size()) return false;
        for(auto pair: s_map){
            if(t_map[pair.first] != pair.second) return false;
        }
        return true; 
    }
};
