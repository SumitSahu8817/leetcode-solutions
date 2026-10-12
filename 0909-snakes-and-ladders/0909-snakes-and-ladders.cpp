class Solution {
public:

    pair<int,int> get(int num , int n) {
        int RT = (num-1)/n;
        int RB = n-1 - RT;
        int col = (num-1)%n;
        if (n%2==0&&RB%2==0||n%2==1&&RB%2==1) {
                col = n-1 - col;
        }
        return make_pair(RB , col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        queue <int> q;
        int n = board.size();
        q.push(1);
        int steps = 0;
        vector<vector<bool>> visited(n , vector<bool> (n,false));
        visited[n-1][0] = true;
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                int top = q.front();
                q.pop();
                if (top == n*n) {
                    return steps;
                }
                for (int i=1;i<=6;i++) {
                    if (top+i>n*n) {
                        break;
                    }
                    int val = top + i;
                    pair <int , int> p = get(top+i,n);
                    int r = p.first;
                    int c = p.second;
                    if (visited[r][c]==true) {
                        continue;
                    }

                    if (board[r][c] == -1) {
                        q.push(top+i);
                    } else {
                        q.push(board[r][c]);
                    }
                        visited[r][c] = true;
                }
            }
            steps++;
        }
        return -1;

    }
};