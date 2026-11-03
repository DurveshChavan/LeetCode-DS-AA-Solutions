class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n {static_cast<int>(nums.size())};

        set<vector<int>> ans;

        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if ((nums[i] + nums[j] + nums[k]) == 0)
                    {
                        vector<int> triple {nums[i], nums[j], nums[k]};

                        sort(triple.begin(), triple.end());

                        ans.insert(triple);
                    }
                }
            }
        }
        return vector<vector<int>> (ans.begin(), ans.end());
    }
};