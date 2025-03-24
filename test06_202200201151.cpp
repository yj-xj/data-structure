#include<bits/stdc++.h>
#include<queue>
using namespace std;
bool isFirst = true;

template<class T>
struct TreeNode{
	T element;  // 节点元素的类型为 T
	TreeNode<T> *lchild, *rchild;  // 左孩子和右孩子的指针
	TreeNode(){  // 默认构造函数，左孩子和右孩子指针初始化为 NULL
		lchild = rchild = NULL;
	}
	TreeNode(const T& theelement){  // 构造函数，将节点元素赋值给 element，左孩子和右孩子指针初始化为 NULL
		element = theelement;
		lchild = rchild = NULL;
	}
	TreeNode(const T& theelement, TreeNode *thelchild, TreeNode *therchild){  // 构造函数，设置节点元素、左孩子和右孩子
		element = theelement;
		lchild = thelchild;
		rchild = therchild;
	}
};

template<class T>
class Tree{
	public:
		Tree(){  // 默认构造函数，根节点指针初始化为 NULL
			root = NULL;
		}
	void creat(string);
	~Tree(){  // 析构函数，递归删除树上的所有节点
		delet(root);
	}
	void visit(TreeNode<T>*);  // 访问并输出节点元素
	void pre(TreeNode<T>*);  // 先序遍历
	void in(TreeNode<T>*);  // 中序遍历
	void post(TreeNode<T>*);  // 后序遍历
	void lev(TreeNode<T>*);  // 层次遍历
	int height(TreeNode<T>*);  // 计算树的高度
	TreeNode<T>* getroot() const{  // 获取根节点
		return root;
	}
	TreeNode<char>* bulid(const char*pre,const char* in , int m){  // 构建二叉树，返回根节点指针
		if(m == 0){  // 当前节点为空，直接返回 NULL
			return NULL;
		}
		int k = 0;
		while(pre[0]!= in[k]){  // 在中序序列中找到根节点的位置
			k++;
		}
		TreeNode<char>* t = new TreeNode<char>;  // 创建一个新节点
		t->element = pre[0];  // 设置新节点的元素为根节点
		t->lchild = bulid(pre+1,in,k);  // 递归构建左子树
		t->rchild = bulid(pre+k+1,in+k+1,m-k-1);  // 递归构建右子树
		return t;
		}
	private:
		TreeNode<T>* root;  // 根节点指针
		void delet(TreeNode<T>* op){  // 递归删除节点
			if(op!= NULL){
				delet(op->lchild);
				delet(op->rchild);
				delete op;
			}
		}
};

void level(TreeNode<char>*tree){
	queue<TreeNode<char>*>q;
	while(tree != NULL){
		 if (!isFirst) {  // 如果不是第一个节点，输出逗号和空格
					        cout << ",";
					    }
					    cout << tree->element;  // 输出节点元素
					    isFirst = false;
		if(tree->lchild!=NULL){  // 将左孩子加入队列
			q.push(tree->lchild);
		}
		if(tree->rchild!=NULL){  // 将右孩子加入队列
					q.push(tree->rchild);
				}
				if(!q.empty()){  // 如果队列非空，获取下一个节点
					tree = q.front();
				}
				else return;  // 如果队列为空，退出循环
					q.pop();  // 弹出队首节点
	}
}

template<class T>
int Tree<T>::height(TreeNode<T>*tree){  // 计算树的高度
	if(tree == NULL){  // 如果当前节点为空，返回 0
		return 0;
	}
	int hleft = height(tree->lchild);  // 递归计算左子树的高度
	int hright = height(tree -> rchild);  // 递归计算右子树的高度
	if(hleft< hright){  // 返回左右子树高度的较大值加 1
		return ++hright;
	}
	else return ++hleft;
}
template<class T>
void Tree<T>::visit(TreeNode<T>* op){  // 访问并输出节点元素
			    if (!isFirst) {  // 如果不是第一个节点，输出逗号和空格
			        cout << ",";
			    }
			    cout << op->element;  // 输出节点元素
			    isFirst = false;
}	
		
