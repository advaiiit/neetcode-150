#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int numCars = position.size();
        vector<pair<int, int>> positionAndSpeed;
        stack<float> stack;

        for (int i = 0; i < numCars; i++) 
            positionAndSpeed.push_back({position[i], speed[i]});

        sort(positionAndSpeed.begin(), positionAndSpeed.end());

        for (int i = 0; i < numCars; i++) {
            auto [position, speed] = positionAndSpeed[i];
            float time = (float) (target - position) / speed;
            
            while (!stack.empty() && time >= stack.top()) stack.pop();

            stack.push(time);
        }

        return stack.size();
    }
};
// TC: O(NlogN) SC: O(N)