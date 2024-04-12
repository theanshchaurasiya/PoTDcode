class Solution {
public:
    int trap(vector<int>& height) {
        // step1
        int tallest = 0;
        int n = height.size();
        for (int i = 1; i < n; i++) {
            if (height[i] > height[tallest]) {
                tallest = i;
            }
        }
        int ans = 0;
        // step2
        for (int i = 0, leftMaxHeight = 0; i < tallest; i++) {
            if (leftMaxHeight < height[i]) {
                leftMaxHeight = height[i];
            } else {
                ans += (leftMaxHeight - height[i]);
            }
        }
        // step 3
        for (int i = n - 1, rightMaxHeight = 0; i > tallest; i--) {
            if (height[i] > rightMaxHeight) {
                rightMaxHeight = height[i];
            } else {
                ans += (rightMaxHeight - height[i]);
            }
        }
        return ans;
    }
};