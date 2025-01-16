#define IN_BOUND(x, y, grid)                                                   \
    x >= 0 && y >= 0 && x < int(grid.size()) && y < int(grid[0].size())
#define pii pair<int, int>;
// 4 directions
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// 8 directions
int dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dyy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
