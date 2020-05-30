int Set( int n, int pos )
{
    return n = n | ( 1 << pos ) ;
}
int reset( int n, int pos )
{
    return n = n & ~( 1 << pos ) ;
}
bool check( int n, int pos )
{
    return (bool) ( n & ( 1 << pos ) ) ;
}
