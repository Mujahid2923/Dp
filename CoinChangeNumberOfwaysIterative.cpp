///https://codeforces.com/problemset/problem/431/C

#include<bits/stdc++.h>
using namespace std;

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          eb                     emplace_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          scln3(x,y,z)           scanf("%lld %lld %lld",&(x),&(y),&(z))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
//#define          input                  freopen("input.txt","rt", stdin)
//#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     acos(-1.0)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Min(v)                 *min_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
#define          DBG                    cout << endl << "---------------" << endl ;
#define segment_tree int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;


ll t, T, n, k, d, m, a, b, x ;

void Reset() {}

vector < ll > v( 100005 ) ;

void Input()
{
    cin >> n >> k >> d ;
}

ll A[ 105 ] ;
ll B[ 105 ] ;

void Calculation()
{
    A[ 0 ] = 1 ;
    B[ 0 ] = 1 ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= k ; j ++ )
        {
            if( i >= j )
            {
                A[ i ] = ( A[ i ] + A[ i - j ] ) % MOD ;
            }
        }
    }

    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= k ; j ++ )
        {
            if( j < d && ( i - j ) >= 0 )
            {
                B[ i ] = ( B[ i ] + B[ i - j ] ) % MOD ;
            }
        }
    }
    cout << ( A[ n ] - B[ n ] + MOD ) % MOD << endl ;

}


void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    FaRaBi ;
    t = 1 ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }

    return 0 ;
}



..............................................*****.................................................

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
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
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
//#define          endl                   '\n'

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

vl v, v1, v2, v3 ;
vector < pll > vec, vec1, vec2 ;
vector < ll > adj[ 200000 + 5 ] ;
map < ll, ll > Mp, Mp2 ;
set < ll > st, st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;
multiset < ll > :: iterator it ;

ll n, a, total ;
ll DP[ 10 ][ 100005 ] ;

void calcultion()
{
    for( int i = 0 ; i <= v.size() ; i ++ )
    {
        DP[ i ][ 0 ] = 1 ;
    }

    for( int i = 1 ; i <= v.size() ; i ++ )
    {
        for( int j = 1 ; j <= total ; j ++ )
        {
            if( j >= v[ i - 1 ] )
            {
                DP[ i ][ j ] = DP[ i - 1 ][ j ] + DP[ i ][ j - v[ i - 1 ] ] ;
            }
            else
            {
                DP[ i ][ j ] = DP[ i - 1 ][ j ] ;
            }
        }
    }
    cout << DP[ v.size() ][ total ] << endl ;
}

int main()
{
    CIN ;
    cin >> n ;
    for( int i = 0 ; i < n ; i ++ )
    {
        cin >> a ;
        v.pb( a ) ;
    }
    cin >> total ;
    calcultion() ;

    return 0 ;
}

///Always check for n = 1

/*
3
1 2 3
5
*/
