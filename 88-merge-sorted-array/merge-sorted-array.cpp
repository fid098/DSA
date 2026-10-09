class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
            given two integer arrays each sorting in ascending order 
            two integers m and n, representing the number of elements in nums1 and nums2

            the final sorted array should not be returned but stored inside array nums1

            [4,5,6,0,0,0] m = 3  [1,2,3] n = 3
                 i              j
            [] 
            
        */
        int i = m - 1;
        int j {};

        if (m == 0){
            nums1[0] = nums2[0];
        }

        while (i >= 0 && j < n){
            if (nums1[i] >= nums2[j]){
                std::swap(nums1[i], nums2[j]);
                i--;
                j++;
            }
            else{
                break;
            }
            
        }

        std::sort(nums1.begin(), nums1.begin() + m);
        std::sort(nums2.begin(), nums2.end());


        int k = m;
        int l = 0;
        while (k < nums1.size() && l < nums2.size()){
            nums1[k] = nums2[l];
            k++;
            l++;
        }
        


    }
};