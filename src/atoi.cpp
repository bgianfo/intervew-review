
#include <iostream>
    using std::cout;
    using std::endl;

#include <string>
    using std::string;

int myatoi( string str ) {

    int total;
    bool isNegative;
    unsigned int i = 0;

    if ( str[0] == '-' ) {
        isNegative = true;
        i++;
    } else {
        isNegative = false;
    }


    for ( ; i < str.length(); i++ ) {
        total = (total*10) + ( str[i] - 48 );
    }

    return isNegative ? -total : total;
}


int main() {

    cout << "Expecting: -1234" << endl;
    cout << myatoi("-1234") << endl;

    cout << "Expecting: 1" << endl;
    cout <<  myatoi("1")  << endl;

    cout << "Expecting: 1000000" << endl;
    cout << myatoi("1000000") << endl;

    cout << "Expecting: 0" << endl;
    cout << myatoi("0") << endl;

    return 0;
}
