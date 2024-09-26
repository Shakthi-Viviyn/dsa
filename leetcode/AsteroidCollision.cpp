#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
                if (stack.back() < -asteroid) {
                    stack.pop_back();
                } else if (stack.back() == -asteroid) {
                    stack.pop_back();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                stack.push_back(asteroid);
            }
        }

        return stack;
    }
};
