
#include <iostream>
    using std::cout;
    using std::endl;

#include <vector>
    using std::vector;

#include <algorithm>

vector<int> merge( vector<int> lefty, vector<int> righty )
{

    size_t ri = 0;
    size_t li = 0;

    vector<int> merged;

    while ( li < lefty.size() && ri < righty.size() ) {
        if ( lefty[li] < righty[ri] ) {
            merged.push_back( lefty[li] );
            li++;
        } else {
            merged.push_back( righty[ri] );
            ri++;
        }
    }

    while ( li < lefty.size() ) {
        merged.push_back( lefty[li] );
        li++;
    }

     while ( ri < righty.size() ) {
        merged.push_back( righty[ri] );
        ri++;
    }


    return merged;
}

void mergesort( vector<int> &vec ) {

    if ( vec.size() < 2 ) {
        return;
    }

    size_t mid = (vec.size()/2);

    vector<int> lefty(vec.begin(), vec.begin()+mid);
    vector<int> righty(vec.begin()+mid, vec.end());

    mergesort( lefty );
    mergesort( righty );
    vec = merge(lefty,righty);
    return;
}

template<typename T> void print(const T &data)
{
    std::cout<<" "<<data;
}

int main()
{
    std::vector<int> v;
    v.push_back(20);
    v.push_back(0);
    v.push_back(24);
    v.push_back(13);
    v.push_back(5);
    v.push_back(9);

    std::for_each( v.begin(), v.end(), print<int> );
    std::cout << '\n';

    mergesort(v);

    std::for_each( v.begin(), v.end(), print<int> );
    std::cout << '\n';

    return 0;
}
