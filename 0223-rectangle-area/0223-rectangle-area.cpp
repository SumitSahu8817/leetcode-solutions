class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int l1 = abs(ax1-ax2);
        int b1 = abs(ay1-ay2);
        int l2 = abs(bx1-bx2);
        int b2 = abs(by1-by2);
        int A = l1*b1+l2*b2;
        int stx = max (ax1 , bx1);
        int endx = min (ax2 , bx2);
        int l =  (-stx + endx);
        int sty = max (ay1 , by1);
        int endy = min (ay2 , by2);
        int b = (-sty + endy);
        int ans = A;
        if (l>0 && b>0)
         ans = A - l*b;

    return ans;
    }
};