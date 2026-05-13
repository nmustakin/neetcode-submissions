class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0; 
        unsigned int mask = 1; 
        for(unsigned int i = 0; i < 32; i++){
            if( n & mask) count++; 
            n = n >> 1;
        }

        return count; 
    }
};
