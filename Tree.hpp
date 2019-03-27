#include <iostream>

 namespace ariel{
   struct node
   {
       int data;
    node* left;
    node* right;
    node() {}
    ~node() {}
      
   };
   
   class Tree{
    private:
     node *Root=NULL; 
        int mysize=0;
    
    public:

        Tree();
        void insert(int i);
        void remove (int i);
        int size();
        bool contains(int i);
        int root();
        int parent (int i);
        int left(int i);
        int right(int i);
        void print();
        void printTreeRec(node *root);
       node* deleteNode( node* root, int key);
        node* minValueNode(node* node);
     };
 }
 
