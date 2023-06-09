#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 20;

int n;                // số đỉnh của đồ thị
int dist[MAXN][MAXN]; // ma trận khoảng cách giữa các đỉnh
int path[MAXN];       // lưu trữ đường đi tìm được
bool visited[MAXN];   // đánh dấu các đỉnh đã ghé thăm

void greedy_algorithm(int start)
{
    memset(visited, false, sizeof(visited)); // khởi tạo tất cả các đỉnh chưa được ghé thăm
    visited[start] = true;                   // đánh dấu điểm xuất phát đã được ghé thăm
    path[0] = start;                         // điểm xuất phát là điểm đầu tiên trong đường đi
    for (int i = 1; i < n; i++)
    {                                       // lặp lại cho tất cả các đỉnh
        int u = path[i - 1];                // lấy đỉnh hiện tại là đỉnh cuối cùng trong đường đi
        int min_dist = INT_MAX, min_v = -1; // tìm đỉnh tiếp theo có khoảng cách ngắn nhất
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[u][v] < min_dist)
            {
                min_dist = dist[u][v];
                min_v = v;
            }
        }
        visited[min_v] = true; // đánh dấu đỉnh tiếp theo đã được ghé thăm
        path[i] = min_v;       // thêm đỉnh tiếp theo vào đường đi
    }
}

int calc_cost(int *p)
{ // tính chi phí của một đường đi
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += dist[p[i]][p[(i + 1) % n]];
    }
    return res;
}

int main()
{
    cout << "Nhập sô đỉnh của đồ thị : ";
    cin >> n;
    cout << "Nhập khoảng cách giữa các đỉnh : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }
    int start = 0; // giả sử điểm xuất phát là đỉnh

    greedy_algorithm(start);
    cout << "Đường đi ngắn nhất : ";
    for (int i = 0; i < n; i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << "Chi phí : " << calc_cost(path) << endl;
    return 0;
}
