class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sum1 = 0;
        int sum2 = 0;

        int i = 1;
        int count = 0;

        while (count < n) {
            if (i % 2 != 0) {
                sum1 += i;
                count++;
            }
            i++;
        }

        i = 1;
        count = 0;

        while (count < n) {
            if (i % 2 == 0) {
                sum2 += i;
                count++;
            }
            i++;
        }

        return __gcd(sum1, sum2);
    }
};