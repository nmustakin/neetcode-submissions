class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        result[0] = 0; 
        int curr = 3; 
        int i; 
        if (n > 0){
            for(i = 1; i<= n; i*=2){
                result[i] = 1;
                if(curr == i) curr++; 
                //cout << curr << endl;
                while(curr < i) {
                    result[curr] = 1 + result[curr - i/2];
                    //cout << curr << endl; 
                    curr++;
                }
            }
            while(curr <= n){
                result[curr] = 1 + result[curr - i/2]; 
                curr++;
            }
        }
        return result; 
    }
};
