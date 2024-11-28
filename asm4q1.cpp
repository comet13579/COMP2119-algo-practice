#include <iostream>
#include <cmath>
using namespace std;

class Tree{
    private:
        int data;
        Tree *left;
        Tree *right;
        Tree *parent;

    public:
        Tree(int input, Tree * parentNode){ //input null for parentNode for first node
            data = input;
            left = NULL;
            right = NULL;
            parent = parentNode;
        }

        void Tree_Insert(int data, Tree * parent){
            if (data < this->data){
                if (this->left == NULL) {
                    this->left = new Tree(data, parent);
                } else {
                    this->left->Tree_Insert(data,this);
                }

            } 
            else {
                if (this->right == NULL) {
                    this->right = new Tree(data,parent);
                } else {
                    this->right->Tree_Insert(data,this);
                }
            }
        }

};