class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1, x = 0;
        while (x <= j)
        {
            if (nums[x] == 0)
            { // Meet a 0? Send it back !
                swap(nums[x++], nums[i++]);
            }
            else if (nums[x] == 2)
            {                             // Meet a 2? Send it forward, but don't move forward yourself,
                swap(nums[j--], nums[x]); // You might have just swapped a two with a 0.
            }
            else
            {        // In that case, you'd need to swap it back. If I wrote nums[x++], I would have missed it!
                x++; // Keep walking, x.
            }
        }
        return;
    }
};