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

bool isprime(ll num) {
    if (num == 1)return false;

    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0)return false;
    }
    return true;
}

string primefactors(long long num) {
    //Math_wk6_assiut
    string empt = "";
    if (num == 1 || num == 0)return empt;
    lup(i, 2, (i * i) + 1) {
        bool flag = false;
        int c = 0;
        while (num % i == 0) {
            ++c;
            //cout << i << " ";
            num /= i;
            flag = true;
        }
        if (flag) {
            if (!empt.empty())empt += "*";
            empt += "(";
            empt += to_string(i);
            empt += "^";
            empt += to_string(c);
            empt+=")";
            flag = false;
        }
    }if (num >1) {//for testCase 123453153
                    /*
                    The Prime Factorization is:
                        2 x 3 x 3 x 13 x 224969

                        In Exponential Form:
                        2^1 x 3^2 x 13^1 x 224969^1

                        The prev code with this extra if 
                        make the output  2^1 x 3^2 x 13^1
                        without the last number  224969^1


                    */
        empt += "*";
        empt += "(";
        empt += to_string(num);
        empt += "^";
        empt += to_string(1);
        empt += ")";
    }
      
    return empt;
}
//cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
int main()
{ sonic;
 //https://codeforces.com/group/MWSDmqGsZm/contest/223338/problem/J
int x;
cin >> x;
if (isprime(x)) {
    cout << "(" << x << "^" << 1 << ")";
}
else cout<<primefactors(x);

return 0;
}
