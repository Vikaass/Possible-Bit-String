#include<iostream>
#define ll long long
#define max 1000000007
using namespace std;

void multiply(ll A[2][2],ll B[2][2])
{

    ll w = ((A[0][0]%max)*(B[0][0]%max)%max + (A[0][1]%max)*(B[1][0]%max)%max)%max;
    ll x =((A[0][0]%max)*(B[0][1]%max)%max + (A[0][1]%max)*(B[1][1]%max)%max)%max;
    ll y =((A[1][0]%max)*(B[0][0]%max)%max + (A[1][1]%max)*(B[1][0]%max)%max)%max;
    ll z =((A[1][0]%max)*(B[0][1]%max)%max + (A[1][1]%max)*(B[1][1]%max)%max)%max;

    A[0][0] = w;
    A[0][1] = x;
    A[1][0] = y;
    A[1][1] = z;


}

void power(ll M[2][2],ll n)
{
    ll F[2][2]={
                 {1,1},
                 {1,0}
                };

    if (n == 0 || n == 1)
        return;
    else
    {
        power(M,n/2);

        if (n%2 == 0)
        {
            multiply(M,M); // n is even M^(n/2) x M^(n/2)
        }
        else
        {
            multiply(M,M); // b is odd M^(n/2) x M^(n/2) x M
            multiply(M,F);
        }
    }

}


ll count(ll n)
{

    if (n == 0)
        return 0;

    ll F[2][2]={
                 {1,1},
                 {1,0}
                };

    power(F,n-3);

    return (5*F[0][0]%max+3*F[0][1]%max)%max;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	ll n;
   	cin>>n;
   	if(n==2||n==3||n==1)
   	{
   		if (n==2)
   		{
		   cout<<"3"<<endl;
		   continue;}
   		else if(n==1)
   		{
   		    cout<<"2"<<endl;
   		    continue;
   		}
   		else
   		{
		cout<<"5"<<endl;
		continue;
		}
	   }
   	cout<<count(n)<<endl;
   }

    return 0;
}
