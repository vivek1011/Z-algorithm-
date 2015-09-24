// finding the longest common prefix between the sorted suffix strings.
// making of suffix array 
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
int P[100][10002]; 
string s; int n ; 
struct s1
{		
	int nr[2];
	int p; 
}L[10002];
int sa[100002] ,LCP[10002];
int stp , cnt;  
bool cmp(struct s1 a, struct s1 b)
{
	return a.nr[0]==b.nr[0] ? (a.nr[1]<b.nr[1]) : (a.nr[0]<b.nr[0]); 
}
void fun()
{
	for(int i =0;i<n; i++)
		P[0][i] = s[i] - 'a';
	for(stp = 1 ,cnt = 1 ;cnt<n ; cnt*=2, stp++)	
	{
		for(int i =0 ; i<n; i++)
		{
			L[i].nr[0] = P[stp-1][i];
			L[i].nr[1] = (i+cnt)<n ? P[stp-1][i+cnt] : -1; 
			L[i].p = i ;
		}
		sort(L , L+n , cmp);
		for(int i =0 ; i<n; i++)
		{
			P[stp][L[i].p] = i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1] ? P[stp][L[i-1].p] : i;
		}
	}	
	for(int i =0;  i<n; i++)
		sa[P[stp-1][i]] = i; 
	return ;
}
ll power(ll x,ll y)
{
	if(y==0) return 1;
	ll tmp = power(x,y/2); 
	if(y%2==0) return (tmp*tmp);
	return ((tmp*tmp))*x;
}
ll lcp(int i, int j)
{
	if(i==j) return n -i ;
	ll final =0 ; 
	for(int k =stp -1; k>=0 && i<n && j<n; k--)
	{
		if(P[k][i]==P[k][j]) // means at this point their suffix index was same, add 2^k chars to the final
		{
			ll ans = power(2,k);
			final+=ans ; i+=ans; j+=ans; 
		}
	} 
	return final;
}
void constlcp()
{
	for(int i =0 ; i<n-1; i++)
	{
		LCP[i] = lcp(sa[i] , sa[i+1]); 
	}
	return ; 
}
int main()
{
	//std::ios_base::sync_with_stdio(false);
	cin>>s; 
	n= s.size();
	fun(); 
	constlcp(); 
	for(int i =0 ;  i<n-1 ; i++)
		cout<<LCP[i]<<" ";
	cout<<endl;
	return 0;
}
