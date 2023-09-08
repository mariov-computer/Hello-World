/* The following problem was done in C++ and here is the general prompt:
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order. The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int i = m - 1; // This is the pointer for nums 1
        int j = n - 1; // This is the pointer for nums2
        int k = m + n -1; //This is the pointer for the merged array

        // I must merge nums1 and nums2 in non-decreasing order
        while (i >= 0 && j >= 0){
            if (nums1[i] > nums2[j]){
                nums1[k--] = nums1 [i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

    // If there are remaining elements in nums2, then simply copy them to nums1
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

/* My general thought process: 
1.)initialize three pointers: 'i' pointing to the last element of nums1 (before the zeros), 
'j' pointing to the last element of nums2, and 'k' pointing to the last element of the merged array (nums1).
    
2.) I start from the end of both arrays and compare the elements at nums1[i] and nums2[j]. 
I then put the larger element at nums1[k] and decrement both i and k, or j and k, accordingly.
    
3.) I must continue this process until either i or j becomes less than 0.
    
4.) If there are remaining elements observed in nums2, like if j is greater than or equal to 0, then the code will copy them to the beginning 
of nums1. Ultimately, the algorithm merges the 2 arrays in-place and in non-decreasing order as required
*/
