#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>
#include <typeinfo>
#include "element.cpp"
#include <queue>
using namespace std;

template <typename D, typename K>
class BST
{

public:
    Element<D, K> *root;

    BST()
    {
        root = NULL; // the root is initialized to null because nothing is in the tree as of this point
    }
    ~BST(){ //destructor for bst
      if(empty()!= true){
        Element <D,K> * current = root;
        destroy(current);

      }
    }
    void destroy(Element <D,K> * el){ //recursively destroys every element in a bst rooted at "el"
      if(el != NULL){
        destroy(el->leftchild);
        destroy(el->rightchild);
        delete(el); //unallocates the memeory allocated for el
      }
    }

    /**
    * Precondition: no param needed
    * Postcondition: True if BST empty false otherwise 
    */
    bool empty()
    {
        if (root == NULL)
        { // if the root is null that means nothing is in the tree
            return true;
        }
        return false; // if the root is not null, at least one item is in the tree
    }
    /**
    * Precondition: param data is of type D and param key is of type K
    * Postcondition: Element get inserted into the tree with BSt properties maintained. Return nothing
    */
    void insert(D data, K key)
    {
        Element<D, K> *newElement = new Element<D, K>(data, key);
        Element<D, K> *current = root;         // tracks the position where the element will be inserted at the end
        Element<D, K> *parentEl = NULL; // tracks the parent of where the element will be inserted at the end

        if (empty())
        { // if the tree has no elements, the new element becomes the root
            root = newElement;
        }
        else {
            while (current != NULL)
            {                       // traverses the bst
                parentEl = current; // keeps track of what the parent of the inserted element will be by the end of this loop
                if (current->getkey() > newElement->getkey())
                {
                    current = current->leftchild;
                }
                else
                {
                    current = current->rightchild;
                }
            }
            newElement->parent = parentEl; // setting the parent of the newly inserted element to be equal to the parent tracked in the while loop above

            if (parentEl == NULL){ //newly added 
                root = newElement;
            }
            
            else if (parentEl->getkey() > newElement->getkey())
            { // deciding whether the new element should be the left or right child of its new parent
                parentEl->leftchild = newElement;

            }
            else
            {
                parentEl->rightchild = newElement;
            }
        }
    }
    /**
    * Precondition: param key is of type K
    * Postcondition: return the value of the node whose key is key
    */
    D get(K key)
    { // gets the data associated with an inputted key
        if (empty())
        { // if the tree is empty we obviously return nothing
            return D();
        }
        else
        {
            Element<D, K> *current = root;
            while (current->getkey() != key)
            { // traverses the bst looking for the element corresponding with the given key
                if (current->getkey() > key)
                {
                    current = current->leftchild;
                }
                else
                {
                    current = current->rightchild;
                }
            }
            if (current == NULL)
            { // if this condition is true then the key was not found
                return D();
            }
            else
            { // else the key was located and we return the data associated with the node at that key
                return current->getdata();
            }
        }
    }

    /**
    * Precondition: no param needed
    * Postcondition: return biggest key
    */
    K max_key()
    { // returns the maximum key in the tree
        if (empty())
        {
            return K(); // if the tree is empty there is no key to be the maximum
        }
        Element<D, K> *current = root;
        while (current->rightchild != NULL)
        { // the maximum key will be the furthest right element in the bst, so we continue to move down the tree while elements still have right children
            current = current->rightchild;
        }
        return current->getkey();
    }
    /**
    * Precondition: no param needed
    * Postcondition: return smallest key
    */
    K min_key()
    {
        if (empty())
        { // if the tree is empty there is no key to be the minimum
            return K();
        }
        Element<D, K> *current = root;
        while (current->leftchild != NULL)
        { // the minimum key will be the furthest left element in the bst, so we continue to move down the tree while elements still have left children

            current = current->leftchild;
        }
        return current->getkey();
    }
    
    /**
    * Precondition: no param needed
    * Postcondition: return largest data
    */
    D max_data()
    {
        if (empty())
        {
            return D();
        }
        Element<D, K> *current = root;
        while (current->rightchild != NULL)
        {
            current = current->rightchild;
        }
        return current->getdata();
    }
    /**
    * Precondition: no param needed
    * Postcondition: return smallest data
    */
    D min_data()
    {
        if (empty())
        {
            return D();
        }
        Element<D, K> *current = root;
        while (current->leftchild != NULL)
        {
            current = current->leftchild;
        }
        return current->getdata();
    }

    /**
    * Precondition: param key is of type K
    * Postcondition: return the node whose key is key
    */
    Element<D, K> *findKey(K key)
    {

        // returns a pointer to the memory address of a given key so that it can be referenced later in the remove function
        if (empty() == true)
        {
            return NULL;
        }
        else
        {
            Element<D, K> *current = root;

            while (current != NULL && current->getkey() != key)
            { // finding the location in memory of the requested key
                if (current->getkey() > key)
                {
                    current = current->leftchild;
                }
                else
                {
                    current = current->rightchild;
                }
            }
            return current; // returns a pointer to the node with the found key
        }
        return NULL;
    }

