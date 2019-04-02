#include <iostream>
#include "Tree.hpp"
#include <stdexcept>  
using namespace ariel;
   Tree::Tree(){
    }
    void Tree::insert(int i)
    {
        node *n=new node();
        n->data=i;
        node *foundI=Root;
        node *Parent;
        if(Root==NULL)
        {
         Root=n;
         mysize++;
        }
     else if(contains(i)==true)
        {
             std::__throw_bad_exception();
        }
        else 
         {
             mysize++;
             while(foundI!=NULL) 
              {
                if ((*foundI).data>i)
                {
                    Parent=foundI;
                    foundI=(*foundI).left;
                }
                else 
                {
                    Parent=foundI;
                    foundI=(*foundI).right;
                }
            }
            if ((Parent->data)>i)
            {
                Parent->left=n;
            }
            else
            {
                Parent->right=n;
             }   
     }
    }
    void Tree::remove (int i){
        if (Root==NULL)
        {
             std::__throw_bad_exception ();
        }
    else if (contains(i)==false)
        {
             std::__throw_bad_exception ();
        }
        else
        {
            node *temp=Root;
            Root=deleteNode(temp,i);
            mysize--;
        }
        
    }


    struct node* Tree::deleteNode( node* root, int key) 
{ 
    // base case 
    if (root == NULL) 
    return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data = temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 
 node* Tree::minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
    int Tree::size(){
        return mysize;
    }
   bool Tree::contains(int i)
   {
        if(Root==NULL)
        {
             return false;
        }
     else 
        {
            node *foundI=Root;
            while(foundI!=NULL)
            {
                if(foundI->data==i)
                return true;
                else if(foundI->data>i)
                {
                    foundI=foundI->left;
                }
                else 
                {
                    foundI=foundI->right;
                }
            }
        }  
        return false;
   }
    int Tree::root(){ 
        if (Root==NULL)
        {
             std::__throw_bad_exception ();
            
        }
        else return Root->data;
    }
    int Tree::parent (int i){
    if (Root==NULL)
        {
             std::__throw_bad_exception ();
        }
    else if (contains(i)==false)
        {
             std::__throw_bad_exception ();
        }
    else if (root()==i)
        {
          std::__throw_bad_exception ();
        }
        else
        {
            node *foundI=Root;
            node *Parent;
            while((*foundI).data!=i)
            {
                if ((*foundI).data<i)
                {
                    Parent=foundI;
                    foundI=(*Parent).right;
                }
                else
                {
                    Parent=foundI;
                    foundI=(*Parent).left;
                } 
            }
            return Parent->data;
        }
    return 1;
    }
    int Tree::left(int i){
    if (Root==NULL)
        {
            std::__throw_bad_exception ();
        }
    else if (contains(i)==false)
        {
             std::__throw_bad_exception ();
        }
    else
        {
            node *foundI=Root;
            while((*foundI).data!=i)
            {
                if ((*foundI).data<i)
                {
                    foundI=(*foundI).left;
                }
                else
                {
                    foundI=(*foundI).right;
                } 
            }
        if (foundI->left==NULL)
        {
             std::__throw_bad_exception ();
        }
        else
        {
            return foundI->left->data;
        }
        }
    }
    int Tree::right(int i){
      if (Root==NULL)
        {
             std::__throw_bad_exception (); 
        }
    else if (contains(i)==false)
        {
             std::__throw_bad_exception ();
        }
    else
        {
            node *foundI=Root;
            while((*foundI).data!=i)
            {
                if ((*foundI).data<i)
                {
                    foundI=(*foundI).left;
                }
                else
                {
                    foundI=(*foundI).right;
                } 
            }

        if (foundI->right==NULL)
            std::__throw_bad_exception ();
        else
        {
            return foundI->right->data;
        }
    }
}  
    void Tree::print(){ 
        node *p=Root; 
        printTreeRec(p);
    }
    void Tree::printTreeRec(node *root) {
        if(!root) {
            printf("NULL");
	        return; 
        }
        printf("(");
        printTreeRec(root->left);
        printf(",%d,",root->data); 
        printTreeRec(root->right);
        printf(")"); 
}