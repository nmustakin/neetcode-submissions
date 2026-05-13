class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans; 
        unordered_map<string, vector<string>> char_map;
        for(string str: strs){
            vector<int> str_arr(26);
            for(char c: str){
                str_arr[(int)c - int('a')]++;
            }
            stringstream ss;
            for(int i:str_arr) ss << hex << i; 
            string key_str = ss.str();
            cout << key_str << endl; 
            if(char_map.find(key_str) != char_map.end()){
                char_map[key_str].push_back(str);
                cout << str << endl; 
            }
            else{
                vector<string> group = {str};
                char_map[key_str] = group; 
            }
        }
        for(auto pair: char_map){
            ans.push_back(pair.second);
        }
        return ans;
    }
    
};
