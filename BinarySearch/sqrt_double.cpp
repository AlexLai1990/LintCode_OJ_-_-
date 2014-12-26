class Solution {
public:
    double sqrt(double x) {
        return sqrtHelper(x, 1);
    }
    
    double sqrtHelper(double x, double g) {
        if (closeEnough(double(x/g), g) )
            return g;
        else
            return sqrtHelper(x, betterGuess(x, g)); 
    }
    
    bool closeEnough(double a, double b) {
        return (abs(a - b) < 0.000001);
    }
        
    double betterGuess(double x, double g) {
        return ((g + x/g) / 2);
    }
};