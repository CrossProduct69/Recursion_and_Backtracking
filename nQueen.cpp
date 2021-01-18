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

bool isValid(vector<vector<int> > &board,int row,int col,int size)
{
    bool valid=true;

    rep(i,0,size)
    {
        if(board[i][col])
        {
            valid=false;
        }
    }
    for (int i = row,j=col; i >= 0 && j>=0; i--,j--)
    {
        /* code */
        if(board[i][j])
        {
            valid=false;
        }
    }

    for (int i = row,j=col; i >= 0 && j<size; i--,j++)
    {
        /* code */
        if(board[i][j])
        {
            valid=false;
        }
    }
    
    return valid;
}

bool nQueen(vector<vector<int> > &board,int size,int row)
{
    //base case
    if(row==size-1)
    {
        rep(i,0,size)
        {
            /* code */
            rep(j,0,size)
            {
                /* code */
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return true; //if you want only one solution , comment this line and uncomment next line to get all the possible combinations  
        // cout<<"-----------------------------"<<endl;
        
    }

    else
    {
        
        rep(col,0,size)
        {
            int newRow=row+1;
            if(isValid(board,newRow,col,size))
            {
                board[newRow][col]=1;
                if(nQueen(board,size,newRow))
                {
                    return true;
                }
                board[newRow][col]=0;

            }
        }
        
    }
    return false;
    
}


void solve()
{
	
    int size;
    cin>>size;
    vector<vector<int> > board(size,vector<int> (size,0));

    nQueen(board,size,-1);
    
    
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