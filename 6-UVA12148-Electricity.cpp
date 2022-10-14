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

int checkleap(int year) {
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}
int main()
{ 
    sonic;
   // cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    int arr[13]{
    arr[0] = 0,
    arr[1] = 31,
    arr[2] = 28,//leap=29
    arr[3] = 31,
    arr[4] = 30,
    arr[5] = 31,
    arr[6] = 30,
    arr[7] = 31,
    arr[8] = 31,
    arr[9] = 30,
    arr[10] = 31,
    arr[11] = 30,
    arr[12] = 31
    };
    while (true) {
        int q;
        cin >> q;
        if (q == 0)break;
        int prevd, prevm, prevy, prevc;
            cin >> prevd >> prevm >> prevy >> prevc;
            --q;
            int TOTAL = 0;
            int TOTALDAYS = 0;
        while (q--) {
            int d, m, y, c;
            cin >> d >> m >> y >> c;
            if (d == prevd + 1 && m == prevm && y == prevy) {
                TOTAL += (abs(prevc - c));
                ++TOTALDAYS;
            }
            if (prevm == 2 && prevd == 29&&d == 1 && y == prevy&& m==3&&checkleap(y)==1) {//leap year
                TOTAL += (abs(prevc - c));
                ++TOTALDAYS;
            }
            if (prevm == 2 && prevd == 28&&d == 1 && y == prevy&& m==3 && checkleap(y) == 0) {//not leapyear
                TOTAL += (abs(prevc - c));
                ++TOTALDAYS;
            }
            if (prevm == 12 && prevd == 31 &&d == 1 && y == prevy+1 &&m==1) {//end of year
                TOTAL += (abs(prevc - c));
                ++TOTALDAYS;
            }
            if (prevd == arr[prevm] && d == 1 && y == prevy && m == prevm+1&&prevm!=2) {//end of each month except febraury
                TOTAL += (abs(prevc - c));
                ++TOTALDAYS;
            }
            prevd = d;
            prevm = m;
            prevy = y;
            prevc = c;
        }
        cout <<TOTALDAYS<<" " << TOTAL << "\n";
    }
    return 0;
}
