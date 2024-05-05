#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());
        int numBoats = 0;

        int i = 0;
        int j = people.size() - 1;

        while(i <= j){
            if (people[j] + people[i] <= limit){
                i++;
                j--;
                
            }else{
                j--;
            }
            numBoats++;
        }

        return numBoats;
    }
};