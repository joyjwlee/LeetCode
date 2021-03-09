class Solution {
  public:
    void sortColors(vector<int> &nums) {
        // Dijkstra 3-Way Partition AKA Dutch national flag problem
        // pointers and value of the pivot
        int i = 0, j = 0, k = nums.size() - 1, pivot = 1;

        // loop through entire array
        while (j <= k) {
            // if less than pivot, move to [0, i)
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            // if greater than pivot, move to [k+1, end]
            else if (nums[j] > pivot) {
                swap(nums[j], nums[k]);
                k--;
            }
            // if same, move j
            else {
                j++;
            }
        }
    }
};

/*

invariant: i <= j <= k
ranges:
    [0, i) is less than pivot
    [i, j) is equal to pivot
    [j, k] is unsorted
    [k+1, end] is greater than pivot

*/