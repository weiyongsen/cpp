//给定一个最大容量为 M 的堆栈，
//将 N 个数字按 1, 2, 3, ..., N 的顺序入栈，
//允许按任何顺序出栈，则哪些数字序列是不可能得到的？
//例如给定 M=5、N=7，则我们有可能得到{ 1, 2, 3, 4, 5, 6, 7 }，
//但不可能得到{ 3, 2, 1, 7, 5, 6, 4 }。

//输入格式：
//输入第一行给出 3 个不超过 1000 的正整数：
//M（堆栈最大容量）、N（入栈元素个数）、K（待检查的出栈序列个数）
//最后 K 行，每行给出 N 个数字的出栈序列。所有同行数字以空格间隔。
//
//输出格式：
//对每一行出栈序列，如果其的确是有可能得到的合法序列，就在一行中输出YES，否则输出NO。
//

//输入样例：
//5 7 5
//1 2 3 4 5 6 7
//3 2 1 7 5 6 4
//7 6 5 4 3 2 1
//5 6 4 3 7 2 1
//1 7 6 5 4 3 2

//输出样例：
//YES
//NO
//NO
//YES
//NO

#include <bits/stdc++.h>

using namespace std;


int main()
{

    int n, m, k;
    cin >> m >> n >> k;

    for (int i = 0; i < k; i++)
    {

        int num[1000];
        int flag = n;
        bool isOk = true;
        stack<int> shelves;

        for (int k = n - 1; k >= 0; k--)
            cin >> num[k];

        int j = 0;
        while (j < n)
        {
            if (!shelves.empty() && shelves.top() == flag)
            {
                flag--;
                shelves.pop();
            } else
            {
                if (num[j] == flag && shelves.size() < m)
                {
                    flag--;

                } else
                {
                    if (shelves.size() >= m)
                    {
                        isOk = false;
                        break;
                    } else
                    {
                        shelves.push(num[j]);
                    }
                }
                j++;
            }


        }

        if (!shelves.empty() && isOk)
        {
            int size = shelves.size();
            for (int l = 0; l < size; ++l)
            {
                if (shelves.top() == size - l)
                {
                    shelves.pop();
                } else
                {
                    isOk = false;
                    break;
                }
            }
        }
        if (isOk)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}



