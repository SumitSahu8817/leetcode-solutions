class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n<=8){
                return word.length();
        }
        else if(n>8&&n<16){
            return  8 + (n%8)*2;
        }
        else if(n>=16&&n<24){
            return 8 + 8*2 + (n%8)*3;
        }else{
            return 8 + 8*2 + 8*3 + (n%8)*4;
        }
        return 0;
    }
};