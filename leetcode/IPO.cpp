#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitHeap;
        int i = 0;

        while (k > 0) {

            while (i < projects.size() && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                i++;
            }

            if (maxProfitHeap.empty()) break;

            w += maxProfitHeap.top();
            maxProfitHeap.pop();
            k--;
        }

        return w;
    }
};
