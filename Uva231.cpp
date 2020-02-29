///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
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
#define          PI                     acos(-1.0)
//#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Min(v)                 *min_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;

vector < ll > v, v1, v2, v3, v4 ;
vector < pll > vec, vec1, vec2 ;
vector < pair < ll, pll > > vec3 ;
vector < ll > adj[ 200005 ] ;
map < ll, ll > Mp ;
map < pll, ll > Mp1, Mp2 ;
set < ll > st,st1,st2, st3 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < pll > S, S2 ;
multiset < ll > :: iterator it ;


int Fun()
{
    v2.clear() ;
    v2.pb( v1[ 0 ] ) ;

    for(int i = 1; i < v1.size(); i++)
    {
        if( v2.back() <= v1[ i ] )
        {
            v2.pb( v1[ i ] ) ;
        }
        else
        {
            int pos = Upper( v2, v1[ i ] ) ;
            v2[ pos ] = v1[ i ] ;
        }
    }
    return ( int ) v2.size() ;
}

int main()
{
    CIN ;
    int a, b, cnt = 0 ;
    while( cin >> a && a != -1 )
    {
        if( cnt > 0 )
        {
            printf( "\n" ) ;
        }
        cnt ++ ;
        v1.pb( a ) ;
        while( cin >> b && b != -1 )
        {
            v1.pb( b ) ;
        }
        int x = Fun() ;
        reverse( all( v1 ) ) ;
        int y = Fun() ;
        int z = max( x, y ) ;
        printf( "Test #%d:\n  maximum possible interceptions: %d\n", cnt , z ) ;
        v1.clear() ;
    }


    return 0 ;
}

