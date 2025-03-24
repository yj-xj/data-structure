#include<bits/stdc++.h>
#include<queue>
using namespace std;
bool isFirst = true;

template<class T>
struct TreeNode{
	T element;  // �ڵ�Ԫ�ص�����Ϊ T
	TreeNode<T> *lchild, *rchild;  // ���Ӻ��Һ��ӵ�ָ��
	TreeNode(){  // Ĭ�Ϲ��캯�������Ӻ��Һ���ָ���ʼ��Ϊ NULL
		lchild = rchild = NULL;
	}
	TreeNode(const T& theelement){  // ���캯�������ڵ�Ԫ�ظ�ֵ�� element�����Ӻ��Һ���ָ���ʼ��Ϊ NULL
		element = theelement;
		lchild = rchild = NULL;
	}
	TreeNode(const T& theelement, TreeNode *thelchild, TreeNode *therchild){  // ���캯�������ýڵ�Ԫ�ء����Ӻ��Һ���
		element = theelement;
		lchild = thelchild;
		rchild = therchild;
	}
};

template<class T>
class Tree{
	public:
		Tree(){  // Ĭ�Ϲ��캯�������ڵ�ָ���ʼ��Ϊ NULL
			root = NULL;
		}
	void creat(string);
	~Tree(){  // �����������ݹ�ɾ�����ϵ����нڵ�
		delet(root);
	}
	void visit(TreeNode<T>*);  // ���ʲ�����ڵ�Ԫ��
	void pre(TreeNode<T>*);  // �������
	void in(TreeNode<T>*);  // �������
	void post(TreeNode<T>*);  // �������
	void lev(TreeNode<T>*);  // ��α���
	int height(TreeNode<T>*);  // �������ĸ߶�
	TreeNode<T>* getroot() const{  // ��ȡ���ڵ�
		return root;
	}
	TreeNode<char>* bulid(const char*pre,const char* in , int m){  // ���������������ظ��ڵ�ָ��
		if(m == 0){  // ��ǰ�ڵ�Ϊ�գ�ֱ�ӷ��� NULL
			return NULL;
		}
		int k = 0;
		while(pre[0]!= in[k]){  // �������������ҵ����ڵ��λ��
			k++;
		}
		TreeNode<char>* t = new TreeNode<char>;  // ����һ���½ڵ�
		t->element = pre[0];  // �����½ڵ��Ԫ��Ϊ���ڵ�
		t->lchild = bulid(pre+1,in,k);  // �ݹ鹹��������
		t->rchild = bulid(pre+k+1,in+k+1,m-k-1);  // �ݹ鹹��������
		return t;
		}
	private:
		TreeNode<T>* root;  // ���ڵ�ָ��
		void delet(TreeNode<T>* op){  // �ݹ�ɾ���ڵ�
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
		 if (!isFirst) {  // ������ǵ�һ���ڵ㣬������źͿո�
					        cout << ",";
					    }
					    cout << tree->element;  // ����ڵ�Ԫ��
					    isFirst = false;
		if(tree->lchild!=NULL){  // �����Ӽ������
			q.push(tree->lchild);
		}
		if(tree->rchild!=NULL){  // ���Һ��Ӽ������
					q.push(tree->rchild);
				}
				if(!q.empty()){  // ������зǿգ���ȡ��һ���ڵ�
					tree = q.front();
				}
				else return;  // �������Ϊ�գ��˳�ѭ��
					q.pop();  // �������׽ڵ�
	}
}

template<class T>
int Tree<T>::height(TreeNode<T>*tree){  // �������ĸ߶�
	if(tree == NULL){  // �����ǰ�ڵ�Ϊ�գ����� 0
		return 0;
	}
	int hleft = height(tree->lchild);  // �ݹ�����������ĸ߶�
	int hright = height(tree -> rchild);  // �ݹ�����������ĸ߶�
	if(hleft< hright){  // �������������߶ȵĽϴ�ֵ�� 1
		return ++hright;
	}
	else return ++hleft;
}
template<class T>
void Tree<T>::visit(TreeNode<T>* op){  // ���ʲ�����ڵ�Ԫ��
			    if (!isFirst) {  // ������ǵ�һ���ڵ㣬������źͿո�
			        cout << ",";
			    }
			    cout << op->element;  // ����ڵ�Ԫ��
			    isFirst = false;
}	
		
