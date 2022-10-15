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
 char arr[25][25];
 bool seen[25][25];//instead of changing the arr val itself 


bool ok(int x, int y,int n) { return x >= 0 && y >= 0 && x < n&& y < n; }//check is in or not

void searcher(int i, int j, int n) {
    if (seen[i][j])
        return;
    seen[i][j] = 1;
    lup(k, 0, 8) {
        int xc = dx[k] + i;
        int yc = dy[k] + j;
        if (ok(xc, yc, n) != 0 && arr[xc][yc] == '1' && seen[xc][yc] == 0) {
            searcher(xc, yc, n);
        }
    }
}
int main()
{ 
    sonic;
   int globalc = 1;
   // cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    int n;
   while (cin >> n) {  
        memset(seen, 0, sizeof(seen));//clear the seen each case
        if (n == 0)return 0;
        int tot = 0;
        lup(i, 0, n) {
            lup(j, 0, n) {
                cin >> arr[i][j];
            }
        }
        lup(i, 0, n) {
            lup(j, 0, n) {
                if (arr[i][j] == '1'&&seen[i][j]==0) {
                    searcher(i, j, n);//detect all neighbours for any element=1
                    ++tot;//then all group detected become tot+1
                }
            }
        }
        cout<<"Image number "<<globalc++<<" contains "<<tot<<" war eagles.\n";
    }
    return 0;
}
