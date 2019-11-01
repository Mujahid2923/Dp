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
///string s = std::bitset<64>(n).to_string();
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

vi v, v1, v2, v3 ;
vector < pll > vec, vec1, vec2 ;
vector < pii > adj[ 200000 + 5 ] ;
map < ll, ll > Mp, Mp2 ;
set < pii > st, st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;
multiset < ll > :: iterator it ;

int n, k ;
int DP[ 5 ][ 200005 ] ;
int a[ 200005 ] ;
int b[ 200005 ] ;

int Fun( int pos, int idx )
{
    if( pos < 0 )
    {
        return 0 ;
    }
    if( DP[ idx ][ pos ] != -1 )
        return DP[ idx ][ pos ] ;

    int r1 = 0, r2 = k ;
    r1 = a[ pos ] + Fun( pos - 1, 0 ) ;
    if( idx == 1 )
        r2 = 0 ;
    r2 += b[ pos ] + Fun( pos - 1, 1 ) ;
    return DP[ idx ][ pos ] = min( r1, r2 ) ;
}

int main()
{
    CIN ;
    cin >> n >> k ;

    for( int i = 0 ; i < n - 1 ; i ++ )
    {
        cin >> a[ i ] ;
    }

    for( int i = 0 ; i < n - 1 ; i ++ )
    {
        cin >> b[ i ] ;
    }

    memset( DP, -1, sizeof DP ) ;

    Fun( n - 1, 0 ) ;
    cout << "0 " ;
    for( int i = 0 ; i < n - 1 ; i ++ )
    {
        cout << DP[ 0 ][ i ] << " " ;
    }
    return 0 ;
}

-------------------Iterative-------------------------

int DP[ 2 ][ 200005 ] ;
int a[ 200005 ] ;
int b[ 200005 ] ;

int main()
{
    CIN ;
    int n, k ;
    cin >> n >> k ;
    for( int i = 1 ; i < n ; i ++ )
    {
        cin >> a[ i ] ;
    }

    for( int i = 1 ; i < n ; i ++ )
    {
        cin >> b[ i ] ;
    }

    DP[ 1 ][ 0 ] = INT_MAX ;
    for( int i = 1 ; i < n ; i ++ )
    {
        DP[ 0 ][ i ] = a[ i ] + min( DP[ 0 ][ i - 1 ], DP[ 1 ][ i - 1 ] ) ;
        DP[ 1 ][ i ] = b[ i ] + min( DP[ 0 ][ i - 1 ] + k, DP[ 1 ][ i - 1 ] ) ;
    }

    for( int i = 0 ; i < n ; i ++ )
    {
        cout << min( DP[ 0 ][ i ], DP[ 1 ][ i ] ) << " " ;
    }

    return 0 ;
}
