//Source - http://codeforces.com/blog/entry/3107
// gift of raksha bandhan insomnia qualifier codechef. 
#include<bits/stdc++.h>
using namespace std;
#define S(x) scanf("%d",&x)
#define P(x) printf("%d",x)
#define fl(i , a, b) for(i = a; i<b; i++)
#define MOD 1000000007
#define MAX 1000000010
#define ll long long
#define mp make_pair
#define pb push_back
typedef pair<int,int> pp;
string s; 
int n , z[5000002]; 
void fun()
{
	int i; 
	z[0] = 0 ; 
	n = s.size();
	int L = 0 , R= 0 ; 
	fl(i , 1, n)
	{
		if(i>R){
			L = R = i ; 
			while(R<n && s[R-L]==s[R]) R++; 
			z[i] = R-L ; R-- ;
		}
		else
		{
			int k= i -L; 
			if(z[k]<R-i+1){
				z[i] = z[k]; 
			}
			else{
				L= i ; 
				while(R<n && s[R-L]==s[R]) R++; 
				z[i] = R-L; R--; 
			}
		}
	}
}
int main()
{
	//std::ios_base::sync_with_stdio(false);
	cin>>s; 
	int i , m , p ; 
	fun(); 
	// fl(i , 0 , n ) cout<<z[i]<<" ";
	S(m); 
	fl(i , 0 , m)
	{
		S(p); 
		printf("%d\n",min(z[p] ,p));
	}
	return 0;
}
