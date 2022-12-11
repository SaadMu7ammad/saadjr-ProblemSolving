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
unsigned long long nCr(unsigned long long n, unsigned long long r) {
    if (r > n)
        return 0;
    r = max(r, n - r); //nCr(n,r) = nCr(n,n-r)
    unsigned long long ans = 1, div = 1, i = r + 1;
    while (i <= n) {
        ans *= i; 
        i++;
        ans /= div;// n! / [r!*(n-r)!] //div= (n-r)! 
        div++;
    }
    return ans;
}
unsigned long long nPr(unsigned long long n, unsigned long long r) {
    if (r > n)
        return 0;
    unsigned long long p = 1, i = n - r + 1;
    while (i <= n)// >> n!/(n-r)!
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

    return (num * factorial(num - 1)) % LONG_MAX;
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
ll sumMultiples(ll n, ll num) {//calc the sum of multiples of num from num to n (مضاعفات الرقم حتي ان )
    n = n / num;
    return (n * (n + 1)) / 2 * num;
}


//cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

string addBigNumbers(string number1, string number2 = "9999") {
    if (number1.length() > number2.length())//make num1 is the lower length and num2 is the higher
        swap(number1, number2);
    string sum = "";
    int len1 = number1.length();
    int len2 = number2.length();
    int digitDiff = len2 - len1;
    int carry = 0;
    int intSum;
    for (int i = len1 - 1; i >= 0; i--) {
        intSum = ((number1[i] - '0') + (number2[i + digitDiff] - '0') + carry);//the digitdiff make the digit for num2 is the last digit from right(i=len-1) and so on --i
        sum.push_back(intSum % 10 + '0');//to char then push
        carry = intSum / 10;
    }
    for (int i = digitDiff - 1; i >= 0; i--) {//add the rest of the len2 which is the bigger one in length 
        intSum = ((number2[i] - '0') + carry);
        sum.push_back(intSum % 10 + '0');
        carry = intSum / 10;
    }
    if (carry)
        sum.push_back(carry + '0');
    reverse(sum.begin(), sum.end());
    return sum;
}

string multiply(string num1, string num2 = "9999")
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    vector<int> result(len1 + len2, 0);

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--)//two loops coz each digit multiplied in the whole other number
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';

            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

            carry = sum / 10;

            result[i_n1 + i_n2] = sum % 10;//result is the summation of each row =(each loop)

            i_n2++;
        }

        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        i_n1++;
    }

    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)//remove the right zeros
        i--;

    if (i == -1)
        return "0";

    string s = "";

    while (i >= 0)//flip the num
        s += std::to_string(result[i--]);

    return s;
}
 int arr[11][11];
 int n; int m;

 int valid(int i,int j) {
     if (i >= n || j >= m) {
         return 0;
     }
     return 1;
 }
int mx( int i=0,int j=0) {//another sol but not clear as below
    if (!valid(i, j))
    {
        return INT_MIN; 
    }else if (i == n-1 && j == m-1)
    {
        return arr[i][j];
    }
    else if (valid(i, j)) {
        int right = mx(i, j + 1);

        int down = mx(i + 1, j);

        return arr[i][j]+ max(right, down);
   }
}
ll maxi = INT_MIN;
void  f(ll i=0, ll j=0, ll sum=arr[0][0])//not my sol>> but make little changes to see if it acc or not Xd 
                                            // the most good and readable idea to be easy to who get WA all the time :(
{
    if (i == n - 1 && j == m - 1) {//reach end
        maxi = max(maxi, sum);//filter pathes using the max one sum
        return;
    }
    if (i == n - 1 && j < m - 1) {//reach end of column only so it goes right
        f(i, j + 1,  sum + arr[i][j + 1]);
    }
    else if (i < n - 1 && j == m - 1) {//reach end of row only so it goes down
        f(i + 1, j,  sum +arr[i + 1][j]);
    }
    else 
    {//goes right and down 
        f(i, j + 1,  sum + arr[i][j + 1]);
        f(i + 1, j, sum + arr[i + 1][j]);
    }
}

int main()
{
sonic;
 cin >> n;
 cin >> m;
lup(i, 0, n) {
    lup(j, 0, m) {
        cin >> arr[i][j];
    }
}
f();
cout << maxi;
}
