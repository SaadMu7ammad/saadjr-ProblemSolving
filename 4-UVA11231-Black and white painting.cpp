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

int main()
{
    sonic();
    while (true) {
        long long r, c, w;
        cin >> r >> c >> w;
        if (r ==0&& c ==0&& w == 0)break;
        //the commented below is a very common mistake that we must add the extra according to the corner chess white or not 
       // long long tmp = (1 + (r - 8)) * (1 + (c - 8)) / 2;
        long long tmp = (1 + (r - 8)) * (1 + (c - 8)) ;
            if (w== 0) {
                cout << tmp/2 <<"\n";
            }
            else {
                cout << (tmp+1)/2 << "\n";
            }
    }
    return 0;
}
