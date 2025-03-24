#include <bits/stdc++.h>
using namespace std;
// ���庯�� ��ӡȫ����
void printPermutations(vector<int>& numbers, vector<int>& now, vector<bool>& used) 
{
	// usedΪʹ�ù�������
	// numbersΪ�������������
	// nowΪ�����������
    // ���now�Ĵ�С����numbers�Ĵ�С�����Ѿ�������һ�����������У������
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
    for (int i = 1; i <=numbers.size(); i++) // ������������
	 {
        if (!used[i-1]) // ����������û�б�ʹ��
		{
            used[i-1] = true;
            now.push_back(numbers[i-1]);
            printPermutations(numbers, now, used);
            now.pop_back(); // �Ƴ������ӵ�����
            used[i-1] = false;    // ���Ϊδʹ��
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
        // ����Ϊ0ʱ����
        if (m == 0) break;
        // �������������ӵ�numbers��
        if (m> 0) numbers.push_back(m);
    }
    while (true);
    // �����������������Ƿ���2��20֮��
    if (numbers.size() < 1 || numbers.size() > 20)
	 {
        cout << "The numbers Should be between 2 and 20." << endl;
        return 0;
    }
    cout << "Output" << endl;
    // ��ʼ����ǰ���к�ʹ�����
    vector<int> now;
    vector<bool> used(numbers.size(), false);
    // ����ȫ���к���
    printPermutations(numbers, now, used);
    cout << "End" << endl;
    system("pause");
    return 0;
}
