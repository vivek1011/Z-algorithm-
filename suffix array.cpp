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
bool cmp(struct s1 a, struct s1 b)
{
	return a.nr[0]==b.nr[0] ? (a.nr[1]<b.nr[1]) : (a.nr[0]<b.nr[0]); 
}
void fun()
{
	for(int i =0;i<n; i++)
		P[0][i] = s[i] - 'a';
	int stp , cnt ; 
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
	// basically suffix starting at ith position will come at P[stp-1][i] th postion after sorting all the suffix strings. 
	for(int i=0 ; i<n; i++)
	cout<<P[stp-1][i]<<" ";
	return ;
}
int main()
{
	//std::ios_base::sync_with_stdio(false);
	cin>>s; 
	n= s.size();
	fun(); 
	return 0;
}
