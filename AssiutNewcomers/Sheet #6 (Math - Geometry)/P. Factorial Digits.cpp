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
unsigned long long nCr(int n, int r) {
    if (r > n)
        return 0;
    r = max(r, n - r); //nCr(n,r) = nCr(n,n-r)
    unsigned long long ans = 1, div = 1, i = r + 1;
    while (i <= n) {
        ans *= i;
        i++;
        ans /= div;
        div++;
    }
    return ans;
}
unsigned long long nPr(int n, int r) {
    if (r > n)
        return 0;
    unsigned long long p = 1, i = n - r + 1;
    while (i <= n)
        p *= i++;
    return p;
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

    return (num * factorial(num - 1))%LONG_MAX;
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

bool isprime(ll num) {
    if (num == 1)return false;

    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0)return false;
    }
    return true;
}
void divisors(ll a) {
    vector<ll>arr;
    ll tot = 0;
    for (ll i = 1; i * i <= a; i++) {
        if (a % i == 0) {
            tot += i;
            arr.push_back(i);
            if (a / i != i) {
                arr.push_back(a / i);
                tot += a / i;
            }
        }
    }
    cout << tot;
}

ll sumMultiples(ll n,ll num) {//calc the sum of multiples of num from num to n (مضاعفات الرقم حتي ان )
    n = n / num;
    return (n * (n + 1)) / 2* num;
}
ll digits(ll n) {
    double res = 1;
    lup(i, 1, n + 1) {
        res += log10(i);
    }
    
    return res;
}
//cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
int main()
//https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/P
{sonic;
ll n; cin >> n;
ll res = 1;
ll digitsnum = 0;
for (int i = 2; i <= n; i++)
{
    res *= i;
    while (res > 1e10)//1e10 is a chosen val just to be away from overflow
        digitsnum++, res /= 10;//minimze the res and save the removed digits in digitsnum
}
string num = to_string(res);
//two solutions 

cout << "Number of digits of " << n << "! is " << digitsnum + num.length();
//Math way 
//cout<< "Number of digits of "<<n<<"! is "<<digits(n);

}
