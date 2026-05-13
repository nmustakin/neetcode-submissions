class Solution {
public:
    unordered_map<int, int> memo; 
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0; 
        queue<int> q; 
        set<int> seen; 
        q.push(0);

        int path = 0; 
        while(!q.empty()){
            int size = q.size(); 

            for(int i = 0; i < size; i++){
                int current = q.front();
                q.pop();
                if (seen.contains(current)) continue; 
                for(int coin: coins){
                    if(current + coin == amount){
                        return path+1;
                    }
                    else if(current + coin < amount){
                        q.push(current+coin);
                    }
                    else continue; 
                }
                seen.insert(current);
                
            }
            path++; 
        }

        if(!seen.contains(amount)) return -1; 
        else return path; 
    }
};
