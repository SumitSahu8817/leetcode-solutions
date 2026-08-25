class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int i = 0 , j = 0;
        int n = instructions.size();
        long long score = 0;
       vector<int> v(n,0);
        while (j>=0 && j<n) {
             if(v[j]==1){
                return score;
            }
            v[j]=1;
            if (instructions[j] == "jump") {
                    j = j + values[j];
            } else {
                    score += values[j];
                    j++;
            }
           
            
        }
        return score;
    }
};