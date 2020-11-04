int row = s1.size(), col = s2.size() ;
int dp[ row + 5 ][ col + 5 ] ;
for( int i = 0 ; i <= row ; i ++ ) dp[ i ][ 0 ] = i ;
for( int i = 0 ; i <= col ; i ++ ) dp[ 0 ][ i ] = i ;
        
        
for( int i = 1 ; i <= row ; i ++ )
{
    for( int j = 1 ; j <= col ; j ++ )
    {
        if( s1[ i - 1 ] == s2[ j - 1 ] ) dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] ;
        else dp[ i ][ j ] = 1 + min( { dp[ i-1 ][ j-1 ], dp[ i-1 ][ j ], dp[ i ][ j-1 ] } ) ;
    }
}
return dp[ row ][ col ] ;

string s1 = abcdef
string s2 = agced
Total 3 cahnge needed to make them equal ( edit, delete, add )
