#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* creatchainlist(){ // ��������
	int n;
	cin>>n;
	if(n == 0){
		return nullptr; // ����Ϊ0ʱ�����ؿ�ָ��
	}
	Node* head = new Node; // ����ͷ�ڵ�
	head->data = n;
	head->next = nullptr;
	Node* now = head; // ��ǰ�ڵ�ָ��
	while(cin>>n){
		if(n == 0){
			break; // ����Ϊ0ʱ������ѭ��
		}
		Node* node = new Node; // �����½ڵ�
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
	return head; // ����ͷ�ڵ�
}

void printchainlist(Node* head){ // ��ӡ����
	if(head == nullptr){
		cout<<"<null>"<<endl; // ����Ϊ��ʱ�����"<null>"
		return;
	}
	Node* current = head; // ��ǰ�ڵ�ָ��
	while(current != nullptr){
		cout<<current->data; // �����ǰ�ڵ������
		if(current->next!=nullptr){
			cout<<",";
		}
		current = current->next; // ���µ�ǰ�ڵ�ָ��
	}
	cout<<endl;
}

Node* mergechainlist(Node* head1, Node* head2){ // �ϲ�����
	if(head1 == nullptr){
		return head2; // ����1Ϊ��ʱ����������2
	}
	if(head2 == nullptr){
		return head1; // ����2Ϊ��ʱ����������1
	}
	Node* mergenode; // �ϲ��������ͷ�ڵ�
	if(head1->data <= head2->data){
		mergenode = head1; // ����1��ͷ�ڵ���Ϊ�ϲ����ͷ�ڵ�
		head1 = head1->next; // ��������1��ͷ�ڵ�ָ��
	}
	else{
		mergenode = head2; // ����2��ͷ�ڵ���Ϊ�ϲ����ͷ�ڵ�
		head2 = head2->next; // ��������2��ͷ�ڵ�ָ��
	}
	Node* now = mergenode; // ��ǰ�ڵ�ָ��
	while(head1 != nullptr && head2 != nullptr){
		if(head1->data <= head2->data){
			now->next = head1; // ������1�Ľڵ����ӵ���ǰ�ڵ�ĺ���
			head1 = head1->next; // ��������1��ͷ�ڵ�ָ��
		}
		else{
			now->next = head2; // ������2�Ľڵ����ӵ���ǰ�ڵ�ĺ���
			head2 = head2->next; // ��������2��ͷ�ڵ�ָ��
		}
		now = now->next; // ���µ�ǰ�ڵ�ָ��
	}
	if(head1 != nullptr){
		now->next = head1; // ������1ʣ��Ľڵ����ӵ���ǰ�ڵ�ĺ���
	}
	if(head2 != nullptr){
		now->next = head2; // ������2ʣ��Ľڵ����ӵ���ǰ�ڵ�ĺ���
	}
	return mergenode; // ���غϲ��������ͷ�ڵ�
}

Node* insertchainnode(Node* head, int data){ // ����ڵ�
	Node* n = new Node; // �����½ڵ�
	n->data = data;
	n->next = nullptr;
	if(head == nullptr){
		return n; // ����Ϊ��ʱ��ֱ�ӷ����½ڵ�
	}
	if(data <= head->data){
		n->next = head; // ���½ڵ���뵽����ͷ��
		return n;
	}
	Node* now = head; // ��ǰ�ڵ�ָ��
	while(now->next != nullptr && now->next->data <= data){
		now = now->next; // �ҵ�Ҫ�����λ��
	}
	n->next = now->next; // ���½ڵ����ӵ���ǰ�ڵ�ĺ���
	now->next = n;
	return head; // ��������ͷ�ڵ�
}

Node* delet(Node* head, int data){ // ɾ���ڵ�
	if(head == nullptr){
		return nullptr; // ����Ϊ��ʱ��ֱ�ӷ��ؿ�ָ��
	}
	if(head->data==data)
	{
		Node* node = head;
		head= head->next;
		delete node;
		return head;
	}
	Node* current = head; // ��ǰ�ڵ�ָ��
	while(current->next != nullptr && current->next->data != data){
		current = current->next; // �ҵ�Ҫɾ���Ľڵ��ǰһ���ڵ�
	}
	Node* n = current->next; // Ҫɾ���Ľڵ�
	current->next = current->next->next; // ��ǰһ���ڵ����ӵ�Ҫɾ���ڵ����һ���ڵ�
	delete n; // �ͷ�Ҫɾ���Ľڵ���ڴ�ռ�
	return head; // ��������ͷ�ڵ�
}

int searchchainnode(Node* head, int data){ // ���ҽڵ�
	Node* now = head; // ��ǰ�ڵ�ָ��
	int index = 0; // �ڵ�λ��
	while(now != nullptr ){
			index++; // λ�ü�1
			 if (now->data == data) {
			            return index;
			        }
		now = now->next; // �ƶ�����һ���ڵ�
	}
	return 0; // ���ؽڵ�λ��
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
