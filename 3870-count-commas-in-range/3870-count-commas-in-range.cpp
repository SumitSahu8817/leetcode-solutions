class Solution {
public:
    int countCommas(int n) {
        int ans=0;
        int base=1000;
        while(n>=base){
            ans+=n-1000+1;
            base=base*1000;
            
        }
        return ans;
    }
};