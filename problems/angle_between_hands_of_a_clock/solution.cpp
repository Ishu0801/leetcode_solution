class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = hour;
        if(hour == 12){
            h = 0.0;
        }
        double tilt = (double(minutes)/60) * 30;
        double h_deg = (h * 30) + tilt;
        double m_deg = minutes * 6;
        double result = m_deg - h_deg;
        if(result < 0.0){
            result = -result;
        }
        if(result > 180.0){
            result = 360.0 - result;
        }
        return result;
    }
};