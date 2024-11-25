#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());  // Sort the array
    int n = nums.size();

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i];
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates for the second element
                while (left < right && nums[left] == nums[left + 1]) left++;
                // Skip duplicates for the third element
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < target) {
                left++;  // Increase sum
            } else {
                right--;  // Decrease sum
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    vector<vector<int>>k=threeSum(v);

    for(int i=0; i<k.size(); i++)
    {
        for(int j=0; j<k[i].size(); j++)
            cout<<k[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/**

6
-4 0 -1 -1 1 2

*/
