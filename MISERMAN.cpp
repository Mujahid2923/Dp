///https://www.spoj.com/problems/MISERMAN/en/
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
#define segment_trele int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;


ll row, col ;
ll arr[ 105 ][ 105 ] ;
ll dp[ 105 ][ 105 ] ;

bool ck( int i, int j )
{
    if( i >= 0 && j >= 0 && i < row && j < col )
    {
        return true ;
    }
    return false ;
}

ll Fun( ll i, ll j )
{
    if( dp[ i ][ j ] != -1 )
    {
        return dp[ i ][ j ] ;
    }
    else
    {
        ll r1 = INT_MAX, r2 = INT_MAX, r3 = INT_MAX ;

        if( ck( i + 1, j - 1 ) ) r1 = Fun( i + 1, j - 1 ) ;
        if( ck( i + 1, j ) ) r2 = Fun( i + 1, j ) ;
        if( ck( i + 1, j + 1 ) ) r3 = Fun( i + 1, j + 1 ) ;

        ll r4 = 0 ;
        if( min3( r1, r2, r3 ) != INT_MAX )
        {
            r4 = min3( r1, r2, r3 ) ;
        }
        return dp[ i ][ j ] = arr[ i ][ j ] + r4 ;
    }
}

int main()
{
    scln2( row, col ) ;
    for( int i = 0 ; i < row ; i ++ )
    {
        for( int j = 0 ; j < col ; j ++ )
        {
            scln( arr[ i ][ j ] ) ;
        }
    }
    ll ans = INT_MAX ;
    memset( dp, -1, sizeof dp ) ;
    for( int j = 0 ; j < col ; j ++ )
    {
        ans = min( ans, Fun( 0, j ) ) ;
    }

    pf( "%lld\n", ans ) ;
    return 0 ;
}


