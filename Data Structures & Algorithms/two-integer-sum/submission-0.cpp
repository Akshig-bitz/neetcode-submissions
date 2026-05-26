class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> prevMap;
        for(int i=0; i< nums.size(); i++){
            int num = target - nums[i];
            if(prevMap.find(num) != prevMap.end()) return {prevMap[num], i};
            prevMap.insert({nums[i], i});
        }
        return {};
    }
};
