#include <bits/stdc++.h>
using namespace std;
void bub(vector<int>& numbers)//����ð�����к���
{
	for(int i=0;i<numbers.size()-1;i++)
		for(int j=0;j<numbers.size()-1-i;j++)
		{
			if(numbers[j+1]<numbers[j])//�����һ��С��ǰһ��
			{
				int t;
				t=numbers[j];
				numbers[j]=numbers[j+1];
				numbers[j+1]=t;
			}
			//��������
		}
	
}
void ins(vector<int>& numbers)//����������к���
{
	for(int i=1;i<numbers.size();i++)
	{	
		int k=numbers[i];
		int j= i-1;
	    while(j>=0 && numbers[j]>k)//����j+1λ�����㣬�����ڵ�j+2λ
		{
			numbers[j+1]=numbers[j];//��ǰһλ��ֵ������һλ
			j--;
		}
		numbers[j+1]=k;
	}
}
void sel(vector<int>& numbers)
{
	for(int i=0;i<numbers.size();i++)
	{
	      int min=i;//����min����ֵΪi
	      for(int j=i+1;j<numbers.size();j++)
		  //������iλ֮�����
		     if(numbers[j]<numbers[min])//�������С�ڵ�iλ��ֵ
			 	min=j;///��min��ֵΪj
			 	swap(numbers[min],numbers[i]);//������minλ���iλ
     }
}
int main()
{
	cout<<"Input"<<endl;
	vector<int> numbers;
	int n; 
    for(int i=0;i<18;i++)//�������ʮ��λ��
	{
		cin>>n;
		if(n==0)//���n�����㣬��ֹ
		break;	
		numbers.push_back(n);
	}
	int choice;
	cout<<"1-Bubble Sort,2-Insert Sort,3-Select Sort"<<endl;
	cin>> choice;//����choice
	cout<< "Output"<<endl;
	switch (choice)
	 {
		case 1://��choiceΪ1
		     bub(numbers);//ʹ��ð������
		     cout<< "Bubble Sort"<<endl;
			break;
		case 2://��choiceΪ2
			ins(numbers);//ʹ�ò�������
			cout<<"Insert Sort"<<endl;
			break;
		case 3://��choiceΪ3
			sel(numbers);//ʹ��ѡ������
			cout<<"Select Sort"<<endl;
			break;
	}
	bool m=true;
	for(const auto&i:numbers){
		
		if(!m)
		{
			cout<<",";
		}
		cout<<i;
		m=false;
	}
		cout<<endl;
	cout<<"End";
	return 0;
}

