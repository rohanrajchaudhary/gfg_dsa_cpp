class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> left(n), right(n);
        long long total_sum = 0;

        for (int x : arr) {
            total_sum += x;
        }

        // Left se maximum possible height
        left[0] = min(arr[0], 1);
        for (int i = 1; i < n; i++) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }

        // Right se maximum possible height
        right[n - 1] = min(arr[n - 1], 1);
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }

        // Maximum peak height x nikalna
        long long max_peak = 0;
        for (int i = 0; i < n; i++) {
            long long current_peak = min(left[i], right[i]);
            max_peak = max(max_peak, current_peak);
        }

        // Minimum cost = Total sum - sum of elements in max pyramid (x^2)
        return total_sum - (max_peak * max_peak);
    }
};