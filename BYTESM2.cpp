///https://www.spoj.com/problems/BYTESM2/en/
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
#define segment_trele int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;


int row , col ;
int arr[ 105 ][ 105 ] ;
int dp[ 105 ][ 105 ] ;

int Fun( int i , int j )
{
    if( i >= 0 && i < row && j >= 0 && j < col )
    {
        if( dp[ i ][ j ] != -1 ) return dp[ i ][ j ] ;

        int r1 = arr[ i ][ j ] + Fun( i + 1 , j - 1 ) ;
        int r2 = arr[ i ][ j ] + Fun( i + 1 , j ) ;
        int r3 = arr[ i ][ j ] + Fun( i + 1 , j + 1 ) ;
        return dp[ i ][ j ] = max3( r1 , r2 , r3 ) ;
    }
    else
    {
        return 0 ;
    }
}

int main()
{
    int t ;
    scin( t ) ;
    while( t-- )
    {
        scin2( row , col ) ;
        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j ++ )
            {
                scin( arr[ i ][ j ] ) ;
            }
        }
        int ans = INT_MIN ;
        for( int j = 0 ; j < col ; j ++ )
        {
            memset( dp , -1 , sizeof dp ) ;
            ans = max( ans , Fun( 0, j ) ) ;
        }

        pf( "%d\n", ans ) ;
    }
    return 0 ;
}




