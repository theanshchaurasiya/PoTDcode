class Solution {
public:
    int pivotInteger(int n) {
        int square = (n * (n + 1)) / 2;
        int temp = sqrt(square);
        if (temp * temp == square) {
            return temp;
        } else
            return -1;
    }
};