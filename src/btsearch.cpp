
#include <iostream>
    using std::cout;
    using std::endl;

 class Node {  
   private:
     Node* left;
     Node* right;
     int value;

   public:
     Node( int value ) {
         left = NULL;
         right = NULL;
         this->value = value;
     }

     int getValue() {
         return value;
     }

     Node* getLeft() {
         return left;
     }

     Node* getRight() {
         return right;
     }

     void setLeft( Node* node ) {
         left = node;
     }

     void setRight( Node* node ) {
         right = node;
     }

     bool add( int value ) {
         if ( this->value > value ) {
             if ( left == NULL ) {
                 left = new Node( value );
                 return true;
             } else {
                 return left->add( value );
             }
         } else if ( this->value < value ) {
             if ( right == NULL ) {
                 right = new Node( value );
                 return true;
             } else {
                 return right->add( value );
             }
         }
         return false;
     }

     bool search( int value ) {
         if ( this->value == value ) {
             return true;
         } else if ( this->value > value ) {
             if ( left == NULL ) {
                 return false;
             } else {
                 return left->search( value );
             }
         } else if ( this->value < value ) {
             if ( right == NULL ) {
                 return false;
             } else {
                 return right->search( value );
             }
         }
         return false;
     }

     Node* remove( int val, Node* parent ) {
         if ( this->value > val ) {
             if ( left == NULL ) {
                 return NULL;
             } else {
                 return left->remove( val, this );
             }
         } else if ( this->value < val ) {
             if ( right == NULL ) {
                 return NULL;
             } else {
                 return right->remove( val, this );
             }
         } else {
            if (left != NULL && right != NULL) {
                  this->value = right->min();
                  return right->remove( this->value, this );
            } else if (parent->left == this) {
                  parent->left = (left != NULL) ? left : right;
                  return this;
            } else if (parent->right == this) {
                  parent->right = (left != NULL) ? left : right;
                  return this;
            }
         }
         return NULL;
     }

     static void traversalPrint( Node* node ) {
         if ( node == NULL ) {
             return;
         }

         traversalPrint( node->getLeft() );
         std::cout << " " << node->getValue();
         traversalPrint( node->getRight() );
     }


     int min() { 
         if ( left == NULL ) {
             return value;
         } else {
             return left->min();
         }
     }

};

class BinaryTree {
    private:
        Node* root;
    public:
        BinaryTree() {
            root = NULL;
        }

        bool add( int val ) {
            if ( root == NULL ) {
                root = new Node( val );
                return true;
            } else {
                return root->add( val );
            }
        }

        bool search( int val ) {
            if ( root == NULL ) {
                return false;
            } else {
                return root->search( val );
            }
        }

        bool remove( int val ) {
            if ( root == NULL ) {
                return false;
            } else {
                if ( root->getValue() == val ) {
                    Node fake(0);
                    fake.setLeft( root );
                    Node* removed = root->remove( val, &fake );
                    root = fake.getLeft();
                    if ( removed != NULL ) {
                        delete removed;
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    Node* removed = root->remove( val, NULL );
                    if ( removed == NULL ) {
                        return false;
                    } else {
                        delete removed;
                        return true;
                    }
                }
            }
        }

        void print( void ) {
            if ( root != NULL ) {
                Node::traversalPrint(root);
                std::cout << std::endl;
            } else {
                std::cout << "Tree is empty" << std::endl;
            }
        }
};

int main()
{
    BinaryTree tree;


    tree.add( 5 );
    tree.add( 2 );
    tree.add( 12 );
    tree.add( -4 );
    tree.add( 3 );
    tree.add( 9 );
    tree.add( 21 );
    tree.add( 19 );
    tree.add( 25 );   

    tree.print();

    tree.remove(12);

    tree.print();

    return 0;
}
