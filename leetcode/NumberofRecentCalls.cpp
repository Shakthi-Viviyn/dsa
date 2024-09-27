#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);

        int rangeStart = t - 3000;
        while(q.front() < rangeStart){
            q.pop();
        }

        return q.size();
    }
};