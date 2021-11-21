class Solution
{
public:
    bool check(int mid, vector<int> &nums, int m)
    {
        int as = 0, p = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > mid)
                return false;

            if (p + nums[i] > mid)
            {
                as++;
                p = nums[i];
            }
            else
                p += nums[i];
        }
        return as < m;
    }
    int splitArray(vector<int> &nums, int m)
    {

        int high = 0, low = 0, ans = -1;
        for (int i : nums)
        {
            low = max(low, i);
            high += i;
        }
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (check(mid, nums, m))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};