#include <algorithm>
#include <iostream>
using namespace std;

class AVLTree {
private:
    long long key;
    AVLTree* left;
    AVLTree* right;
    int height;
    int size;
    long long sum;
    
    int getHeight(AVLTree* node) const { 
        return (node != nullptr) ? node->height : 0; 
    }
    
    int getSize(AVLTree* node) const { 
        return (node != nullptr) ? node->size : 0; 
    }
    
    long long getSum(AVLTree* node) const { 
        return (node != nullptr) ? node->sum : 0LL; 
    }
    
    int getBalance(AVLTree* node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    
    void update() {
        height = 1 + max(getHeight(left), getHeight(right));
        size = 1 + getSize(left) + getSize(right);
        sum = key + getSum(left) + getSum(right);
    }
    
    AVLTree* rightRotate(AVLTree* y) {
        AVLTree* x = y->left;
        AVLTree* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        y->update();
        x->update();
        
        return x;
    }
    
    AVLTree* leftRotate(AVLTree* x) {
        AVLTree* y = x->right;
        AVLTree* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        x->update();
        y->update();
        
        return y;
    }
    
    AVLTree* minValueNode(AVLTree* node) const {
        AVLTree* current = node;
        while (current->left)
            current = current->left;
        return current;
    }
    
public:
    AVLTree(long long x) 
        : key(x), left(nullptr), right(nullptr), height(1), size(1), sum(x) {}
    
    AVLTree* insert(long long val) {
        if (val < key) {
            if (left == nullptr) {
                left = new AVLTree(val);
            } else {
                left = left->insert(val);
            }
        } else {
            if (right == nullptr) {
                right = new AVLTree(val);
            } else {
                right = right->insert(val);
            }
        }
        
        update();
        
        int balance = getBalance(this);
        
        // Left Left Case
        if (balance > 1 && val < left->key)
            return rightRotate(this);
            
        // Right Right Case
        if (balance < -1 && val > right->key)
            return leftRotate(this);
            
        // Left Right Case
        if (balance > 1 && val > left->key) {
            left = leftRotate(left);
            return rightRotate(this);
        }
        
        // Right Left Case
        if (balance < -1 && val < right->key) {
            right = rightRotate(right);
            return leftRotate(this);
        }
        
        return this;
    }
    
    AVLTree* remove(long long val) {
        if (val < key) {
            if (left) left = left->remove(val);
        }
        else if (val > key) {
            if (right) right = right->remove(val);
        }
        else {
            if (!left || !right) {
                AVLTree* temp = left ? left : right;
                if (!temp) {
                    // No child case
                    return nullptr;
                } else {
                    // One child case
                    *this = *temp;
                    delete temp;
                }
            } 
            else {
                AVLTree* temp = minValueNode(right);
                key = temp->key;
                right = right->remove(temp->key);
            }
        }
    
        update();
    
        int balance = getBalance(this);
    
        // Perform rotations if needed
        if (balance > 1 && getBalance(left) >= 0)
            return rightRotate(this);
        
        if (balance > 1 && getBalance(left) < 0) {
            left = leftRotate(left);
            return rightRotate(this);
        }

        if (balance < -1 && getBalance(right) <= 0)
            return leftRotate(this);

        if (balance < -1 && getBalance(right) > 0) {
            right = rightRotate(right);
            return leftRotate(this);
        }
        return this;
    }

    
    long long findKth(int k) {
        int leftSize = getSize(left);
        if (k <= leftSize) {
            return left->findKth(k);
        }
        if (k == leftSize + 1) {
            return key;
        }
        return right->findKth(k - leftSize - 1);
    }
    
    int findIndex(long long x) {
        if (x < key) {
            return left ? left->findIndex(x) : 0;
        }
        if (x > key) {
            return getSize(left) + 1 + (right ? right->findIndex(x) : 0);
        }
        return getSize(left) + 1;
    }
    
    long long sumK(int k) {
        if (k <= 0) return 0;
        
        int leftSize = getSize(left);
        if (leftSize >= k) {
            return left->sumK(k);
        }
        
        long long leftSum = getSum(left);
        if (k == leftSize + 1) {
            return leftSum + key;
        }
        
        return leftSum + key + right->sumK(k - leftSize - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k,cmd;
    long long x;
    cin >> n;
    
    AVLTree* tree = nullptr;
    
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        
        switch (cmd) {
            case 1:
                cin >> x;
                if (!tree) {
                    tree = new AVLTree(x);
                }
                else {
                    tree = tree->insert(x);
                }
                break;
                
            case 2:
                cin >> x;
                tree = tree->remove(x);
                break;
                
            case 3:
                cin >> k;
                cout << tree->findKth(k) << "\n";
                break;
                
            case 4:
                cin >> x;
                cout << tree->findIndex(x) << "\n";
                break;
                
            case 5:
                cin >> k;
                cout << tree->sumK(k) << "\n";
                break;
        }
    }
 
    return 0;
}
