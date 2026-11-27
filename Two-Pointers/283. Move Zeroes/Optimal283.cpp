class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Two Pointers
        // optimal

        int slow {0};
        for (int fast; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0 )
            {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }

    }
};