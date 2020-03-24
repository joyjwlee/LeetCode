//Kadane's algorithm!
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSumAtIndex = nums[0];
        int maxTillIndex = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxSumAtIndex = max(maxSumAtIndex + nums[i], nums[i]);
            maxTillIndex = max(maxTillIndex, maxSumAtIndex);
        }
        return maxTillIndex;
    }
};