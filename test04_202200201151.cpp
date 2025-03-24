#include <iostream>
#include <vector>
#include <algorithm>

struct equivnode{
    int equivclass,  // 等价类的标识
        size,        // 等价类的大小
        next;        // 下一个节点的索引
};

equivnode *node;      // 存储等价类信息的数组

void creat(int num) {
    node = new equivnode[num+1];  // 创建存储等价类信息的数组
    for (int i = 1; i <= num; i++) {
        node[i].equivclass = i;  // 初始时每个元素的等价类标识为自身
        node[i].next = 0;         // 初始时每个元素的下一个节点索引为0
        node[i].size = 1;         // 初始时每个等价类的大小为1
    }
}

int find(int data) {
    return node[data].equivclass;  // 返回元素所属的等价类标识
}

void unit(int a, int b) {
    if (node[a].size > node[b].size) {
        std::swap(a, b);  // 交换a和b，保证a所在的等价类更小
    }
    int k;
    for (k = a; node[k].next != 0; k = node[k].next) {
        node[k].equivclass = b;  // 将a所在的等价类中的所有元素的等价类标识都设为b
    }
    node[k].equivclass = b;  // 将a所在的等价类中的最后一个元素的等价类标识设为b
    node[b].size += node[a].size;  // 更新b所在等价类的大小
    node[k].next = node[b].next;   // 将a所在的等价类连接到b所在的等价类
    node[b].next = a;              // 将a所在的等价类连接到b所在的等价类
}

void printequivalenceclass(int num) {
    std::vector<int> equivalenceclass[num+1];
    for (int i = 1; i <= num; i++) {
        int e = find(i);
//        std::cout<<e<<std::endl;
        equivalenceclass[e].push_back(i);  // 将元素按照等价类归类
    }
    for (int i = 1; i <= num; i++) {
        if (!equivalenceclass[i].empty()) {
            std::sort(equivalenceclass[i].begin(), equivalenceclass[i].end());
            std::cout << "(";
            for (int j = 0; j < equivalenceclass[i].size(); j++) {
                std::cout << equivalenceclass[i][j];  // 输出每个等价类中的元素
                if (j != equivalenceclass[i].size() - 1) {
                    std::cout << ",";
                }
            }
            std::cout << ")" << std::endl;
        }
    }
}

int main() {
    int n, r;
    std::cout << "input" << std::endl;
    std::cin >> n;
    creat(n);
    std::cin >> r;
    for (int i = 1; i <= r; i++) {
        int a, b;
        char c;
        std::cin >> c >> a >> c >> b >> c;
        if(find(a)!=find(b)){
		unit(find(a), find(b));  // 合并a和b所在的等价类
		}
    }
    std::cout << "output" << std::endl;
    printequivalenceclass(n);  // 输出等价类
    std::cout << "End" << std::endl;
    delete[] node;  // 释放内存
    return 0;
}
