#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, std::greater<int>> pq;
    unordered_set<int> s;

    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++){
            pq.push(i);
            s.insert(i);
        }
    }
    
    int popSmallest(){
        int smallest = pq.top();
        s.erase(smallest);
        pq.pop();
        return smallest;
    }
    
    void addBack(int num) {
        if (s.find(num) == s.end()){
            s.insert(num);
            pq.push(num);
        }
    }
};