///Uva481
#include<bits/stdc++.h>
using namespace std;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define          min3(a,b,c)            min( { a, b , c } )
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
#define segment_trele int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;

vector < ll > v1, v2, v3 ;
map < ll, ll > Mp ;
ll n ;

void Fun()
{
    ll n = v1.size() ;
    ll LIS[ n + 2 ] ;
    LIS[ 0 ] = 0 ;

    v2.eb( v1[ 0 ] ) ;
    for( int i = 1 ; i < n ; i++ )
    {
        if( v1[ i ] > v2.back() )
        {
            LIS[ i ] = v2.size() ;
            v2.eb( v1[ i ] ) ;
        }
        else
        {
            int pos = Lower( v2, v1[ i ] ) ;
            LIS[ i ] = pos ;
            v2[ pos ] = v1[ i ] ;
        }
    }

    ll k = v2.size() - 1 ;
    for( int i = n - 1 ; i >= 0 ; i -- )
    {
        if( LIS[ i ] == k )
        {
            v3.eb( v1[ i ] ) ;
            k -- ;
        }
    }
}

int main()
{
    ll a ;
    while( scln( a ) != EOF )
    {
        v1.pb( a ) ;
        Mp[ a ] = -1 ;
    }

    Fun() ;

    reverse( all( v3 ) ) ;

    pf( "%d\n", v3.size() ) ;
    pf( "-\n" ) ;
    for( ll x : v3 )
    {
        pf( "%lld\n", x ) ;
    }
    return 0 ;
}