template<class T>
void Tree<T>::creat(string str){  // 创建一棵树
	if(str.empty()){  // 如果输入字符串为空，直接返回
		return;
	}
	
	root =new TreeNode<T>(str[0]);  // 创建根节点
	
	queue<TreeNode<T>*> q;
	q.push(root);
	int j = 1;
	
	while(!q.empty()){
		TreeNode<T>* now = q.front();  // 当前节点
		q.pop();
		
		if(j < str.length() && now->lchild == NULL){  // 当前节点的左孩子为空，且还有输入字符
			TreeNode<T>* left =new TreeNode<T>(str[j]);  // 创建左孩子节点
			now->lchild = left;  // 当前节点的左孩子指针指向左孩子节点
			q.push(left);  // 将左孩子节点加入队列
	    }
	    j++;
	    if(j < str.length() && now->rchild == NULL){  // 当前节点的右孩子为空，且还有输入字符
			TreeNode<T>* righ =new TreeNode<T>(str[j]);  // 创建右孩子节点
			now->rchild = righ;  // 当前节点的右孩子指针指向右孩子节点
			q.push(righ);  // 将右孩子节点加入队列
	    }
	    j++;
	}
}

template<class T>
void Tree<T>::pre(TreeNode<T>* op){  // 先序遍历
		if(op!=NULL){
			visit(op);  // 访问当前节点
			pre(op->lchild);  // 先序遍历左子树
			pre(op->rchild);  // 先序遍历右子树
		}
	}
	
	
template<class T>
void Tree<T>::in(TreeNode<T>* op){  // 中序遍历
		if(op!=NULL){
			in(op->lchild);  // 中序遍历左子树
				visit(op);  // 访问当前节点
			in(op->rchild);  // 中序遍历右子树
		}
	}	
	
	
template<class T>
void Tree<T>::post(TreeNode<T>* op){  // 后序遍历
		if(op!=NULL){
			post(op->lchild);  // 后序遍历左子树
			post(op->rchild);  // 后序遍历右子树
				visit(op);  // 访问当前节点
		}
	}	

void postorder(TreeNode<char>* op){  // 后序遍历
		if(op!=NULL){
			postorder(op->lchild);  // 后序遍历左子树
			postorder(op->rchild);  // 后序遍历右子树
		 if (!isFirst) {  // 如果不是第一个节点，输出逗号和空格
	    cout << ",";
		 }
			cout << op->element;  // 输出节点元素
			 isFirst = false;
		}
	}	
	
int main() {
    string str;
    cout << "input1" << endl;
    getline(cin, str);  // 读取第一个字符串

    cout << "output1" << endl;
    Tree<char> tree1;
    tree1.creat(str);  // 创建第一棵树
    tree1.pre(tree1.getroot());  // 先序遍历输出
    cout << endl;
    isFirst = true;
    tree1.in(tree1.getroot());  // 中序遍历输出
    cout << endl;
    isFirst = true;
    tree1.post(tree1.getroot());  // 后序遍历输出
    cout << endl;
    int l = str.length();  // 输入字符串的长度
    cout << l << endl;
    int h = tree1.height(tree1.getroot());  // 第一棵树的高度
    cout << h << endl;

    cout << "input2" << endl;
    const char* pre;
    const char* in;
    string p, i;
    cin >> p >> i;  // 读取第二个字符串
    pre = p.data();
    in = i.data();
    Tree<TreeNode<char>*> tree2;
    cout << "output2" << endl;
    TreeNode<char>* root2 = tree2.bulid(pre, in, p.length());  // 创建第二棵树
    isFirst = true;
    postorder(root2); // 后序遍历输出
    cout<<endl;
    isFirst = true;
    level(root2);  // 层次遍历输出
    cout << endl;
    cout << "End";
    
    return 0;
}
