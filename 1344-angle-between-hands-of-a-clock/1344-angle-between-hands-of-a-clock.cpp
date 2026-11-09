class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double hr = (hour%12) * 5 + minutes/12.0 ;
        double dif = abs(hr - minutes) ;
        return min(dif*6 , 360.0 - dif*6); 

        
      
    }
};