class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector <int> nums3;
        for(int i=0;i<size2;i++){
            int d = nums2[i];
            nums1.push_back(d);
        }

        sort(nums1.begin(),nums1.end());
        if(nums1.size()%2!=0){
            return nums1[(nums1.size())/2.0];
        }
        else{
            int size = nums1.size();
            return (nums1[size/2.0]+nums1[(size/2.0)-1])/2.0;
        }
    }
};