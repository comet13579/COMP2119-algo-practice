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

public:
    AVLTree(long long val) {
        key = val;
        left = nullptr;
        right = nullptr;
        height = 1;
        size = 1;
        sum = val;
    }

    int getHeight() {
        return (this != nullptr) ? this->height : 0;
    }

    int getSize() {
        return (this != nullptr) ? this->size : 0;
    }

    long long getSum() {
        return (this != nullptr) ? this->sum : 0LL;
    }

    int getBalance() {
        if (this == nullptr) {
            return 0;
        }
        return left->getHeight() - right->getHeight();
    }

    void update() {
        if (this != nullptr) {
            height = 1 + max(left ? left->getHeight() : 0, right ? right->getHeight() : 0);
            size = 1 + (left ? left->getSize() : 0) + (right ? right->getSize() : 0);
            sum = key + (left ? left->getSum() : 0) + (right ? right->getSum() : 0);
        }
    }

    AVLTree* rightRotate() {
        AVLTree* x = this->left;
        AVLTree* T2 = x->right;

        x->right = this;
        this->left = T2;

        this->update();
        x->update();

        return x;
    }

    AVLTree* leftRotate() {
        AVLTree* y = this->right;
        AVLTree* T2 = y->left;

        y->left = this;
        this->right = T2;

        this->update();
        y->update();

        return y;
    }

    AVLTree* insert(long long val) {
        if (this == nullptr) {
            return new AVLTree(val);
        }

        if (val < key) {
            left = left ? left->insert(val) : new AVLTree(val);
        } else {
            right = right ? right->insert(val) : new AVLTree(val);
        }

        update();

        int balance = getBalance();

        // Left Left Case
        if (balance > 1 && val < left->key) {
            return rightRotate();
        }

        // Right Right Case
        if (balance < -1 && val > right->key) {
            return leftRotate();
        }

        // Left Right Case
        if (balance > 1 && val > left->key) {
            left = left->leftRotate();
            return rightRotate();
        }

        // Right Left Case
        if (balance < -1 && val < right->key) {
            right = right->rightRotate();
            return leftRotate();
        }

        return this;
    }

    AVLTree* findMin() {
        AVLTree* current = this;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    long long findKth(int k) {
        int leftSize = left ? left->getSize() : 0;
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
            return (left ? left->getSize() : 0) + 1 + (right ? right->findIndex(x) : 0);
        }
        return (left ? left->getSize() : 0) + 1;
    }

    long long sumK(int k) {
        if (k <= 0) return 0;
        int leftSize = left ? left->getSize() : 0;
        
        if (leftSize >= k) {
            return left->sumK(k);
        }
        
        long long leftSum = (left ? left->getSum() : 0) + key;
        if (k == leftSize + 1) {
            return leftSum;
        }
        return leftSum + (right ? right->sumK(k - leftSize - 1) : 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k,op;
    long long x;
    cin >> n;
    AVLTree* root = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            root = root ? root->insert(x) : new AVLTree(x);
        }
        else if (op == 3) {
            cin >> k;
            cout << root->findKth(k) << "\n";
        }
        else if (op == 4) {
            cin >> x;
            cout << root->findIndex(x) << "\n";
        }
        else if (op == 5) {
            cin >> k;
            cout << root->sumK(k) << "\n";
        }
    }
}
