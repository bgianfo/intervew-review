
#include <iostream>
    using std::cout;
    using std::endl;

 class Entry {  
   private:
     int key;
     int value;
   public:
     Entry( int key, int value ) {
         this->key = key;
         this->value = value;
     }
     int getKey(void) { return key; }
     int getValue(void) { return value; }
};


class HashMap {
  private:
    static const int SIZE = 128;
    Entry** table;
 public:
    HashMap() {
        table = new Entry*[SIZE];
        for (int i = 0; i < SIZE; i++ ) {
            table[i] = NULL;
        }
    }

   ~HashMap() {
        for (int i = 0; i < SIZE; i++ ) {
            if ( table[i] != NULL ) {
                delete table[i];
            }
        }
        delete [] table;
    }

    int get( int key ) {
        int keyhash = key % SIZE;
        while ( table[keyhash] != NULL && table[keyhash]->getKey() != key ) { 
            keyhash = (keyhash+1) % SIZE;
        }

        if ( table[keyhash] == NULL ) {
            return -1;
        }
        return table[keyhash]->getValue();
    }

    void insert( int key, int value ) {
        int keyhash = key % SIZE;
        while ( table[keyhash] != NULL && table[keyhash]->getKey() != key ) { 
            keyhash = (keyhash+1) % SIZE;
        }

        if ( table[keyhash] != NULL ) {
            delete table[keyhash];
        } 
        table[keyhash] = new Entry( key, value );
    }
};

int main()
{
    HashMap map;

    map.insert(1,10);
    map.insert(20,200);
    map.insert(3,30);
    map.insert(99,990);

    std::cout << "Expecting: 10" << std::endl;
    std::cout << "Got: " << map.get(1) << std::endl;

    std::cout << "Expecting: 200" << std::endl;
    std::cout << "Got: " << map.get(20) << std::endl;

    std::cout << "Expecting: 30" << std::endl;
    std::cout << "Got: " << map.get(3) << std::endl;

    std::cout << "Expecting: 990" << std::endl;
    std::cout << "Got: " << map.get(99) << std::endl;

    map.insert(99,888);

    std::cout << "Expecting: 888" << std::endl;
    std::cout << "Got: " << map.get(99) << std::endl;


    return 0;
}
