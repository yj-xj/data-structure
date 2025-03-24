#include<bits/stdc++.h>
using namespace std;
bool isFirst = true;

// ��������
void createMaxHeap(vector<int>& heap){
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        int k = i;
        int j = 2 * k + 1;
        while (j < n) {
            if (j + 1 < n && heap[j] < heap[j + 1]) {  // �Ƚ϶ѵ������ӽڵ㣬���ϴ�Ľڵ��뵱ǰ�ڵ㽻��
                j++;
            }
            if (heap[k] >= heap[j]) { // ��ǰ�ڵ���ڵ��������ӽڵ㣬�򽻻���������
                break;
            } else {
                swap(heap[k], heap[j]); // ��ǰ�ڵ�С�������ӽڵ㣬����ǰ�ڵ���ϴ���ӽڵ㽻�����������ƶ�
                k = j;
                j = 2 * k + 1;
            }
        }
    }
}

// ������
void maxHeapSort(vector<int>& heap){
    createMaxHeap(heap);
    int n = heap.size();
    for(int i=n-1;i>0;i--){
        swap(heap[0],heap[i]); // ���Ѷ�Ԫ�أ����Ԫ�أ��뵱ǰ�������һ��Ԫ�ؽ���
        int k = 0;
        int j = 2*k + 1;
        while(j<i){
            if(j+1<i && heap[j]<heap[j+1]){ // �Ƚ϶ѵ������ӽڵ㣬���ϴ���ӽڵ��뵱ǰ�ڵ㽻��
                j++;
            }
            
            if(heap[k]>=heap[j]){ // ��ǰ�ڵ���ڵ��������ӽڵ㣬�򽻻���������
                break;
            }
            else{
                swap(heap[k],heap[j]); // ��ǰ�ڵ�С�������ӽڵ㣬����ǰ�ڵ���ϴ���ӽڵ㽻�����������ƶ�
                k = j;
                j = 2*k + 1;
            }
        }
    }
}

struct TreeNode{
    int element;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : element(x), left(nullptr), right(nullptr) {}
};

// �������������
TreeNode* insert(TreeNode* root, int element){
    if(root == nullptr){
        return new TreeNode(element);
    }
    if(element < root->element){
        root->left = insert(root->left, element);
    }
    else if(element > root->element){
        root->right = insert(root->right, element);
    }
    return root;
}

// ���ʶ������ڵ�
void visit(TreeNode* op){
    if (op == nullptr) {
        return;
    }
    if (!isFirst) {
        cout << ",";
    }
    cout << op->element;
    isFirst = false;
}

// ǰ�����
void preOrderTraversal(TreeNode* op){
    if(op == nullptr){
        return;
    }
    visit(op); // �ȷ��ʵ�ǰ�ڵ�
    preOrderTraversal(op->left); // �ٱ���������
    preOrderTraversal(op->right); // ������������
}

// �������
void inOrderTraversal(TreeNode* op){
    if(op == nullptr){
        return;
    }
    inOrderTraversal(op->left); // �ȱ���������
    visit(op); // �ٷ��ʵ�ǰ�ڵ�
    inOrderTraversal(op->right); // ������������
}

int main(){
    vector<int> heap;
    int n;
    cout << "input" << endl;
    while(cin >> n){
        if(n == 0 || heap.size() >= 20){
            break;
        }
        heap.push_back(n);
    }
    vector<int> heap1 = heap;  // �������е�����

    cout << "output" << endl;
    createMaxHeap(heap); // ��������
    isFirst = true;
    for (auto num : heap) { // �������
        if (!isFirst) {
            cout << ",";
        }
        cout << num;
        isFirst = false;
    }
    cout << endl;

    maxHeapSort(heap); // ������
    isFirst = true;
    for (auto num : heap) { // ����������Ľ��
        if (!isFirst) {
            cout << ",";
        }
        cout << num;
        isFirst = false;
    }
    cout << endl;

    TreeNode* root = nullptr;
    for(auto num : heap1){ // ��������������
        root = insert(root, num);
    }

    isFirst = true;
    preOrderTraversal(root); // ǰ��������
    cout << endl;

    isFirst = true;
    inOrderTraversal(root); // ����������
    cout << endl;
    cout << "End";
    return 0;
}
