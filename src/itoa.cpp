
#include <iostream>
    using std::cout;
    using std::endl;

#include <string>
    using std::string;

#include <algorithm>
    using std::reverse;

string myitoa( int var ) {

    string strval;

    bool issigned = false;
    if ( var < 0 ) {
        issigned = true;
        var *= -1;
    }

    do {
        strval.push_back( (var%10) + '0' );
    } while ( (var /= 10) > 0 );


    if ( issigned ) {
        strval.push_back( '-' );
    }

    reverse( strval.begin(), strval.end() );
    return strval;
}


int main() {

    cout << "Expecting: -1234" << endl;
    cout << myitoa(-1234) << endl;

    cout << "Expecting: 1" << endl;
    cout <<  myitoa(1)  << endl;

    cout << "Expecting: 1000000" << endl;
    cout << myitoa(1000000) << endl;

    cout << "Expecting: 0" << endl;
    cout << myitoa(0) << endl;

    return 0;
}
