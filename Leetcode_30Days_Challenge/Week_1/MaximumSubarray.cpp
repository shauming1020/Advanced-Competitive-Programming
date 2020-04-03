# https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/528/week-1/3285/
# AC

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        A = nums;
        return maxsum(0, nums.size() - 1);
    }

    int maxsum(int l, int r) {
        if (l == r) return A[l];

        int m = (r + l) / 2, sum, centre = A[m];

        sum = 0;
        for (int i = m; i <= r; i++)
            centre = max(centre, sum+=A[i]);

        sum = centre;
        for (int i = m-1; i >= l;i--)
            centre = max(centre, sum+=A[i]);

        return max(centre, max(maxsum(l, m), maxsum(m+1, r)));
    }
private:
    vector<int> A;
};
