class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask; 
        
        for (auto& res : reservedSeats) {
            int row = res[0];
            int seat = res[1];
            if (seat >= 2 && seat <= 9) {
                rowMask[row] |= (1 << (seat - 2)); 
            }
        }
        
        const int LEFT   = 0b00001111; 
        const int MIDDLE = 0b00111100; 
        const int RIGHT  = 0b11110000; 
        
        long long count = 2LL * (n - (long long)rowMask.size());
        
        for (auto& [row, mask] : rowMask) {
            if ((mask & LEFT) == 0) {
                count++;
                if ((mask & RIGHT) == 0) {
                    count++;
                }
            } else if ((mask & MIDDLE) == 0) {
                count++;
            } else if ((mask & RIGHT) == 0) {
                count++;
            }
        }
        
        return (int)count;
    }
};