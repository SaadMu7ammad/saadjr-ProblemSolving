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

ll lcmarr(vector<ll>arr) {//get the lcm of the whole vector
   
    ll ans = arr[0];
    lup(i, 1, arr.size()) {
       //ans = (arr[i]* ans) / gcd(ans, arr[i]);
        ans = lcm(ans, arr[i]);
    }
    return ans;
}
ll count_divisibility(ll L, ll R, ll n) {
    ll x, y;
    if (L % n == 0) {
        x = L / n ;//floor
    }
    else {
        x = L / n+1;//ceil
    }
    y = R / n;//floor
                       // cout << "Left: " << x << "\n"; // cout << "Right: " << y << "\n";
    return y - x + 1;//Inclusion-Exclusion 
}

int main()
{ 
  //first of all i would say that this is NOT AN EASY MATH at all :)
// thanks to the creator of this tutorial >> https://www.youtube.com/watch?v=2TijUJXvyGw&ab_channel=TechTalk
    sonic;
   // cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

    ll q; cin >> q;
    while (q--) {

        ll n, m, a, d;
        cin >> n >> m >> a >> d; 
        ll c0, c1, c2, c3, c4;
        ll arr[5];

        ll ans=0;
        lup(i, 0, 5) {
            arr[i] = a + i * d;
            ans += count_divisibility(n,m,arr[i]);// sum all of subsets with the repeated (intersections)(Not Filtered Yet) 
        }                               // so the remain part is to filter this value by remove the intersections (apply the principle)
                                        // a U b U c U d U e
                                        
      //Now the even Part is subtract
        vector<ll>two;
        lup(i, 0, 5) {
            lup(j, i+1, 5) {
                two = { arr[i],arr[j] };//combinations of numbers(couple)
                ll lcm = lcmarr(two);//lcm of each pair
                ans -= count_divisibility(n,m,lcm);
            }
        }

        //Now the odd Part is a plus
        vector<ll>three;
        lup(i, 0, 5) {
            lup(j, i + 1, 5) {
                lup(k, j + 1, 5) {
                    three = { arr[i],arr[j],arr[k] };//combinations of numbers(couple)
                    ll lcm = lcmarr(three);//lcm of each pair
                    ans += count_divisibility(n, m, lcm);
                }
            }
        }

        //Now the even Part is a sub
        vector<ll>four;
        lup(i, 0, 5) {
            lup(j, i + 1, 5) {
                lup(k, j + 1, 5) {
                    lup(q, k + 1, 5) {
                        four = { arr[i],arr[j],arr[k] ,arr[q]};//combinations of numbers(couple)
                        ll lcm = lcmarr(four);//lcm of each pair
                        ans -= count_divisibility(n, m, lcm);
                    }
                }
            }
        }
        vector<ll>five;//all
        five = { arr[0],arr[1],arr[2] ,arr[3],arr[4]};
        ll lastAllintersections = lcmarr(five);
        ans += count_divisibility(n, m, lastAllintersections);
        cout << (m-n+1)-ans<<"\n";//count all numbers between m&n then subtract from it the ans
                                // ans is the count of num divisible by the combination of the array we created the loop for 
    }

    return 0;
}
