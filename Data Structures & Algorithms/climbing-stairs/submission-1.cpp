class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1; 
        else if(n == 2) return 2;
        else{
            unsigned int sol[2] = {2, 1};
            for(unsigned int i = 3; i <= n; i++){
                sol[i%2] = sol[0] + sol[1]; 
            }
            return sol[n%2]; 
        } 
    }
};
