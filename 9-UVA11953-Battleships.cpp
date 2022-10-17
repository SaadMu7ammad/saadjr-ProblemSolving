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
//int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
//int dy[8] = { 1,-1,0,0,1,-1,-1,1 };
//int dx[4] = { 0,0,1,-1};
//int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,1 };//right and down only
int dy[4] = { 1,0 };
char arr[110][110];
int visited[110][110];
bool ok(int x, int y,int n) { return x >= 0 && y >= 0 && x < n&& y < n; }//check is in or not
int glob_c = 0; bool get_inside = false;
void searchright(int n, int i, int j) {
    lup(k, 0, 1) {
        int cx = i + dx[k];
        int cy = j + dy[k];
        if (ok(cx, cy, n) && visited[cx][cy] == 0 && arr[i][j] != '.') {
            visited[cx][cy] = 1;
            get_inside = true;
            searchright(n, cx, cy);
        }
        else if (arr[i][j] == '.' || visited[i][j]) {
            return;
        }
    }
}
void searchdown(int n, int i, int j) {
    lup(k, 1, 2) {
        int cx = i + dx[k];
        int cy = j + dy[k];
        if (ok(cx, cy, n) && visited[cx][cy] == 0 && arr[i][j] != '.') {
            visited[cx][cy] = 1;
            get_inside = true;
            searchdown(n, cx, cy);
        }
        else if (arr[i][j] == '.' || visited[i][j]) {
            return;
        }
    }
}
void search(int n, int i, int j) {
    lup(k,0, 2) {
        int cx = i + dx[k];
        int cy = j + dy[k];
        if (ok(cx, cy,n)&&visited[cx][cy]==0&&arr[i][j]!='.') {
            visited[cx][cy] = 1;
            get_inside = true; //to check that its first time
            search(n, cx, cy);
            //the constraints in problem that ship is only horizontal or vertical 
            //if founded at k=0 means that besides it so mean the rest of the ship is horizontalso goes right
            if (k == 0&&get_inside) {//right
                searchright(n, cx, cy);
            }
            //if founded at k=1 means that besides it so mean the rest of the ship is vertical so goes down
            else if (k == 1&&get_inside) {//down
                searchdown(n, cx, cy);
            }
        }
        else if (arr[i][j] == '.' || visited[i][j]) {
            return;
        }
    }
}
int main()
{ 
    //problem could solved in normal dfs >> https://ideone.com/DmVZPs
    sonic;
   // cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    int q; cin >> q;
   lup (Q,1,q+1) {
        memset(visited, 0, sizeof(visited));
        glob_c = 0;
        get_inside = false;
        int n; cin >> n;
        lup(i, 0, n) {
            lup(j, 0, n) {
                cin >> arr[i][j];
            }
        }
        lup(i, 0, n) {
            lup(j, 0, n) {
                if ( arr[i][j] == 'x'&& visited[i][j]==0) {
                    ++glob_c;
                    search(n, i, j);
                }
            }
        }
        cout << "Case "<<Q<<": "<< glob_c << "\n";
    }
    return 0;
}
