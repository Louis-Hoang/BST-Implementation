#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>
#include <typeinfo>
using namespace std;

template <typename D, typename K>
class BST;

template <typename D, typename K>
class Element{

    public:
        friend class BST<D,K>;
        Element <D, K> * parent;
        Element <D, K> * leftchild;
        Element <D, K> * rightchild;

        Element(){
            parent = NULL;
            leftchild = NULL;
            rightchild = NULL;
        }
        Element(D da, K ke){
            parent = NULL;
            leftchild = NULL;
            rightchild = NULL;
            data = da;
            key = ke;
        }
        D getdata(){
            return data; //returns the data associated with this element
        }
        K getkey(){
            return key; //returns the key associated with this element
        }
        void setdata(){

        }


    private:
        K key;
        D data;


};