    /**
    * Precondition: param key is of type K 
    * Postcondition: return the successor (smallest value that larger than the key)
    */
    K successor(K key)
    {
        K succ;
        if (empty())
        {
            return K(); // there is no key to remove if it is empty
        }

        if (key == max_key()){
            return 0;
        }

        Element<D, K> *foundNode = findKey(key); // finds the memory location of the first instance of the requested key in the bst
        if (foundNode)
        { // if the key is not in the bst return NULL
            if (foundNode->rightchild != NULL)
            { // the successor will be the minimum value in the right subtree if there exists a right subtree
                
                Element<D, K> *current = foundNode->rightchild;

                while (current->leftchild != NULL)
                {
                    current = current->leftchild;
                }
                succ = current->getkey();
                return succ;
            }
            
        // if there is no right subtree, we traverse up the tree while the current node is a left child, when the current node is a right child, the parent of current at this point will be the successor of our original node
            // Element<D, K> *current = foundNode;
            Element<D, K> *par = foundNode->parent;
            while (par->rightchild == foundNode && par != NULL)
            {
                foundNode = par;
                par = foundNode->parent;
            }
            succ = par->getkey();     
            
        }
        return succ;
    }
    /**
    * Precondition: u and v are two pointer
    * Postcondition: replace subtree rooted at u with the subtree rooted at v 
    */
    void transplant( Element<D, K>*u, Element<D, K>*v){
        if (u->parent == NULL){
            root = v;
        }
        else if (u==u->parent->leftchild){
            u->parent->leftchild = v;
        }
        else {
            u->parent->rightchild = v;
        }
        if (v != NULL){
            v->parent = u->parent;
        }
    }
    /**
    * Precondition: param key is of type K
    * Postcondition: return nothing and remove node whose key is key and still maintain tree property
    */
    void remove(K key)
    {
        Element<D, K> *foundNode = findKey(key); // finds the memory location of the first instance of the requested key in the bst
        if (foundNode -> leftchild == NULL){
            transplant(foundNode, foundNode->rightchild);
        }
        else if (foundNode->rightchild == NULL){
            transplant(foundNode, foundNode->leftchild);
        }
        else{
            Element<D, K> *y  = findKey(successor(key));
            if (y != foundNode -> rightchild){
                transplant(y, y->rightchild);
                y->rightchild = foundNode->rightchild;
                y->rightchild->parent = y;
            }
            transplant(foundNode, y);
            y->leftchild = foundNode -> leftchild;
            y->leftchild->parent = y;
        }
        delete(foundNode);
    }

    string in_order_helper(Element<D, K> *current)
    { // recursively prints the elements in the bst in order

        std::stringstream ss;
        if (current != NULL)
        {
            ss << in_order_helper(current->leftchild);
            ss << current->getkey() << " ";
            ss << in_order_helper(current->rightchild);
        }
        return ss.str();
    }
    /**
    * Precondition: no param needed
    * Postcondition: return in order string representation of BST 
    */
    string in_order()
    {
        string ostring;
        if (empty())
        {
            return string();
        }
        ostring = in_order_helper(root);
        return ostring.substr(0, ostring.size()-1);
    }

    /**
    * Precondition: param root if a pointer
    * Postcondition: return the level order traversal string representation of BST 
    */
    string toStringHelper(Element<D, K> *root)
    {  
            stringstream ss;
            if(root == NULL){
                return ""; 
            }
    
            queue< Element<D, K> * > queue;              //create empty Queue
    
            queue.push(root);                   //enqueue root
    
            while(!queue.empty())
            {
                // Print front of queue and remove it from queue
        
                Element<D, K>* node = queue.front();
                ss << node->getkey() << " ";
                queue.pop();
        
                //enqueue Left child
        
                if(node->leftchild){
                    queue.push(node->leftchild);
                }
                //enqueue right child
        
                if(node->rightchild)
                    queue.push(node->rightchild);
            }
        return ss.str();
    }
     
      
    /**
    * Precondition: none 
    * Postcondition:  return string represent level order traverse of BST 
    */
    string to_string()
    {
        Element<D, K> *current = root;
        stringstream ostring;
        string str = "";
        string outstring = toStringHelper(root);
        ostring << outstring;
        str += ostring.str();
        return str.substr(0, str.size()-1);
    }
    
    /**
    * Precondition: param is a pointer and two low and high variable 
    * Postcondition: return the bst with all nodes with key between low and high
    */
    Element<D, K> * trim_helper(Element<D, K> *root, K low, K high){
        if (root == NULL){
            return NULL;
        }
        root ->leftchild = trim_helper(root->leftchild,low,high); //trim leftsubtree recursively
        root ->rightchild = trim_helper(root->rightchild,low,high);//trim rightsubtree recursively
        if (root -> getkey() >= low && root->getkey() <=high){
            return root;
        }
        if (root->getkey() >= high){
            return root->leftchild;
            delete(root);
        }
        if (root->getkey() <= low){
            return root->rightchild;
            delete(root);
        }
        return root;
    }

    void trim(K low, K high){
        trim_helper(root, low,high);
    }
};
