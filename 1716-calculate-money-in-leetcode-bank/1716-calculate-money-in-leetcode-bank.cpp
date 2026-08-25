class Solution {
public:
    int totalMoney(int n) {
        int pre = 0;
        int sum = 0;
        for (int i=1;i<=(n/7)*7;i++) {
                if  (i%7==1){
                     pre++; 
                } 
                    sum += pre + (i-1)%7;
                
        }
        int q = n%7;
        int addto = 0;
        for (int i=1;i<=q;i++){
            addto += i+pre;
        }
        return (sum+addto);
    }
};