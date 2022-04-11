//����һ���������Ϊ M �Ķ�ջ��
//�� N �����ְ� 1, 2, 3, ..., N ��˳����ջ��
//�����κ�˳���ջ������Щ���������ǲ����ܵõ��ģ�
//������� M=5��N=7���������п��ܵõ�{ 1, 2, 3, 4, 5, 6, 7 }��
//�������ܵõ�{ 3, 2, 1, 7, 5, 6, 4 }��

//�����ʽ��
//�����һ�и��� 3 �������� 1000 ����������
//M����ջ�����������N����ջԪ�ظ�������K�������ĳ�ջ���и�����
//��� K �У�ÿ�и��� N �����ֵĳ�ջ���С�����ͬ�������Կո�����
//
//�����ʽ��
//��ÿһ�г�ջ���У�������ȷ���п��ܵõ��ĺϷ����У�����һ�������YES���������NO��
//

//����������
//5 7 5
//1 2 3 4 5 6 7
//3 2 1 7 5 6 4
//7 6 5 4 3 2 1
//5 6 4 3 7 2 1
//1 7 6 5 4 3 2

//���������
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



