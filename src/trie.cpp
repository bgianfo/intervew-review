
#include <iostream>
  using std::cout;
  using std::endl;

#include <string.h>

class Node {
    public:
        static const int MAX_EDGES = 26;
        char character;
        bool endWord;
        int prefixes;
        Node** edges;

        Node() {
            edges = new Node*[MAX_EDGES];
            for( int i = 0; i < MAX_EDGES; i++ ) {
                edges[i] = NULL;
            }
        }

        ~Node() {
            delete [] edges;
        }

        int size( void ) { return MAX_EDGES; }
};

class Trie {
    private:
        Node* root;

        void displayNode( Node* node ) {
            if ( node == NULL ) { 
                return;
            }
            std::cout << "iterating :: " << node->character 
                      << " :: " << node->endWord
                      << " :: " << node->prefixes << std::endl;
             
            for ( int i = 0; i < node->size(); i++ ) {
                if ( node->edges[i] != NULL ) {
                    displayNode( node->edges[i] );
                }
            }
        }

        void truncate( Node* n ) {
            for ( int i = 0; i < n->size(); i++ ) {
                if ( n->edges[i] != NULL ) {  
                    truncate( n->edges[i] );
                    n->edges[i] = NULL;
                }
            }
            delete n;
        }

    public:
        Trie() {
            root = new Node();
            root->character = '\0';
            root->prefixes = 0;
            root->endWord = false;
        }
        ~Trie() {
            truncate( root );
        }

        void insert( char* word ) {
            Node* cur = root;

            while ( *word != '\0' ) {
                int characterIndex = toupper(*word) - 'A';
                if ( cur->edges[characterIndex] == NULL ) {
                    Node* newNode = new Node();
                    newNode->character = *word;
                    newNode->endWord = false;
                    newNode->prefixes = 1;

                    cur->edges[characterIndex] = newNode;
                    cur = newNode;
                } else {
                    cur = cur->edges[characterIndex];
                    cur->prefixes++;
                }
                word++;
            }
            cur->endWord = true;
        }
        
        void display( void ) {
            displayNode( root );
        }
        
        bool search( char* word ) {
            Node* cur = root;
            while ( *word != '\0' ) {
                int characterIndex = toupper(*word) - 'A';
                if ( cur->edges[characterIndex] == NULL ) {
                    return false;
                } else {
                    std::cout << "Found: " << *word << std::endl;
                    cur = cur->edges[characterIndex];
                }
                word++;
            }
            return cur->endWord;
        }

        void remove( char* word ) {
            Node* cur = root;
            while ( *word != '\0' ) {
                int characterIndex = toupper(*word) - 'A';
                if ( cur->edges[characterIndex] == NULL ) {
                    return;
                } else if ( cur->edges[characterIndex]->prefixes == 1 ) {
                    truncate( cur->edges[characterIndex] );
                    cur->edges[characterIndex] = NULL; 
                    return;
                } else {
                    cur = cur->edges[characterIndex];
                }
                *word++;
            }
        }
};


int main()
{

    Trie trie;
    char* words[] = { "tree", "trie", "algo", "assoc", "all", "also", "ass" };

    for ( unsigned int i = 0; i < (sizeof(words)/sizeof(*words)); i++ ) {
        trie.insert( words[i] );
    }
 
    trie.display();
     
    if ( trie.search( "all" ) ) {
        cout << "all exist" << endl;
    } else {
        cout << "all do not exist" << endl;
    }
             
    trie.remove( "all" );

    if ( trie.search( "all" ) ) {
        cout << "all exist" << endl;
    } else {
        cout << "all do not exist" << endl;
    }                   

    trie.display();

    return 0;
}
