class Solution {
public:
    int tribonacci(int n) {

        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int last = 1, secondLast = 1, thirdLast = 0;
        int current;
        for (int i = 3; i <= n; i++) {
            current = last + secondLast + thirdLast;
            thirdLast = secondLast;
            secondLast = last;
            last = current;
        }
        return current;
    }
};