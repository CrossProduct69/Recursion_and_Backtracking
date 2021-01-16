#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long
#define all(x)            (x).begin(),(x).end()
#define len(x)             (int)((x).size())
#define rep(i,a,b)        for(int i=a;i<b;i++)


#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front


const long long INF=1e18;

void permute(string &input,string &output,vector<int> &count,int level)
{
    if(level==len(input))
    {
        cout<<output<<endl;
    }
    else
    {
        for (int i = 0; i < len(input); i++)
        {
            /* code */
            if(count[i]==0)
            {
                continue;
            }
            else
            {
                output[level]=input[i];
                count[i]--;
                permute(input,output,count,level+1); // ek depth bhetore dhukchi
                count[i]++;
            }

            
        }
        
    }
    
}

void solve()
{
	string s;
    cin>>s;
    string final(len(s),'n');

    vector<int> count(len(s),1);
    permute(s,final,count,0);

    
    


}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int T=1;
	// cin>>T;
	while(T--) solve();

	return 0;
}