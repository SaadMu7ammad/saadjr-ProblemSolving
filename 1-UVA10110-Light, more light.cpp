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
#define sonic() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
ll mini = 4444477777;
//ll num;
//void superlucky(ll start, ll sum) {
//    if (start > num*100)return ;//if the number become with 10 digits terminate the recursive calls
//    //to reduce the depth >> start > num*100
//    if (sum == 0 && start >= num) {
//        mini = min(mini, start);
//    }
//   // cout << start << " \n";
//    superlucky(start * 10 + 4,sum+1);//the 4 is a plus 
// //   cout << start << " \n";
//    superlucky(start * 10 + 7,sum-1);//the 7 is a minus
//   // cout << start << " \n";
//}
//ll sum = 0;
//
//unsigned  factorial(unsigned long long start, unsigned long long end) {
//  
//    if (start == end)return 1;
//    return start*factorial(start-1,end);  
//   
//}
unsigned long long factorial(unsigned long long num) {

    if (num == 1 || num == 0)return 1;

    return num * factorial(num - 1);
}

unsigned  comb(ll n,  ll r) {

    if (n < r) {
        return 0;
    }
    if (r == 0) {
        return 1;
    }
    if (r == 1) {
        return n;
    }
    if (n == 1) {
        return 1;
    }
    return comb(n - 1, r - 1) + comb(n - 1, r);
    //5C3=(4C2)+(4C3)=10

}
int fib(int n) {
    if (n == 1)return 0;
    if (n == 2)return 1;

   
    return fib(n - 1) + fib(n - 2);
}
void divisors(int n) {
    if (n == 1 || n == 2) {
        cout << "yes\n";
        return;
    }
}
int main()
{
    long long n;
    while (cin >> n && n != 0) {  
        long long sqr = sqrt(n);  
       //check perfect or not 4 is pefect 16 is perfect so on...
        //odd factors means led is on always 
        if ((sqr * sqr) == n) {
            cout << "yes\n";
        }
        else {
           cout << "no\n";
        }
    }
    return 0;
}
