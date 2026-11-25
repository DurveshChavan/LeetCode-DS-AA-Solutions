class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n {(static_cast<int> (nums.size())) - 1};
        // optimal

        sort(nums.begin(), nums.end());
        int count {0};

        for (int k=n; k > 1; k--)
        {
            int l {0};
            int r {k-1};
            while (l < r)
            {
                if ((nums[l] + nums[r]) > nums[k])
                {
                    count += r - l;
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return count;

    }
};
