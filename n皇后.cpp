#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int a[20];               //第i个数表示在第i行的皇后所在的列数（从0开始）
bool check(int r, int c) //检查当前r行c列是否满足要求
{
    for (int i = 0; i < r; i++)
    {
        if (a[i] == c)
            return false;
        if (abs(r - i) == abs(c - a[i]))
            return false;
    }
    return true;
}
void NQueen(int m) //递归函数
{
    if (m >= n)
    {
        /*
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        */
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(m, i))
        {
            a[m] = i; //标记第m行皇后在第i列
            NQueen(m + 1);
        }
    }
}
int main()
{
    cin >> n;
    clock_t start, end;
    start = clock();
    NQueen(0);
    end = clock();
    cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
    cout << cnt;
    return 0;
}
