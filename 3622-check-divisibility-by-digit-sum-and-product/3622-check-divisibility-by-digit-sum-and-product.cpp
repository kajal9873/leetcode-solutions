class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int temp = n;
        while (temp > 0) {
            int d = temp % 10;
            sum += d;
            product *= d;
            temp /= 10;
        }
        return n % (sum + product) == 0;
    }
};