#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        std::multiset<int> mNumSet;

        mNumSet.insert(std::begin(nums1), std::end(nums1));
        mNumSet.insert(std::begin(nums2), std::end(nums2));

        auto middleIter = mNumSet.begin();
        std::advance(middleIter, std::distance(mNumSet.begin(), mNumSet.end()) / 2);

        if (mNumSet.size() % 2 == 0){
            double num1 = *(middleIter);
            middleIter--;
            double num2 = *(middleIter);
            double average = (num1 + num2) / 2;
            return average;
        }else{
            return (*middleIter);
        }
        
    }
};