#include <iostream>
#include <vector>
#include <algorithm>

struct equivnode{
    int equivclass,  // �ȼ���ı�ʶ
        size,        // �ȼ���Ĵ�С
        next;        // ��һ���ڵ������
};

equivnode *node;      // �洢�ȼ�����Ϣ������

void creat(int num) {
    node = new equivnode[num+1];  // �����洢�ȼ�����Ϣ������
    for (int i = 1; i <= num; i++) {
        node[i].equivclass = i;  // ��ʼʱÿ��Ԫ�صĵȼ����ʶΪ����
        node[i].next = 0;         // ��ʼʱÿ��Ԫ�ص���һ���ڵ�����Ϊ0
        node[i].size = 1;         // ��ʼʱÿ���ȼ���Ĵ�СΪ1
    }
}

int find(int data) {
    return node[data].equivclass;  // ����Ԫ�������ĵȼ����ʶ
}

void unit(int a, int b) {
    if (node[a].size > node[b].size) {
        std::swap(a, b);  // ����a��b����֤a���ڵĵȼ����С
    }
    int k;
    for (k = a; node[k].next != 0; k = node[k].next) {
        node[k].equivclass = b;  // ��a���ڵĵȼ����е�����Ԫ�صĵȼ����ʶ����Ϊb
    }
    node[k].equivclass = b;  // ��a���ڵĵȼ����е����һ��Ԫ�صĵȼ����ʶ��Ϊb
    node[b].size += node[a].size;  // ����b���ڵȼ���Ĵ�С
    node[k].next = node[b].next;   // ��a���ڵĵȼ������ӵ�b���ڵĵȼ���
    node[b].next = a;              // ��a���ڵĵȼ������ӵ�b���ڵĵȼ���
}

void printequivalenceclass(int num) {
    std::vector<int> equivalenceclass[num+1];
    for (int i = 1; i <= num; i++) {
        int e = find(i);
//        std::cout<<e<<std::endl;
        equivalenceclass[e].push_back(i);  // ��Ԫ�ذ��յȼ������
    }
    for (int i = 1; i <= num; i++) {
        if (!equivalenceclass[i].empty()) {
            std::sort(equivalenceclass[i].begin(), equivalenceclass[i].end());
            std::cout << "(";
            for (int j = 0; j < equivalenceclass[i].size(); j++) {
                std::cout << equivalenceclass[i][j];  // ���ÿ���ȼ����е�Ԫ��
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
		unit(find(a), find(b));  // �ϲ�a��b���ڵĵȼ���
		}
    }
    std::cout << "output" << std::endl;
    printequivalenceclass(n);  // ����ȼ���
    std::cout << "End" << std::endl;
    delete[] node;  // �ͷ��ڴ�
    return 0;
}
