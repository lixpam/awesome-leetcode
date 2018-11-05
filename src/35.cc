static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int binarySearch(vector<int>& nums, int i, int j, int target) {
        if (i == j) {
            return target <= nums[i] ? i : i+1;
        } else if (i > j) {
            return j+1;
        }
        
        int mid = (i + j)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) {
            return binarySearch(nums, mid+1, j, target);
        } else {
            return binarySearch(nums, i, mid-1, target);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};