template<class T>
void Tree<T>::creat(string str){  // ����һ����
	if(str.empty()){  // ��������ַ���Ϊ�գ�ֱ�ӷ���
		return;
	}
	
	root =new TreeNode<T>(str[0]);  // �������ڵ�
	
	queue<TreeNode<T>*> q;
	q.push(root);
	int j = 1;
	
	while(!q.empty()){
		TreeNode<T>* now = q.front();  // ��ǰ�ڵ�
		q.pop();
		
		if(j < str.length() && now->lchild == NULL){  // ��ǰ�ڵ������Ϊ�գ��һ��������ַ�
			TreeNode<T>* left =new TreeNode<T>(str[j]);  // �������ӽڵ�
			now->lchild = left;  // ��ǰ�ڵ������ָ��ָ�����ӽڵ�
			q.push(left);  // �����ӽڵ�������
	    }
	    j++;
	    if(j < str.length() && now->rchild == NULL){  // ��ǰ�ڵ���Һ���Ϊ�գ��һ��������ַ�
			TreeNode<T>* righ =new TreeNode<T>(str[j]);  // �����Һ��ӽڵ�
			now->rchild = righ;  // ��ǰ�ڵ���Һ���ָ��ָ���Һ��ӽڵ�
			q.push(righ);  // ���Һ��ӽڵ�������
	    }
	    j++;
	}
}

template<class T>
void Tree<T>::pre(TreeNode<T>* op){  // �������
		if(op!=NULL){
			visit(op);  // ���ʵ�ǰ�ڵ�
			pre(op->lchild);  // �������������
			pre(op->rchild);  // �������������
		}
	}
	
	
template<class T>
void Tree<T>::in(TreeNode<T>* op){  // �������
		if(op!=NULL){
			in(op->lchild);  // �������������
				visit(op);  // ���ʵ�ǰ�ڵ�
			in(op->rchild);  // �������������
		}
	}	
	
	
template<class T>
void Tree<T>::post(TreeNode<T>* op){  // �������
		if(op!=NULL){
			post(op->lchild);  // �������������
			post(op->rchild);  // �������������
				visit(op);  // ���ʵ�ǰ�ڵ�
		}
	}	

void postorder(TreeNode<char>* op){  // �������
		if(op!=NULL){
			postorder(op->lchild);  // �������������
			postorder(op->rchild);  // �������������
		 if (!isFirst) {  // ������ǵ�һ���ڵ㣬������źͿո�
	    cout << ",";
		 }
			cout << op->element;  // ����ڵ�Ԫ��
			 isFirst = false;
		}
	}	
	
int main() {
    string str;
    cout << "input1" << endl;
    getline(cin, str);  // ��ȡ��һ���ַ���

    cout << "output1" << endl;
    Tree<char> tree1;
    tree1.creat(str);  // ������һ����
    tree1.pre(tree1.getroot());  // ����������
    cout << endl;
    isFirst = true;
    tree1.in(tree1.getroot());  // ����������
    cout << endl;
    isFirst = true;
    tree1.post(tree1.getroot());  // ����������
    cout << endl;
    int l = str.length();  // �����ַ����ĳ���
    cout << l << endl;
    int h = tree1.height(tree1.getroot());  // ��һ�����ĸ߶�
    cout << h << endl;

    cout << "input2" << endl;
    const char* pre;
    const char* in;
    string p, i;
    cin >> p >> i;  // ��ȡ�ڶ����ַ���
    pre = p.data();
    in = i.data();
    Tree<TreeNode<char>*> tree2;
    cout << "output2" << endl;
    TreeNode<char>* root2 = tree2.bulid(pre, in, p.length());  // �����ڶ�����
    isFirst = true;
    postorder(root2); // ����������
    cout<<endl;
    isFirst = true;
    level(root2);  // ��α������
    cout << endl;
    cout << "End";
    
    return 0;
}
