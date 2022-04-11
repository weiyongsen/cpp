/*
输入样例 1：
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
输出样例 1：
Insertion Sort
1 2 3 5 7 8 9 4 6 0


输入样例 2：
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
输出样例 2：
Heap Sort
5 4 3 1 0 2 6 7 8 9
*/ 



#include <bits/stdc++.h>
using namespace std;
int f,n,li,m;
int a[110];
int b[110];
int c[110];
/*
   a[]，进行排序的操作函数
   b[]，用于保存原始数据，
   c[]，保存期待的排序函数
*/
void charu() //进行插入排序的判断；
{
    int j,t,f1;
    for(li=1; li<n; li++)
    {
        t=a[li+1];
        for(j=li+1; j>1; j--)
        {
            if(t<a[j-1])
            {
                a[j]=a[j-1];
            }
            else
                break;
        }
        a[j]=t;
        f1=1;
        for(j=1; j<=n; j++)
        {
            if(a[j]!=c[j])
            {
                f1=0;
                break;
            }
        }
        if(f1==1)
        {
            f=1;
            break;
        }
    }
}

void Heap(int k) //进行堆排序的判断；
{
    /*
       堆的下调函数，给定节点编号k，进行下调
    */
    int i=k;
    while(i<=m/2)
    {
        int t;
        if(a[2*i]>a[i])
            t=2*i;
        else
            t=i;
        if(2*i+1<=m&&a[2*i+1]>a[t])
            t=2*i+1;
        if(t!=i)
        {
            a[0]=a[i];//以a[0]作为交换变量
            a[i]=a[t];
            a[t]=a[0];
            i=t;
        }
        else
        {
            return;
        }
    }
}

int main()
{
    int i,j,t;
    scanf("%d",&n);
    m=n;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    for(i=1; i<=n; i++)
        scanf("%d",&c[i]);
    f=0;
    charu();
    if(f==1)  //当f==1时，为插入排序；
    {
        printf("Insertion Sort\n");
        li++;
        t=a[li+1];
        for(j=li+1; j>1; j--)
        {
            if(t<a[j-1])
            {
                a[j]=a[j-1];
            }
            else
                break;
        }
        a[j]=t;
        for(i=1; i<n; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    else  //否则是堆排序；
    {
        printf("Heap Sort\n");
        for(i=1; i<=n; i++)
            a[i]=b[i];
        for(i=n/2; i>=1; i--)
            Heap(i);
        m=n;
        for(i=1; i<n; i++)
        {
            t=a[1];
            a[1]=a[m];
            a[m]=t;
            m--;
            Heap(1);
            int flag=1;
            for(j=1; j<=n; j++)
            {
                if(a[j]!=c[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                t=a[1];
                a[1]=a[m];
                a[m]=t;
                m--;
                Heap(1);
                break;
            }
        }
        for(i=1; i<n; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}




