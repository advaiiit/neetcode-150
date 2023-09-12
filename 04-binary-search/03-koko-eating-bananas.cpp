#include<vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1, maxSpeed = *max_element(piles.begin(), piles.end());

        while (minSpeed < maxSpeed) {
            int currSpeed = minSpeed + (maxSpeed - minSpeed) / 2;

            if (areBananasFinished(currSpeed, h, piles)) 
                maxSpeed = currSpeed;
            else 
                minSpeed = currSpeed + 1;
        }
        
        return maxSpeed;
    }

    bool areBananasFinished(int speed, int hours, vector<int> piles) {
        int timeTaken = 0;

        for (double pile : piles) 
            timeTaken += ceil(pile / speed);
        
        return (timeTaken <= hours) ? true : false;
    }
};
// TC: O(N * log(maxElement)) SC: O(1)