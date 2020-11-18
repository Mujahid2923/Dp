------------------- string combination and permutation -------------------------
   
 void Input()
{
    cin >> s ;
    n = s.size() ;
}

void Combination( string ps, string str )
{
    int n = str.size() ;
    cout << ps << endl ;
    for( int i = 0 ; i < n ; i ++ )
    {
        Combination( ps + str[ i ], str.substr( i + 1 ) ) ;
    }
}
void Permutaion( string ps, string str )
{
    int n = str.size() ;
    if( n == 0 ) cout << ps << endl ;
    for( int i = 0 ; i < n ; i ++ )
    {
        Permutaion( ps + str[ i ], str.substr( 0, i ) + str.substr( i + 1, n ) ) ;
    }
}

void Calculation()
{
    cout << "Combination -> " << endl ;
    Combination( "", s ) ;
    cout << "Permutaion -> " << endl ;
    Permutaion( "", s ) ;
}


---------------------------------------******************--------------------------------------------

///Uva10664
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

vector < int > v ;
int n , ck , sum ;
bool dp[ 22 ][ 205 ] ;

bool Fun()
{
   memset( dp , false , sizeof dp ) ;
   for( int i = 0 ; i <= n ; i ++ )
   {
       dp[ i ][ 0 ] = true ;
   }

   for( int i = 1 ; i <= n ; i ++ )
   {
       for( int j = 1 ; j <= sum ; j ++ )
       {
           if( j < v[ i - 1 ])
           {
               dp[ i ][ j ] = dp[ i - 1 ][ j ] ;
           }
           else
           {
               if( dp[ i - 1 ][ j ] ) dp[ i ][ j ] = dp[ i - 1 ][ j ] ;
               else dp[ i ][ j ] = dp[ i - 1 ][ j - v[ i - 1 ] ] ;
           }
       }
   }

   return dp[ n ][ sum / 2 ] ;
}

int main()
{
    int t , a ;
    string s ;
    cin >> t ;
    getchar() ;
    while( t-- )
    {
        getline( cin , s ) ;
        stringstream ss( s ) ;
        while( ss >> a )
        {
            sum += a ;
            v.pb( a ) ;
        }
        n = v.size() ;

        if( sum & 1 )
        {
            no ;
        }
        else
        {
            if( Fun() )
            {
                yes ;
            }
            else
            {
                no ;
            }
        }

        v.clear() ;
        ck = 0, sum = 0 ;
    }
    return 0 ;
}


