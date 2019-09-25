///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     3.141592653589793238462643
//#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())


///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
///sort( all( v ) ) ;

vi v, v1, v2 ;
map < char, int > mmp ;

int n, a, q ;
vector<int> P;

void Fun( string s )
{
    P.resize(3, 0);
    if( s[ 0 ] == 'W' )
    {
        P[0] = P[1] = P[2] = 1;
    }
    else if( s[ 0 ] == 'R' )
    {
        P[0] = 1;
    }
    else if( s[ 0 ] == 'G' )
    {
        P[1] = 1;
    }
    else
    {
        P[2] = 1;
    }

    for( int i = 1 ; i < s.size() ; i ++ )
    {
        vector<int> temp(3);
        if(s[i] == 'W')
        {
            temp[0] = (P[1] + P[2]) % MOD;
            temp[1] = (P[0] + P[2]) % MOD;
            temp[2] = (P[0] + P[1]) % MOD;
        }
        else if(s[i] == 'R')
            temp[0] = (P[1] + P[2]) % MOD;
        else if(s[i] == 'G')
            temp[1] = (P[0] + P[2]) % MOD;
        else
            temp[2] = (P[0] + P[1]) % MOD;

        P = temp;
    }
}

int32_t main()
{
    CIN ;
    string s ;
    cin >> q ;
    for( int i = 1 ; i <= q ; i ++ )
    {
        P.clear();
        cin >> s ;
        Fun( s ) ;
        int x  = 0;
        for(auto c: P)
            x = (x + c) % MOD;

        pf("Case %d: %d\n", i, x % MOD ) ;
    }
    return 0 ;
}

///problem link : https://algo.codemarshal.org/contests/icpc-dhaka-preli-18/problems/H
