#include <bits/stdc++.h>
using namespace std;
// 定义函数 打印全排列
void printPermutations(vector<int>& numbers, vector<int>& now, vector<bool>& used) 
{
	// used为使用过的数字
	// numbers为输入的所有数字
	// now为现在输出数字
    // 如果now的大小等于numbers的大小，则已经生成了一个完整的排列，输出它
    if (now.size() == numbers.size())
	 {
        for (int i = 0; i <now.size(); i++)
		 {
            cout << now[i];
            if (i != now.size() - 1) cout << ",";
        }
        cout << endl;
        return;
	 }
    for (int i = 1; i <=numbers.size(); i++) // 遍历所有数字
	 {
        if (!used[i-1]) // 如果这个数字没有被使用
		{
            used[i-1] = true;
            now.push_back(numbers[i-1]);
            printPermutations(numbers, now, used);
            now.pop_back(); // 移除最后添加的数字
            used[i-1] = false;    // 标记为未使用
        }
    }
}
int main()
 {
    vector<int> numbers;
    cout << "Input" << endl;
    do
	 {
        int m;
        cin >> m;
        // 输入为0时结束
        if (m == 0) break;
        // 将输入的数字添加到numbers中
        if (m> 0) numbers.push_back(m);
    }
    while (true);
    // 检查输入的数字数量是否在2到20之间
    if (numbers.size() < 1 || numbers.size() > 20)
	 {
        cout << "The numbers Should be between 2 and 20." << endl;
        return 0;
    }
    cout << "Output" << endl;
    // 初始化当前排列和使用情况
    vector<int> now;
    vector<bool> used(numbers.size(), false);
    // 调用全排列函数
    printPermutations(numbers, now, used);
    cout << "End" << endl;
    system("pause");
    return 0;
}
