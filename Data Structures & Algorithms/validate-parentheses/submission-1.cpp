class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        for(char c: s){
            if (c == '(' || c == '{' || c == '[') st.push(c); 
            else{
                if(st.empty()) return false; 
                switch(c){
                    case ')':
                        if(st.top() != '(') return false;
                        else st.pop(); 
                        break;
                    case '}':
                        if(st.top() != '{') return false;
                        else st.pop(); 
                        break;
                    case ']':
                        if(st.top() != '[') return false;
                        else st.pop();
                        break; 
                    default:
                        return false; 
                        break; 
                }
            }
        }

        return st.empty(); 
    }
};
