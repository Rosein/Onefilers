#include <forward_list>
#include <deque>
#include <algorithm>
#include <string>

std::deque<std::string> lengthSort( std::forward_list<std::string> words )
{
    words.sort( 
        []( const std::string& fw, const std::string& sw ){
            return fw.size() < sw.size() || ( fw.size() == sw.size() && fw < sw ); 
    });
    return std::deque<std::string>( std::begin( words ), std::end( words ) );
}