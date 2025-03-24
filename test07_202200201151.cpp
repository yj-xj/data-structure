#include<bits/stdc++.h>
using namespace std;
bool isFirst = true;

// 创建最大堆
void createMaxHeap(vector<int>& heap){
    int n = heap.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        int k = i;
        int j = 2 * k + 1;
        while (j < n) {
            if (j + 1 < n && heap[j] < heap[j + 1]) {  // 比较堆的左右子节点，将较大的节点与当前节点交换
                j++;
            }
            if (heap[k] >= heap[j]) { // 当前节点大于等于左右子节点，则交换操作结束
                break;
            } else {
                swap(heap[k], heap[j]); // 当前节点小于左右子节点，将当前节点与较大的子节点交换，并向下移动
                k = j;
                j = 2 * k + 1;
            }
        }
    }
}

// 堆排序
void maxHeapSort(vector<int>& heap){
    createMaxHeap(heap);
    int n = heap.size();
    for(int i=n-1;i>0;i--){
        swap(heap[0],heap[i]); // 将堆顶元素（最大元素）与当前堆中最后一个元素交换
        int k = 0;
        int j = 2*k + 1;
        while(j<i){
            if(j+1<i && heap[j]<heap[j+1]){ // 比较堆的左右子节点，将较大的子节点与当前节点交换
                j++;
            }
            
            if(heap[k]>=heap[j]){ // 当前节点大于等于左右子节点，则交换操作结束
                break;
            }
            else{
                swap(heap[k],heap[j]); // 当前节点小于左右子节点，将当前节点与较大的子节点交换，并向下移动
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

// 插入二叉搜索树
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

// 访问二叉树节点
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

// 前序遍历
void preOrderTraversal(TreeNode* op){
    if(op == nullptr){
        return;
    }
    visit(op); // 先访问当前节点
    preOrderTraversal(op->left); // 再遍历左子树
    preOrderTraversal(op->right); // 最后遍历右子树
}

// 中序遍历
void inOrderTraversal(TreeNode* op){
    if(op == nullptr){
        return;
    }
    inOrderTraversal(op->left); // 先遍历左子树
    visit(op); // 再访问当前节点
    inOrderTraversal(op->right); // 最后遍历右子树
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
    vector<int> heap1 = heap;  // 拷贝堆中的数据

    cout << "output" << endl;
    createMaxHeap(heap); // 创建最大堆
    isFirst = true;
    for (auto num : heap) { // 输出最大堆
        if (!isFirst) {
            cout << ",";
        }
        cout << num;
        isFirst = false;
    }
    cout << endl;

    maxHeapSort(heap); // 堆排序
    isFirst = true;
    for (auto num : heap) { // 输出堆排序后的结果
        if (!isFirst) {
            cout << ",";
        }
        cout << num;
        isFirst = false;
    }
    cout << endl;

    TreeNode* root = nullptr;
    for(auto num : heap1){ // 构建二叉搜索树
        root = insert(root, num);
    }

    isFirst = true;
    preOrderTraversal(root); // 前序遍历输出
    cout << endl;

    isFirst = true;
    inOrderTraversal(root); // 中序遍历输出
    cout << endl;
    cout << "End";
    return 0;
}
