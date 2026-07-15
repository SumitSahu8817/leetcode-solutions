class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = ((2*n)*(2*n+1))/2 -n*(n+1);
        int sumEven = n*(n+1);
        int ans = 1;
        for(int i=2;i<min(sumOdd,sumEven);i++){
            if(sumOdd%i==0&&sumEven%i==0){
                ans=i;
            }
        }
        return ans;
    }
};