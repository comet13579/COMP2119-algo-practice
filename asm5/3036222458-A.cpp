#include <iostream>
#include <cmath>
using namespace std;

class Tree{
    private:
        int data;
        int height;
        int dH;
        int maxdH;
        Tree *left;
        Tree *right;

    public:
        Tree(int input){
            data = input;
            height = 0;
            dH = 0;
            maxdH = 0;
            left = NULL;
            right = NULL;
        }

        void Tree_Insert(int data){
            if (data < this->data){
                if (this->left == NULL) {
                    this->left = new Tree(data);
                } else {
                    this->left->Tree_Insert(data);
                }
            } 
            else {
                if (this->right == NULL) {
                    this->right = new Tree(data);
                } else {
                    this->right->Tree_Insert(data);
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

        int getdH(){
            if (dH){
                return dH;
            }
            if (this->left == NULL && this->right == NULL) {
                return 0;
            }
            else if (this->left == NULL) {
                dH = this->right->getHeight() + 1;
            }
            else if (this->right == NULL) {
                dH = this->left->getHeight() + 1;
            }
            else {
                dH = abs(this->left->getHeight() - this->right->getHeight());
            }
            return dH;
        }

        int getMaxdH(){
            if (maxdH){
                return maxdH;
            }
            else if (this->left == NULL && this->right == NULL) {
                return 0;
            }
            else if (this->left == NULL) {
                maxdH = max(this->right->getMaxdH(), this->getdH());
            }
            else if (this->right == NULL) {
                maxdH = max(this->left->getMaxdH(), this->getdH());
            }
            else {
                int childMaxdH = max(this->left->getMaxdH(), this->right->getMaxdH());
                maxdH = max(childMaxdH, this->getdH());
            }
            return maxdH;
        }


};

Tree* inputTree(){
    int n, firstdata;
    cin >> n >> firstdata;
    Tree *root = new Tree(firstdata);
    for (int i = 1; i < n; i++){
        int data;
        cin >> data;
        root->Tree_Insert(data);
    }
    return root;
}

int main(){
    Tree * root = inputTree();
    cout << root->getMaxdH() << endl;
}