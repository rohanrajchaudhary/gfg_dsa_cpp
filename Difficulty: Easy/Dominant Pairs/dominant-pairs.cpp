class Solution {
public:
    int dominantPairs(vector<int> &arr) {

        int n = arr.size();
        int mid = n / 2;

        // Sort first half
        sort(arr.begin(), arr.begin() + mid);

        // Sort second half
        sort(arr.begin() + mid, arr.end());

        int count = 0;
        int right = mid;

        // Traverse first half
        for (int left = 0; left < mid; left++) {

            while (right < n &&
                   1LL * arr[left] >= 5LL * arr[right]) {
                right++;
            }

            count += right - mid;
        }

        return count;
    }
};