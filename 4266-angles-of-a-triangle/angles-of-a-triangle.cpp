class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0], b = sides[1], c = sides[2];
        
        // Step 1: Check triangle validity
        if (a + b <= c || b + c <= a || c + a <= b) {
            return {};
        }
        
        // Step 2: Compute angles using Law of Cosines
        auto getAngle = [](double x, double y, double z) {
            double cosA = (y*y + z*z - x*x) / (2*y*z);
            
            // Clamp to avoid precision issues
            cosA = max(-1.0, min(1.0, cosA));
            
            return acos(cosA) * 180.0 / M_PI;
        };
        
        double A = getAngle(a, b, c);
        double B = getAngle(b, a, c);
        double C = getAngle(c, a, b);
        
        vector<double> angles = {A, B, C};
        
        // Step 3: Sort
        sort(angles.begin(), angles.end());
        
        return angles;
    }
};