------ ****** http://lightoj.com/volume_showproblem.php?problem=1011 ****** ----------
int T, n, k ;
int arr[ 17 ][ 17 ] ;
int dp[ 1 << 17 ] ;

int Set( int n, int pos )
{
    return n = n | ( 1 << pos ) ;
}

bool check( int n, int pos )
{
    return (bool) ( n & ( 1 << pos ) ) ;
}

void Reset()
{
    memset( dp, -1, sizeof dp ) ;
}

void Input()
{
    scin( n ) ;
    for( int i = 0 ; i < n ; i ++ )
    {
        for( int j = 0 ; j < n ; j ++ )
        {
            scin( arr[ i ][ j ] ) ;
        }
    }
}

int Fun( int mask , int pos )
{
    cout << mask << " " << pos << endl ;
    if( mask == ( 1 << n ) - 1 ) return 0 ;
    if( dp[ mask ] != -1 ) return dp[ mask ] ;

    int ans = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        if( !check( mask, i ) )
        {
            int val = arr[ pos ][ i ] + Fun( Set( mask, i ), pos + 1 ) ;
            ans = max( ans , val ) ;
        }
    }
    return dp[ mask ] = ans ;
}

void Calculation()
{
    int ans = Fun( 0, 0 ) ;
    pf( "Case %d: %d\n", T, ans ) ;
}


void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int t ;
    scin( t ) ;
    while( t-- )
    {
        T ++ ;
        solve() ;
    }

    return 0 ;
}

------ ****** https://www.codechef.com/problems/TSHIRTS ****** ----------


int n, x, test ;
ll dp[ 105 ][ 1 << 10 ] ;
string s ;

void Reset()
{
    for( int i = 0 ; i <= 100 ; i ++ ) adj[ i ].clear() ;
    memset( dp, -1, sizeof dp ) ;
}

int Set( int n, int pos )
{
    return n = n | ( 1 << pos ) ;
}

bool check( int n, int pos )
{
    return (bool) ( n & ( 1 << pos ) ) ;
}

void Input()
{
    scanf( "%d", &n ) ;
    Ignore ;
    for( int i = 0 ; i < n ; i ++ )
    {
        getline( cin, s ) ;
        stringstream ss ( s ) ;
        while( ss >> x ) adj[ x ].pb( i ) ;
    }
}

ll Fun( int pos, int mask )
{
    if( mask == ( 1 << n ) - 1 ) return 1 ;
    if( pos == 101 ) return 0 ;
    if( dp[ pos ][ mask ] != -1 ) return dp[ pos ][ mask ] ;

    ll ans = Fun( pos + 1, mask ) ;

    for( auto x : adj[ pos ] )
    {
        if( !check( mask, x ) )
        {
            ans = ( ans + Fun( pos + 1, Set( mask, x ) ) ) % MOD ;
        }
    }

    return dp[ pos ][ mask ] = ans ;
}

void Calculation()
{
    printf( "%lld\n", Fun( 0, 0 ) ) ;
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int t ;
    scanf( "%d", &t ) ;
    while( t-- )
    {
        solve() ;
    }
    return 0 ;
}





