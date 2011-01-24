
#include <iostream>
    using std::cout;
    using std::endl;

#include <vector>
    using std::vector;

#include <algorithm>

void partition( vector<int>& main, int part, vector<int> &lefty,  vector<int> &righty )
{
    for ( int i = 0; i < (int)main.size(); i++ ) {
        if ( i == part ) {
            continue;
        }

        if ( main[i] > main[part] ) {
            righty.push_back(main[i]);
        } else {
            lefty.push_back(main[i]);
        }
    }
}

void quicksort( vector<int> &vec ) {

    if ( vec.size() < 2 ) {
        return;
    }

    size_t pivot = (vec.size()/2);

    vector<int> lefty;
    vector<int> righty;

    partition( vec, pivot, lefty, righty );

    quicksort( lefty );
    quicksort( righty );

    vector<int> sorted;

    sorted.insert( sorted.end(), lefty.begin(), lefty.end() );
    sorted.insert( sorted.end(), vec[pivot] );
    sorted.insert( sorted.end(), righty.begin(), righty.end() );

    vec.swap(sorted);
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

    quicksort(v);

    std::for_each( v.begin(), v.end(), print<int> );
    std::cout << '\n';

    return 0;
}
