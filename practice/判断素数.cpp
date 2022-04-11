#include <iostream>
#include <cmath>
using namespace std;
int isPrime(long n)
{
    int k=0;
    k=sqrt(n);
    int i=0;
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    for (i=2;i<=k;i++)
    {
        if(n%i)
            continue;
        else
            return 0;
    }
    return 1;
}
int main()
{
    long n=0;
    int m=0;			
    cin >> m;
    for(int i=0;i<m;i++)
    {
    	cin >> n;
        if(isPrime(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
