class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int a1 = 0;
        int a2 = 0;
        while(a1 < nums1.size() && a2 < nums2.size())
        {
            if(nums1[a1] == nums2[a2])
                return nums2[a2];
            else if(nums1[a1] < nums2[a2])
                a1 += 1;
            else if(nums1[a1] > nums2[a2])
                a2 += 1;
        }
        return -1;
        
    }
};