#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dis[12]; // ���ڴ洢��ʼ�㵽���������̾���
int reach[12]; // ���ڱ�Ƕ����Ƿ�ɴ�

class Graph {
private:
    int n, e; // �ֱ��ʾ�������ͱ���
    vector<vector<int>> matrix; // �ڽӾ���

public:
    Graph(int nodes, int edge) : n(nodes), e(edge), matrix(nodes + 1, vector<int>(nodes + 1, 0)) {}

    void addEdge(int s, int e, int weight) {
        matrix[s][e] = weight; // �ڵ��1��n��ţ��������0��n-1��ţ����ڽӾ�������ӱߵ�Ȩֵ
        matrix[e][s] = weight; // ����ͼ��Ҫ����������ı߶�����Ȩֵ
    }

    void BFS(int node, int breach[]) {
        queue<int> q;
        breach[node] = 1; // �����ʼ�ڵ��ѷ���
        q.push(node);
        bool first = true;

        while (!q.empty()) {
            int m = q.front();
            if (!first) {
			            cout << ","; // ������ǵ�һ���ڵ㣬�������
			        } else {
			            first] = false; // ����Ѿ�����˵�һ���ڵ�
			        }
			        cout << m; // ������ʽڵ�
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
        dreach[node] = 1; // ��ǵ�ǰ�ڵ��ѷ���
        cout << node; // ������ʽڵ�

        for (int i = 1; i <= n; i++) {
            if (matrix[node][i] != 0 && dreach[i] == 0) {
                cout << ","; // �������
                DFS(i, dreach); // �ݹ�������ڽڵ�
            }
        }
    }

    void minPath(int start,int End) {
        for (int i = 2; i <= n; i++) {
            if (matrix[start][i] != 0) {
                dis[i] = matrix[start][i];
            } else {
                dis[i] = 9999; // ��ʼ���������飬9999��ʾ���ɴ� 
            }
        }
        reach[start] = 1; // �����ʼ���ѷ���

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
        cout << dis[End] << endl; // �����ʼ�㵽�յ����̾���
    }
};

int main() {
    int n, m;
    cout << "Input" << endl;
    char c;
    cin >> n >> c >> m;

    if (n <= 0 || n > 10) { // ���� m �ĺϷ��Լ��
        cout << "Error input" << endl;
        return 0;
    }

    Graph g(n, m);
    for (int i = 0; i < m; i++) {
        int start, en, t;
        cin >> start >> c >> en >> c >> t;
        if (start >= 1 && start <= n && en >= 1 && en <= n) { // ���ӱߵĺϷ��ڵ��ż��
            g.addEdge(start, en, t);
        } else {
            cout << "Invalid edge input" << endl; // �������ı߲��Ϸ������������Ϣ
            return 0;
        }
    }

    cout << "Output" << endl;
    int breach[12] = {0}; // ���ڱ�ǽڵ��Ƿ���ʹ�
    int dreach[12] = {0}; // ���ڱ�ǽڵ��Ƿ���ʹ�
    
    g.BFS(1, breach); // �ӵ�һ���ڵ㿪ʼ�����������
    g.DFS(1, dreach); // �ӵ�һ���ڵ㿪ʼ�����������
    cout << endl;
    if(breach[n]==0){
		cout<<0<<endl;
	}
    else g.minPath(1,n); // �����ʼ�㵽�յ����̾���

    cout << "End";
    return 0;
}
