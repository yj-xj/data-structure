#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dis[12]; // 用于存储起始点到各顶点的最短距离
int reach[12]; // 用于标记顶点是否可达

class Graph {
private:
    int n, e; // 分别表示顶点数和边数
    vector<vector<int>> matrix; // 邻接矩阵

public:
    Graph(int nodes, int edge) : n(nodes), e(edge), matrix(nodes + 1, vector<int>(nodes + 1, 0)) {}

    void addEdge(int s, int e, int weight) {
        matrix[s][e] = weight; // 节点从1到n编号，而矩阵从0到n-1编号，在邻接矩阵中添加边的权值
        matrix[e][s] = weight; // 无向图需要将两个方向的边都设置权值
    }

    void BFS(int node, int breach[]) {
        queue<int> q;
        breach[node] = 1; // 标记起始节点已访问
        q.push(node);
        bool first = true;

        while (!q.empty()) {
            int m = q.front();
            if (!first) {
			            cout << ","; // 如果不是第一个节点，输出逗号
			        } else {
			            first] = false; // 标记已经输出了第一个节点
			        }
			        cout << m; // 输出访问节点
            q.pop();

            for (int i = 1; i <= n; i++) {
                if (matrix[m][i] != 0 && breach[i] == 0) {
                    breach[i] = 1;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFS(int node, int dreach[]) {
        dreach[node] = 1; // 标记当前节点已访问
        cout << node; // 输出访问节点

        for (int i = 1; i <= n; i++) {
            if (matrix[node][i] != 0 && dreach[i] == 0) {
                cout << ","; // 输出逗号
                DFS(i, dreach); // 递归访问相邻节点
            }
        }
    }

    void minPath(int start,int End) {
        for (int i = 2; i <= n; i++) {
            if (matrix[start][i] != 0) {
                dis[i] = matrix[start][i];
            } else {
                dis[i] = 9999; // 初始化距离数组，9999表示不可达 
            }
        }
        reach[start] = 1; // 标记起始点已访问

        for (int i = 1; i <= n; i++) {
            int t = 9999, x = 1;
            for (int j = 1; j <= n; j++) {
                if (reach[j] == 0 && dis[j] < t) {
                    t = dis[j];
                    x = j;
                }
            }
            reach[x] = 1;

            for (int k = 1; k <= n; k++) {
                if (reach[k] == 0 && matrix[x][k] != 0) {
                    if (dis[k] > dis[x] + matrix[x][k]) {
                        dis[k] = dis[x] + matrix[x][k];
                    }
                }
            }
        }
        cout << dis[End] << endl; // 输出起始点到终点的最短距离
    }
};

int main() {
    int n, m;
    cout << "Input" << endl;
    char c;
    cin >> n >> c >> m;

    if (n <= 0 || n > 10) { // 增加 m 的合法性检查
        cout << "Error input" << endl;
        return 0;
    }

    Graph g(n, m);
    for (int i = 0; i < m; i++) {
        int start, en, t;
        cin >> start >> c >> en >> c >> t;
        if (start >= 1 && start <= n && en >= 1 && en <= n) { // 增加边的合法节点编号检查
            g.addEdge(start, en, t);
        } else {
            cout << "Invalid edge input" << endl; // 如果输入的边不合法，输出错误信息
            return 0;
        }
    }

    cout << "Output" << endl;
    int breach[12] = {0}; // 用于标记节点是否访问过
    int dreach[12] = {0}; // 用于标记节点是否访问过
    
    g.BFS(1, breach); // 从第一个节点开始广度优先搜索
    g.DFS(1, dreach); // 从第一个节点开始深度优先搜索
    cout << endl;
    if(breach[n]==0){
		cout<<0<<endl;
	}
    else g.minPath(1,n); // 输出起始点到终点的最短距离

    cout << "End";
    return 0;
}
