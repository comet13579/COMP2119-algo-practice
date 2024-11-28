#include <cmath>
using namespace std;

class Tree{
    private:
        int data;
        int height;
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

        int getHeight() {
            if (height){
                return height;
            }
            else if (this->left == NULL && this->right == NULL) {
                height = 0;
                return 0;
            }
            else if (this->left == NULL) {
                height = this->right->getHeight() + 1;
            }
            else if (this->right == NULL) {
                height = this->left->getHeight() + 1;
            }
            else {
                height = max(this->left->getHeight(), this->right->getHeight()) + 1;
            }
            return height;
        }

        Tree* lowestCommon(int a, int b){
            if (this->data > a && this->data > b){
                return this->left->lowestCommon(a,b);
            }
            else if (this->data < a && this->data < b){
                return this->right->lowestCommon(a,b);
            }
            else{
                return this;
            }
        }

        bool checkAVL(){
            return abs(this -> left->getHeight() - this->right->getHeight()) <= 1;
        }

};

/**
 * C++
 * Q1a -> treeInsert()
 * Q1b -> lowestCommon()
 * Q1c -> checkAVL()
 */