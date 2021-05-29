class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //map<int, int> map;
        unordered_set<int> map;
        int size = nums.size();
        int i, j, sum = 0, head;
        int max_sum = 0;
        
        head = 0;
        for (i = 0; i < size; i++) {
            for (j = i; j < size; j++) {
                // Need to remove the the duplicated number
                while (map.find(nums[j]) != map.end()) {
                    sum -= nums[head];
                    map.erase(nums[head]);
                    head++;
                }
                map.insert(nums[j]);
                sum += nums[j];
                max_sum = max(max_sum, sum);
            }
            i = j + 1;
        }
        return max_sum;
    }
};
