#include "../tools/luban.h"
using namespace std;

static const int _=[](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if (trips.size() == 0) return true;
        vector<vector<int>> sp;
        for (auto &iter : trips) {
            sp.emplace_back(std::move(vector<int>{iter[1], 1, iter[0]}));
            sp.emplace_back(std::move(vector<int>{iter[2], -1, iter[0]}));
        }

        sort(sp.begin(), sp.end(), [](const vector<int>& lh, const vector<int>& rh){
            if (lh[0] != rh[0])
                return lh[0] < rh[0];
            else
                return lh[1] < rh[1];
        });

        int sum = 0;
        for (auto &iter : sp) {
            sum += iter[1] * iter[2];
            if (sum > capacity) return false;
        }
        return sum <= capacity;
    }
};

int main()  {
    Solution s;
    vector<vector<int>> trips;
    // [[2,1,5], [3,3,7]] 4 false
    //trips.emplace_back(std::move(vector<int>{2,1,5}));
    //trips.emplace_back(std::move(vector<int>{3,3,7}));

    // [[2,1,5],[3,3,7]] 5 true
    //trips.emplace_back(std::move(vector<int>{2,1,5}));
    //trips.emplace_back(std::move(vector<int>{3,3,7}));
    
    // [[2,1,5],[3,5,7]] 3 true
    //trips.emplace_back(std::move(vector<int>{2,1,5}));
    //trips.emplace_back(std::move(vector<int>{3,5,7}));

    // [[3,2,7],[3,7,9],[8,3,9]] 11 true
    trips.emplace_back(std::move(vector<int>{3,2,7}));
    trips.emplace_back(std::move(vector<int>{3,7,9}));
    trips.emplace_back(std::move(vector<int>{8,3,9}));
    cout << s.carPooling(trips, 11) << endl;

}
