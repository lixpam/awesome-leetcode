#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* binary search O(NlogM)
class Solution {
public:
    bool search(vector<int>& num, int left, int right, int v) {
        if (left > right) return false;
        if (left == right && num[left] == v) return true;

        int index = left;
        for (int i = index; i <= right; ++i) {
            if (num[i] < v) {
                int tmp = num[index];
                num[index] = num[i];
                num[i] = tmp;
                index++;
            }
        }

        if (num[index] == v) {
            return true;
        } 

        return search(num, index+1, right, v);
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if (len1 == 0 || len2 == 0) return vector<int>{};

        unordered_set<int> ret;
        for (int i = 0; i < len2; ++i) {
            if (search(nums1, 0, len1-1, nums2[i])) {
                ret.insert(nums2[i]);
            }
        }

        return vector<int>(ret.begin(), ret.end());
    }
};
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1;
        for (auto &n : nums1) {
            n1.insert(n);
        }
        unordered_set<int> ret;
        for (auto &n : nums2) {
            if (n1.find(n) != n1.end()) {
                ret.insert(n);
            }
        }
        return vector<int>(ret.begin(), ret.end());
    }
};

int main()
{
    vector<int> arg1{54,93,21,73,84,60,18,62,59,89,83,89,25,39,41,55,78,27,65,82,94,61,12,38,76,5,35,6,51,48,61,0,47,60,84,9,13,28,38,21,55,37,4,67,64,86,45,33,41};
    vector<int> arg2{17,17,87,98,18,53,2,69,74,73,20,85,59,89,84,91,84,34,44,48,20,42,68,84,8,54,66,62,69,52,67,27,87,49,92,14,92,53,22,90,60,14,8,71,0,61,94,1,22,84,10,55,55,60,98,76,27,35,84,28,4,2,9,44,86,12,17,89,35,68,17,41,21,65,59,86,42,53,0,33,80,20};

    Solution s;
    vector<int> ret = s.intersection(arg1, arg2);
    for (auto &i : ret) {
         cout << i << " ";
    }
    cout << endl;
}
