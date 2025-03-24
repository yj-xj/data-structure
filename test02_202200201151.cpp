#include <bits/stdc++.h>
using namespace std;
void bub(vector<int>& numbers)//定义冒泡排列函数
{
	for(int i=0;i<numbers.size()-1;i++)
		for(int j=0;j<numbers.size()-1-i;j++)
		{
			if(numbers[j+1]<numbers[j])//如果后一项小于前一项
			{
				int t;
				t=numbers[j];
				numbers[j]=numbers[j+1];
				numbers[j+1]=t;
			}
			//交换它们
		}
	
}
void ins(vector<int>& numbers)//定义插入排列函数
{
	for(int i=1;i<numbers.size();i++)
	{	
		int k=numbers[i];
		int j= i-1;
	    while(j>=0 && numbers[j]>k)//当第j+1位大于零，并大于第j+2位
		{
			numbers[j+1]=numbers[j];//将前一位的值赋给后一位
			j--;
		}
		numbers[j+1]=k;
	}
}
void sel(vector<int>& numbers)
{
	for(int i=0;i<numbers.size();i++)
	{
	      int min=i;//定义min，赋值为i
	      for(int j=i+1;j<numbers.size();j++)
		  //遍历第i位之后的数
		     if(numbers[j]<numbers[min])//如果有数小于第i位的值
			 	min=j;///将min赋值为j
			 	swap(numbers[min],numbers[i]);//交换第min位与第i位
     }
}
int main()
{
	cout<<"Input"<<endl;
	vector<int> numbers;
	int n; 
    for(int i=0;i<18;i++)//输入最多十八位数
	{
		cin>>n;
		if(n==0)//如果n等于零，终止
		break;	
		numbers.push_back(n);
	}
	int choice;
	cout<<"1-Bubble Sort,2-Insert Sort,3-Select Sort"<<endl;
	cin>> choice;//输入choice
	cout<< "Output"<<endl;
	switch (choice)
	 {
		case 1://若choice为1
		     bub(numbers);//使用冒泡排序
		     cout<< "Bubble Sort"<<endl;
			break;
		case 2://若choice为2
			ins(numbers);//使用插入排序
			cout<<"Insert Sort"<<endl;
			break;
		case 3://若choice为3
			sel(numbers);//使用选择排序
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

