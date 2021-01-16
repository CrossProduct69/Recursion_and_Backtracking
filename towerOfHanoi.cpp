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


//assume the top most disk is 1, next is 2 and so on...
void towerOfHanoi(int disk,char A,char C,char B)
{
    if(disk==1)
    {
        cout<<"move disk 1 from "<<A<<" to "<<C<<endl;
    }
    else
    {
        towerOfHanoi(disk-1,A,B,C);
        cout<<"move disk "<<disk<<" from "<<A<<" to "<<C<<endl;
        towerOfHanoi(disk-1,B,C,A);
    }
    
}

void solve()
{
	
    int disk;
    cin>>disk;

    towerOfHanoi(disk,'A','C','B');


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