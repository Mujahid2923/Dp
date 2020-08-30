int Fun( int i, int j )
{
   if( i == s1.size() || j == s2.size() ) return 0 ;
   if( dp[ i ][ j ] != -1 ) return dp[ i ][ j ] ;
   int ans = 0 ;
   if( s1[ i ] == s2[ j ] )
   {
       ans = 1 + Fun( i + 1, j + 1 ) ;
   }
   else
   {
       int r1 = Fun( i + 1, j ) ;
       int r2 = Fun( i, j + 1 ) ;
       ans = max( r1, r2 ) ;
   }
   return dp[ i ][ j ] = ans ;
}

-----------------------------subsequence print------------------------
   
   for( int i = 1 ; i <= n1 ; i ++ )
    {
        for( int j = 1 ; j <= n2 ; j ++ )
        {
            if( s1[ i - 1 ] == s2[ j - 1 ] )
            {
                dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ] ;
                sp[ i ][ j ] = sp[ i - 1 ][ j - 1 ] + s1[ i - 1 ] ;
            }
            else
            {
                if( dp[ i - 1 ][ j ] > dp[ i ][ j - 1 ] )
                {
                    dp[ i ][ j ] = dp[ i - 1 ][ j ] ;
                    sp[ i ][ j ] = sp[ i - 1 ][ j ] ;
                }
                else if( dp[ i ][ j - 1 ] > dp[ i - 1 ][ j ] )
                {
                    dp[ i ][ j ] = dp[ i ][ j - 1 ] ;
                    sp[ i ][ j ] = sp[ i ][ j - 1 ] ;
                }
                else
                {
                    dp[ i ][ j ] = dp[ i ][ j - 1 ] ;
                    sp[ i ][ j ] = min( sp[ i - 1 ][ j ], sp[ i ][ j - 1 ] ) ;
                }
            }
        }
    }
 dp[ n1 ][ n2 ] = length
 sp[ n1 ][ n2 ] = subsequene
 
*************************** -------------------another approach------------------------------**************************


int n1, n2 ;
string s1 , s2 ;
int lcs[ 3005 ][ 3005 ] ;
void Input()
{
    cin >> s1 >> s2 ;
    n1 = s1.size() ;
    n2 = s2.size() ;
}

void Calculation()
{
    for( int i = 1 ; i <= n1 ; i ++ )
    {
        for( int j = 1 ; j <= n2 ; j ++ )
        {
            if( s1[ i - 1 ] == s2[ j - 1 ] )
            {
                lcs[ i ][ j ] = lcs[ i - 1 ][ j - 1 ] + 1 ;
            }
            else
            {
                lcs[ i ][ j ] = max( lcs[ i - 1 ][ j ] , lcs[ i ][ j - 1 ] ) ;
            }
        }
    }

    s1 = "A" + s1 ;
    string s = "" ;
    int i = n1 , j = n2 ;

    while( lcs[ i ][ j ] )
    {
        if( lcs[ i - 1 ][ j ] == lcs[ i ][ j ] ) i -- ;
        else if( lcs[ i ][ j - 1 ] == lcs[ i ][ j ] ) j -- ;
        else if( lcs[ i ][ j ] > lcs[ i - 1 ][ j - 1 ] )
        {
            s += s1[ i ] ;
            i -- ;
            j -- ;
        }
    }

    reverse( s.begin(), s.end() ) ;
    cout << s << endl ;

}

 
 -------------------------------************************---------------------------------


///https://www.spoj.com/problems/CRSCNTRY/en/

int t, n, m, temp ;
vector < int > A, B ;

int Fun()
{
    int n = A.size() ;
    int m = B.size() ;
    int dp[ n + 2 ][ m + 2 ] ;
    zero( dp ) ;

    for( int i = 1 ; i <= n ; i ++ )
    {
        for( int j = 1 ; j <= m ; j ++ )
        {
            if( A[ i - 1 ] == B[ j - 1 ] )
            {
                dp[ i ][ j ] = 1 + dp[ i - 1 ][ j - 1 ] ;
            }
            else
            {
                dp[ i ][ j ] = max( dp[ i ][ j - 1 ], dp[ i - 1 ][ j ] ) ;
            }
        }
    }
    return dp[ n ][ m ] ;
}

int main()
{
    scin( t ) ;
    while( t-- )
    {
        while( scin( temp ) && temp != 0 )
        {
            A.pb( temp ) ;
        }

        int val, res, ans = 0 ;
        while( scin( val ) && val != 0 )
        {
            B.pb( val ) ;
            int in ;
            while( scin( in ) && in != 0  )
            {
                B.pb( in ) ;
            }
            int res = Fun() ;
            ans = max( ans, res ) ;
            B.clear() ;
        }
        pf( "%d\n", ans ) ;
        A.clear() ;
    }


    return 0 ;
}
