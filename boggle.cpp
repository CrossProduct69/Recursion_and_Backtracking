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

vector<int> pathRow={0, 0, 1, 1, -1, 1, -1, -1};
vector<int> pathCol={ 1, -1, -1, 1, 1, 0, 0, -1 };

bool isValid(int rowNew,int colNew,bool visited[][3])
{
    if((rowNew>=0)&&(colNew>=0)&&(rowNew<3)&&(colNew<3)&&(!visited[rowNew][colNew]))
    {
        return true;
    }
    return false;
}

void FindWord(char board[][3],bool visited[][3],int row,int column,string word,vector<string> englishDictionary)
{
    if(count(all(englishDictionary),word))
    {
        cout<<word<<endl;
    }
    if(len(word)==9)
    {
        return;
    }
    for (int i = 0; i < len(pathRow); i++)
    {
        /* code */
        int rowNew=row+pathRow[i];
        int colNew=column+pathCol[i];
        if(isValid(rowNew,colNew,visited))
        {
            visited[rowNew][colNew]=true;
            FindWord(board,visited,rowNew,colNew,word+board[rowNew][colNew],englishDictionary);
            visited[rowNew][colNew]=false;
        }
    }
    
}

void solve()
{
	
    char board[][3] =                   {{'G','I','Z' },
                                        {'U','E','K' },
                                        {'Q','S','E' }};


    bool visited[][3] =              {{false,false,false },
                                    {false,false,false },
                                    {false,false,false } };

    string word="";

    vector<string> englishDictionary={"GEEKS", "QUIZ", "FOR", "GO", "EUGE"};
    for (int row = 0; row < 3; row++)
    {
            for (int col = 0; col < 3; col++)
            {
                    visited[row][col] = true;
                    FindWord(board, visited, 0, 0, word+board[row][col],englishDictionary);
                    visited[row][col] = false;
            }
    }
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
