class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;
        int sum = 0;
        int mask = 0xFFFFFFFF;
        for(int i = 0; i < 32; i++){
            int lsb_a = (a>>i) & 1; 
            int lsb_b = (b>>i) & 1; 
            int lsb = lsb_a ^ lsb_b ^ c; 
            c = (lsb_a + lsb_b + c) >= 2? 1: 0;
            if(lsb) sum |= 1 << i; 
        }
        if(sum > 0x7FFFFFFF) sum = ~(sum ^ mask); 
        return sum; 
    }
};
