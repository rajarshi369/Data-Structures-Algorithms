#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums, int low, int high)
{
    while (low != high)
    {
        int mid = (high + low) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
            return nums[mid];
        if (nums[mid] == nums[mid - 1])
        {
            if ((mid - 1 - low) % 2 == 0)
                low = mid + 1;
            else
                high = mid - 2;
        }
        else
        {
            if ((high - mid) % 2 == 0)
                low = mid + 2;
            else
                high = mid - 1;
        }
    }
    return nums[low];
}

int singleNonDuplicate(vector<int> &nums)
{
    return singleNonDuplicate(nums, 0, nums.size() - 1);
}

int main()
{
    int n, input;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        arr.push_back(input);
    }
    cout << singleNonDuplicate(arr);
    return 0;
}