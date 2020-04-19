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

vector< int > v ;
bool prime[ 1125 ] ;
int n, k ;

void findPrime()
{
    int n = 1125 ;
    memset( prime, false, sizeof prime ) ;

    for( int i = 4 ; i <= n ; i += 2 )
    {
        prime[ i ] = true ;
    }

    prime[ 1 ] = true ;

    for( int i = 3 ; i * i <= n ; i += 2 )
    {
        if( !prime[ i ] )
        {
            for( int j = 2 ; i * j <= n ; j ++ )
            {
                prime[ i * j ] = true ;
            }
        }
    }

    for( int i = 1 ; i <= n ; i ++ )
    {
        if( !prime[ i ] )
        {
            v.push_back( i ) ;
        }
    }
}

int dp[ 200 ][ 1125 ][ 15 ] ;

int Fun( int pos, int sum, int cnt )
{
    if( sum == n && cnt == k ) return 1 ;
    if( sum == n && cnt != k ) return 0 ;


    if( v[ pos ] > n || sum > n || cnt == k ) return 0 ;
    if( dp[ pos ][ sum ][ cnt ] != -1 ) return dp[ pos ][ sum ][ cnt ] ;

    int r1 = 0 , r2 ;
    if( sum + v[ pos ] <= n )
    {
        r1 = Fun( pos + 1, sum + v[ pos ], cnt + 1 ) ;
    }
    r2 = Fun( pos + 1, sum, cnt ) ;

    return dp[ pos ][ sum ][ cnt ] = r1 + r2 ;
}

int main()
{
    findPrime() ;

    while( scin2( n, k ) )
    {
        if( n == 0 && k == 0 )
            break ;
        memset( dp, -1, sizeof dp ) ;
        int ans = Fun( 0, 0,0 ) ;
        pf( "%d\n" , ans ) ;
        ans = 0 ;
    }

    return 0 ;
}


