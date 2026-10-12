class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v (n , vector<int> (n,0));
        if (n==0) {
            return v;
        }
        int top = 0 , left = 0;
        int down = n-1 , right = n-1;
        int id = 0;
        int a = 1;
        while (top<=down && left<=right) {
            if (id == 0) {
                for (int i=left ; i<=right ;i++){
                    v[top][i]=a++;
                }
                top++;
            }
            if (id == 1) {
                 for (int i=top ; i<=down ;i++){
                    v[i][right]=a++;
                }
                right--;
            }
            if (id == 2) {
                 for (int i=right ; i>=left ;i--){
                    v[down][i]=a++;
                }
                down--;
            }
            if (id == 3) {
                 for (int i=down ; i>=top ;i--){
                    v[i][left]=a++;
                }
                left++;
            }
            id++;
            if (id>3){
                id = 0;
            }
        }
        return v;
    }
};