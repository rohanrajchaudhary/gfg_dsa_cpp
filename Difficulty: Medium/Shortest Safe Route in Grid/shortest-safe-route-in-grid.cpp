class Solution {
public:
    int shortestPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> safe(n, vector<bool>(m, true));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Mark landmines and their adjacent cells as unsafe
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    safe[i][j] = false;

                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < m) {
                            safe[ni][nj] = false;
                        }
                    }
                }
            }
        }

        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Start from safe cells in first column
        for (int i = 0; i < n; i++) {
            if (safe[i][0]) {
                q.push({{i, 0}, 0});
                visited[i][0] = true;
            }
        }

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int x = current.first.first;
            int y = current.first.second;
            int dist = current.second;

            // Reached last column
            if (y == m - 1) {
                return dist + 1;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < m &&
                    safe[nx][ny] &&
                    !visited[nx][ny]) {

                    visited[nx][ny] = true;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }

        return -1;
    }
};