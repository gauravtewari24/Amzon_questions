/* // C++ implementation to find k numbers with most
// occurrences in the given array
#include <bits/stdc++.h>

using namespace std;

// Driver program to test above
int return_x(int arr[], int n)
{
    int mini = INT_MAX, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mini = min(sum, mini);
    }
    int x = 0;
    if (mini < 1)
    {
        x = abs(mini) + 1;
    }
    return x;
}

int main()
{
    int arr[] = {-5, 4, -2, 3, 1, -1, -6, -1, 0, 5};
    int n = 4;

    cout << return_x(arr, n);
}
 */

#include <bits/stdc++.h>
using namespace std;

bool check(int a[], int num)
{

    bool ans = true;

    while (num > 0)
    {
        int temp = num % 10;
        ans = ans & (a[temp]);
        num /= 10;
    }

    return ans;
}

int count_digit(int i)
{
    int ans = 0;

    while (i > 0)
    {
        ans++;
        i /= 10;
    }

    return ans;
}

int main()
{

    int t;
    cin >> t;

    for (int p = 1; p <= t; p++)
    {

        int a[10];

        for (int i = 0; i < 10; i++)
        {
            cin >> a[i];
        }

        int target;
        cin >> target;

        int dp[target + 1];

        memset(dp, INT_MAX, sizeof(dp));

        // for(int i=0;i<10;i++) {
        //     if(a[i] == 1) {
        //         dp[i] = 1;
        //     }
        // }

        if (check(a, target))
        {
            dp[target] = count_digit(target);
        }
        else
        {
            for (int i = 0; i <= target; i++)
            {

                if (check(a, i))
                {
                    dp[i] = count_digit(i);
                }
                else
                {
                    if (target % i != 0)
                        continue;
                    int temp = INT_MAX;

                    for (int j = 2; j <= sqrt(i); j++)
                    {
                        if (i % j == 0 && dp[i / j] != INT_MAX && dp[j] != INT_MAX)
                        {
                            temp = min(temp, dp[j] + dp[i / j] + 1);
                        }
                    }

                    dp[i] = temp;
                }
            }
        }
        // for(int i=0;i<=target;i++) {
        //     cout<<i<<" "<<dp[i]<<endl;
        // }

        if (dp[target] == INT_MAX)
        {
            cout << "Case #" << p << ": Impossible" << endl;
        }
        else
        {
            cout << "Case #" << p << ": " << dp[target] + 1 << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int vis[100001] = {0};
bool dfs(int x, int el)
{
    vis[x] = 1;
    for (int ch : v[x])
    {
        if (!vis[ch])
        {
            if (ch == el)
            {
                return true;
            }
            dfs(ch, el);
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
    }
    int m;
    cin >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int x, y;
    cin >> x >> y;
    if (dfs(x, y))
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
}

/*
int find(int s){
    if(p[s]==s)
        return s;
    return p[s]=find(p[s]);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;

*/

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v[1000001];

int main()
{

    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x] = INT_MAX;
    }

    int e;
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        v[x].push_back({y, d});
    }
    int src, dest;
    cin >> src >> dest;
    set<pair<int, int>> s;
    mp[src] = 0;
    s.insert({0, src});
    while (!s.empty())
    {
        pair<int, int> tmp = *(s.begin());
        s.erase(s.begin());
        int u = tmp.second;
        for (auto i = v[u].begin(); i != v[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (mp[v] > mp[u] + weight)
            {
                if (mp[v] != INT_MAX)
                    s.erase(s.find({mp[v], v}));
                mp[v] = mp[u] + weight;
                s.insert({mp[v], v});
            }
        }
    }
    cout << mp[dest];
}