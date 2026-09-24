class Solution {
    int bit[1005];

    void update(int idx, int val) {
        for (; idx <= 1000; idx += idx & -idx) {
            bit[idx] = max(bit[idx], val);
        }
    }

    int query(int idx) {
        int max_val = 0;
        for (; idx > 0; idx -= idx & -idx) {
            max_val = max(max_val, bit[idx]);
        }
        return max_val;
    }

  public:
    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();
        vector<pair<int, int>> discs(n);

        for (int i = 0; i < n; i++) {
            discs[i] = {r[i], h[i]};
        }

        // r ascending order me, agar r barabar ho toh h descending order me
        sort(discs.begin(), discs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        // Fenwick tree reset
        for (int i = 0; i <= 1000; i++) {
            bit[i] = 0;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cur_h = discs[i].second;

            // Height strictly smaller chahiye, isliye 1 se (cur_h - 1) tak query karenge
            int prev_max = query(cur_h - 1);
            int cur_total = prev_max + cur_h;

            ans = max(ans, cur_total);
            update(cur_h, cur_total);
        }

        return ans;
    }
};