class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       		vector<int> v;
		int n=nums.size();
		map<int,int> m;
		for(int i=0;i<n;i++)
		{
			if(m.count(target-nums[i]))
			{
				v.push_back(m[target-nums[i]]);
				v.push_back(i);
				return v;
			}
			else
				m[nums[i]]=i;
		}
        return v;        
    }
};