//Author: rishab_1128

#include<bits/stdc++.h> 
using namespace std;
 
typedef string                         STR;
typedef long long                      ll;
typedef long double                    ld;
typedef unsigned long long             ull;
typedef vector<int>                    vi;
typedef priority_queue<int>            pqi;
typedef vector<ll>                     vll;
typedef vector<ull>                    vull;
typedef vector<STR>                    vs;
typedef vector<char>                   vc;
typedef pair<int,int>                  pii;
typedef pair<ll,ll>                    pll;
typedef pair<STR,int>                  psi;
typedef pair<char,ll>                  pcl;
typedef pair<int,STR>                  pis;
typedef vector<pii>                    vpii;
typedef vector<pll>                    vpll;
typedef vector<pcl>                    vpcl;
typedef map<int,int>                   mii;
typedef map<ll,ll>                     mll;
typedef map<STR,int>                   msi;
typedef map<char,int>                  mci;
typedef map<int,STR>                   mis;
typedef set<STR>                       ss;
typedef set<char>                      sc;
typedef set<int>                       si;
typedef set<ll>                        sll;
 
#define FF                             first
#define SS                             second
#define PB                             push_back
#define PF                             push_front
#define MP                             make_pair
#define all(a)                         (a).begin(), (a).end()
#define ps(x,y)                        fixed<<setprecision(y)<<x
#define setbits(x)                     __builtin_popcountll(x)
#define zrobits(x)                     __builtin_ctzll(x)
#define d2b(x,n)                       bitset<x>(n).to_string()
#define b2d(x,n)                       bitset<x>(n).to_ulong()
#define f(i,a,n)                       for(ll i=a; i<n; i++)                                      
#define f1(i,b,m)                      for(ll i=b; i<=m; i++)
#define f2(i,x,y)                      for(ll i=x; i>=y; i--)
#define fsort(a)                       sort(a.begin(), a.end())
#define rsort(a)                       sort(a.rbegin(), a.rend())
#define w(t)                           ll t; cin>>t; while(t--)
#define UB                             upper_bound
#define LB                             lower_bound
#define BS                             binary_search
#define EB                             emplace_back
#define Max(x,y,z)                     max(x,max(y,z))
#define Min(x,y,z)                     min(x,min(y,z))

const ll MOD     = 1000000007;
const ll SIZE    = 100000;
const int INF    = 0x3f3f3f3f;
const ll ll_INF  = 0x3f3f3f3f3f3f3f3f;
const ld PI      = acos(-1);
const ll MAXN    = numeric_limits<ll>::max();
const ll MAX     = 2000000;

//Using Recursion & Memoization(Bottom Up Approach)
int min_cost1(int **input,int si,int sj,int ei, int ej, int **dp)
{

	if(si==ei&&sj==ej) //Base Case 1
		return input[ei][ej];

	if(si>ei||sj>ej)  //Base Case 2
		return INT_MAX;

	if(dp[si][sj]!=-1)
		return dp[si][sj];

	int op1=min_cost1(input,si+1,sj,ei,ej,dp);
	int op2=min_cost1(input,si,sj+1,ei,ej,dp);
	int op3=min_cost1(input,si+1,sj+1,ei,ej,dp);

	return dp[si][sj]=input[si][sj]+Min(op1,op2,op3);
}

//Using Iteration(Top Down Approach-Filling the table)
int min_cost2(int **input,int n, int m)
{
	int ** dp = new int*[n];
	for (int i = 0; i < n; i++) 
	{
		dp[i] = new int[m];
	}

	dp[n-1][m-1]=input[n-1][m-1]; //dp[i][j] := It stores the min cost to go from (i,j) to (m,n)
    
    //Filling up last row
    for(int j=m-2; j>=0; j--)
    {
    	dp[n-1][j]=input[n-1][j]+dp[n-1][j+1];
    }

    //Filling up last col
    for(int i=n-2; i>=0; i--)
    {
    	dp[i][m-1]=input[i][m-1]+dp[i+1][m-1];
    }

    //Filling the rest of the table
    for(int i=n-2; i>=0; i--)
    {
    	for(int j=m-2; j>=0; j--)
    	{
    		dp[i][j]=input[i][j]+Min(dp[i+1][j],dp[i][j+1],dp[i+1][j+1]);
    	}
    }

    int ans=dp[0][0];
    
    for(int i=0; i<n; i++)
	{
		delete []dp[i];
	}
	delete []dp;

    return ans;
}

void solve()
{
	int n,m;
	cin>>n>>m;

	int **input=new int*[n];
	for(int i=0; i<n; i++)
	{
		input[i]=new int [m];
		for(int j=0; j<m; j++)
		{
			cin>>input[i][j];
		}
	}

	int **dp=new int*[n];
	for(int i=0; i<n; i++)
	{
		dp[i]=new int [m];
		for(int j=0; j<m; j++)
		{
			dp[i][j]=-1;
		}
	}

	int ans1=min_cost1(input,0,0,n-1,m-1,dp);
	int ans2=min_cost2(input,n,m);

	cout<<ans1<<endl;
	cout<<ans2<<endl;

	for(int i=0; i<n; i++)
	{
		delete []input[i];
		delete []dp[i];
	}

	delete []input;
	delete []dp;

}

int main()
{
	std::ios::sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
    return 0;
}