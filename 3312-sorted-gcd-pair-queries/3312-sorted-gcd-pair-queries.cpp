class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(),nums.end());
        vector<int> frequency(mx+1);
        for(int x : nums){
            frequency[x]++;
        }
        vector<long long> divisible(mx+1);
        for (int i=1;i<=mx;i++){
            for (int j=i;j<=mx;j+=i)
                divisible[i] +=frequency[j];
        }
        vector<long long> arr(mx+1);
        for (int i=mx;i>=1;i--){
            arr[i] = divisible[i]*(divisible[i]-1)/2;
            for (int j=2*i; j<=mx;j+=i)
                arr[i]-=arr[j];
        }
        vector<long long> brr(mx+1);
        for (int d=1;d<=mx;d++)
            brr[d] = brr[d-1]+arr[d];
        vector<int> ans;
        for(long long q:queries){
            ans.push_back(lower_bound(brr.begin(),brr.end(),q + 1)-brr.begin());
        }
        return ans;
    }
};