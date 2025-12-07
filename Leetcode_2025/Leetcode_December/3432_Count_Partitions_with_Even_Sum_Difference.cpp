class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long  leftSum=0,rightSum=0;
        long long  total = 0;
        for(int x:nums)
        {
            total+=x;
        }
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            leftSum+=nums[i];
            rightSum=total-leftSum;
            if(abs(rightSum-leftSum)%2==0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};