class Solution {
public:
    bool isPalindrome(string s) {
        char* front = &s[0];
        char* back = &(s.back());

        while(front != back){
            if(!isalnum(*front)){
                front++;
                //cout << "Skipping non alnum from front" << endl; 
                continue; 
            }
            else if(!isalnum(*back)){
                back--;
                //cout << "Skipping non alnum from back" << endl; 
                continue;
            }
            else if(tolower(*front) == tolower(*back)){
                //cout << "Match" << endl; 
                front++;
                if(front == back) return true;
                back--;
            }
            else{
                //cout << *front << "\t" << *back << endl; 
                return false;
            }
        }
        return true;
    }
};
