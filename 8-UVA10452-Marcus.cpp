//                     "اللــهــم ارزقنـــا الهـــدى و الســـداد"
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define loop(start, n) for (ll i = start; i < n; i++)
#define lup(i,start,end) for (int i=(start) ; i<(end) ; i++)
#define ld(i,start,end) for (int i=(start) ; i>=(end) ; i--)
//#define endl "\n"
#define sonic ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()

long long gcd(long long a, long long b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
bool checkPrime(long long num) {
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0)return false;
    }
    return true;
}
bool sortbysec(pair< long long, long long> a, pair< long long, long long> b)
{
    if (a.second == b.second)
    {
        return (a.first > b.first);
    }
    return a.second > b.second;
}
int fibonacii(int indx) {
    if (indx == 1 || indx == 2)return 1;
    return fibonacii(indx - 1) + fibonacii(indx - 2);
}

unsigned long long factorial(unsigned long long num) {

    if (num == 1 || num == 0)return 1;

    return num * factorial(num - 1);
}

int fib(int n) {
    if (n == 1)return 0;
    if (n == 2)return 1;
    return fib(n - 1) + fib(n - 2);
}
int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,-1,1 };


bool ok(int x, int y,int n) { return x >= 0 && y >= 0 && x < n&& y < n; }//check is in or not


int main()
{ 
    sonic;
   // cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    int q; cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        char arr[10][10];
        string path = "IEHOVA#";
        int tracker = 0;
        pair<int, int> startpos;//x,y
        lup(i, 0, n) {
            lup(j, 0, m) {
                cin >> arr[i][j];
                if (arr[i][j] == '@') {
                    startpos.first = i;
                    startpos.second = j;
                }
            }
        }
        vector<string>op;//output
       for(int i=n-1;i>=0;i--) {
           for (int j =0; j <m; j++) {
                if (arr[i][j] ==path[tracker]) {
                    int diffx = (i - startpos.first);
                    int diffy = (j - startpos.second);
                    if (diffx == 0 && diffy > 0) {//right
                        while (diffy--)
                        {
                           //cout << "right";
                           op.push_back("right");
                        }
                        startpos.first = i;
                        startpos.second = j;
                        ++tracker;
                        i++;
                        j = 0;
                        continue;
                    }

                    else if (diffx == 0 && diffy < 0) {//left
                        int temp = abs(diffy);
                        while (temp--)
                        {
                            op.push_back("left");
                        }
                        startpos.first = i;
                        startpos.second = j;
                        ++tracker;
                       i++;
                       j = 0;
                       continue;
                    }
                    else if (diffx < 0 && diffy ==0) {//forth
                        int temp = abs(diffx);
                        while (temp--)
                        {
                            op.push_back("forth");
                        }
                        startpos.first = i;
                        startpos.second = j;
                        ++tracker;
                        i++;
                        j = 0;
                        continue; 
                    }
                }                
            }
        }
       cout << op[0];
       lup(i, 1, op.size())cout << " " << op[i];
       cout << endl;
    }
    return 0;
}
