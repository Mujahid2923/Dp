Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Input: s = "aab", p = "c*a*b" Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

class Solution {
public:
    bool isMatch(string text, string pattern) 
    {
        int dp[ 100 ][ 100 ] = {} ;
        dp[ 0 ][ 0 ] = 1 ;
        for( int i = 1 ; i < pattern.size() ; i ++ )
        {
            if( pattern[ i - 1 ] == '*' ) dp[ 0 ][ i ] = dp[ 0 ][ i - 2 ] ;
        }
        
        for( int i = 1 ; i < text.size() ; i ++ )
        {
            for( int j = 1 ; j < pattern.size() ; j ++ )
            {
                if( pattern[ j - 1 ] == '.' || text[ i - 1 ] == pattern[ j - 1 ] ) dp[ i ][ j ] = dp[ i - 1 ][ j - 1 ] ;
                else if( pattern[ j - 1 ] == '*' ) 
                {
                    dp[ i ][ j ] = dp[ i ][ j - 2 ] ;
                    if( pattern[ j - 2 ] == '.' || pattern[ j - 2 ] == text[ i - 1 ] )
                    {
                        dp[ i ][ j ] = dp[ i ][ j ] | dp[ i - 1 ][ j ] ;
                    }
                }
                else dp[ i ][ j ] = 0 ;
            }
        }
        return dp[ text.size() ][ pattern.size() ] ;
    }
};
