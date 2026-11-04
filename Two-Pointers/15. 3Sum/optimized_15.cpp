#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono> // Required for measuring time

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n {static_cast<int>(nums.size())};
        set<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            int left {i + 1};
            int right {n - 1};
            while (left < right)
            {
                int sum {nums[i] + nums[left] + nums[right]};
                if (sum == 0)
                {
                    vector<int> triplete({nums[i], nums[left], nums[right]});
                    sort(triplete.begin(), triplete.end());

                    ans.insert(triplete);
                    left++;
                    right--;
                    
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return vector<vector<int>> (ans.begin(), ans.end());
    }
};

void runTestCase(int testNumber, Solution& sol, vector<int>& nums) {
    cout << "--- Test Case " << testNumber << " ---" << endl;
    cout << "Input size: " << nums.size() << " elements" << endl;

    // 1. Capture start time
    auto start = chrono::high_resolution_clock::now();

    // 2. Execute the function
    vector<vector<int>> result = sol.threeSum(nums);

    // 3. Capture end time
    auto end = chrono::high_resolution_clock::now();

    // 4. Calculate total duration in milliseconds
    chrono::duration<double, milli> elapsed = end - start;

    // Print the results and time taken
    cout << "Result: [ ";
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i] << (i + 1 < triplet.size() ? "," : "");
        }
        cout << "] ";
    }
    cout << "]" << endl;
    cout << "Execution Time: " << elapsed.count() << " ms\n\n";
}

int main() {
    Solution sol;

    // Define all 3 test cases
    vector<int> test1 = {-1, 0, 1, 2, -1, -4};
    vector<int> test2 = {0, 1, 1};
    vector<int> test3 = {0, 0, 0};

    // Run each test case through the timer function
    runTestCase(1, sol, test1);
    runTestCase(2, sol, test2);
    runTestCase(3, sol, test3);

    return 0;
}
