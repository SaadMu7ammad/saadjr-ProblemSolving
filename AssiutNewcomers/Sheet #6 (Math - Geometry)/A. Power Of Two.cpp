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
void primefactors(long long num) {
    //Math_wk6_assiut
    if (num == 1 || num == 0)return;
    lup(i, 2, (i * i) + 1) {
        while (num % i == 0) {
            cout << i << " ";
            num /= i;
        }
    }
}
int fib(int n) {
    if (n == 1)return 0;
    if (n == 2)return 1;
    return fib(n - 1) + fib(n - 2);
}
//int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
//int dy[8] = { 1,-1,0,0,1,-1,-1,1 };
//int dx[4] = { 0,0,1,-1};
//int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,1 };//right and down only
int dy[4] = { 1,0 };
int visited[110][110];
bool ok(int x, int y, int n) { return x >= 0 && y >= 0 && x < n&& y < n; }//check is in or not

int main()
{
    sonic;
    unsigned ll num; cin >> num;
    unsigned ll res = log2(num);
    if (pow(2, res) == num) {
        cout << "YES";
    }
    else cout << "NO";
    //cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

}