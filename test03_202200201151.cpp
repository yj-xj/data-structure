#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* creatchainlist(){ // 创建链表
	int n;
	cin>>n;
	if(n == 0){
		return nullptr; // 输入为0时，返回空指针
	}
	Node* head = new Node; // 创建头节点
	head->data = n;
	head->next = nullptr;
	Node* now = head; // 当前节点指针
	while(cin>>n){
		if(n == 0){
			break; // 输入为0时，结束循环
		}
		Node* node = new Node; // 创建新节点
		node->data = n;
	if (node->data < head->data) {
	            node->next = head;
	            head = node;
	        } else {
	            Node* cur = head;
	            while (cur->next != nullptr && cur->next->data < node->data) {
	                cur = cur->next;
	            }
	            node->next = cur->next;
	            cur->next = node;
	        }
	}
	return head; // 返回头节点
}

void printchainlist(Node* head){ // 打印链表
	if(head == nullptr){
		cout<<"<null>"<<endl; // 链表为空时，输出"<null>"
		return;
	}
	Node* current = head; // 当前节点指针
	while(current != nullptr){
		cout<<current->data; // 输出当前节点的数据
		if(current->next!=nullptr){
			cout<<",";
		}
		current = current->next; // 更新当前节点指针
	}
	cout<<endl;
}

Node* mergechainlist(Node* head1, Node* head2){ // 合并链表
	if(head1 == nullptr){
		return head2; // 链表1为空时，返回链表2
	}
	if(head2 == nullptr){
		return head1; // 链表2为空时，返回链表1
	}
	Node* mergenode; // 合并后的链表头节点
	if(head1->data <= head2->data){
		mergenode = head1; // 链表1的头节点作为合并后的头节点
		head1 = head1->next; // 更新链表1的头节点指针
	}
	else{
		mergenode = head2; // 链表2的头节点作为合并后的头节点
		head2 = head2->next; // 更新链表2的头节点指针
	}
	Node* now = mergenode; // 当前节点指针
	while(head1 != nullptr && head2 != nullptr){
		if(head1->data <= head2->data){
			now->next = head1; // 将链表1的节点连接到当前节点的后面
			head1 = head1->next; // 更新链表1的头节点指针
		}
		else{
			now->next = head2; // 将链表2的节点连接到当前节点的后面
			head2 = head2->next; // 更新链表2的头节点指针
		}
		now = now->next; // 更新当前节点指针
	}
	if(head1 != nullptr){
		now->next = head1; // 将链表1剩余的节点连接到当前节点的后面
	}
	if(head2 != nullptr){
		now->next = head2; // 将链表2剩余的节点连接到当前节点的后面
	}
	return mergenode; // 返回合并后的链表头节点
}

Node* insertchainnode(Node* head, int data){ // 插入节点
	Node* n = new Node; // 创建新节点
	n->data = data;
	n->next = nullptr;
	if(head == nullptr){
		return n; // 链表为空时，直接返回新节点
	}
	if(data <= head->data){
		n->next = head; // 将新节点插入到链表头部
		return n;
	}
	Node* now = head; // 当前节点指针
	while(now->next != nullptr && now->next->data <= data){
		now = now->next; // 找到要插入的位置
	}
	n->next = now->next; // 将新节点连接到当前节点的后面
	now->next = n;
	return head; // 返回链表头节点
}

Node* delet(Node* head, int data){ // 删除节点
	if(head == nullptr){
		return nullptr; // 链表为空时，直接返回空指针
	}
	if(head->data==data)
	{
		Node* node = head;
		head= head->next;
		delete node;
		return head;
	}
	Node* current = head; // 当前节点指针
	while(current->next != nullptr && current->next->data != data){
		current = current->next; // 找到要删除的节点的前一个节点
	}
	Node* n = current->next; // 要删除的节点
	current->next = current->next->next; // 将前一个节点连接到要删除节点的下一个节点
	delete n; // 释放要删除的节点的内存空间
	return head; // 返回链表头节点
}

int searchchainnode(Node* head, int data){ // 查找节点
	Node* now = head; // 当前节点指针
	int index = 0; // 节点位置
	while(now != nullptr ){
			index++; // 位置加1
			 if (now->data == data) {
			            return index;
			        }
		now = now->next; // 移动到下一个节点
	}
	return 0; // 返回节点位置
}

int main(){
	cout<<"input1"<<endl;
	Node* head1 = creatchainlist();
	cout<<"output1"<<endl;
	printchainlist(head1);
	
	cout<<"input2"<<endl;
	Node* head2 = creatchainlist();
	cout<<"output2"<<endl;
	printchainlist(head2);
	
	cout<<"combine"<<endl;
	Node* merge = mergechainlist(head1, head2);
    printchainlist(merge);
	
	cout<<"insert"<<endl;
	int h;
	cin>>h;
	merge=insertchainnode(merge, h);
	cout<<"insertion"<<endl;
	printchainlist(merge);
	
	cout<<"delete"<<endl;
	int m;
	cin>>m;
	merge=
	delet(merge, m);
	cout<<"deletion"<<endl;
	printchainlist(merge);
	
	cout<<"find"<<endl;
	int f, g;
	cin>>f;
	g = searchchainnode(merge, f);
	cout<<"position"<<endl;
	cout<<g<<endl;
	
	cout<<"End"<<endl;
}
