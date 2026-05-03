class Solution {
public:
    int rev(int x) {
        int y = 0;
        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }

    int sumOfPrimesInRange(int n) {
       

        int r = rev(n);
        int l = min(n, r);
        int h = max(n, r);

        vector<bool> p(h + 1, true);
        if (h >= 0) p[0] = false;
        if (h >= 1) p[1] = false;

        for (int i = 2; i * i <= h; i++) {
            if (p[i]) {
                for (int j = i * i; j <= h; j += i) {
                    p[j] = false;
                }
            }
        }

        int s = 0;
        for (int i = l; i <= h; i++) {
            if (p[i]) s += i;
        }

        return s;
    }
};