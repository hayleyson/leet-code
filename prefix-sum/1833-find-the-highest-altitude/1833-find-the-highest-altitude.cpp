class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0;
        int alt = 0;
        for (const int& g: gain){
            alt += g;
            if (alt > maxAlt) maxAlt = alt;
        }
        return maxAlt;
    }
};