#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int l = left;
        int right = height.size() - 1;
        int r = right;

        int largestArea = 0;
        
        while (l < r){
            int currArea = (r - l) * std::min(height[l], height[r]);
            if (currArea > largestArea){
                left = l;
                right = r;
                largestArea = currArea;
            }
            if (height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        
        return largestArea;
    }
};