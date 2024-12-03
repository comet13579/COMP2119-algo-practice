#include <iostream>
#include <unordered_map>
using namespace std;

struct TreapNode {
public:
    long long value;
    int size;
    long long sum;
    long long max_value;
    TreapNode *left, *right;
    TreapNode *parent;

    TreapNode(long long val)
        : value(val), size(1), sum(val), max_value(val),
          left(nullptr), right(nullptr), parent(nullptr) {}
};

class Treap {
private:
    TreapNode *root;
    unordered_map<long long, TreapNode*> value_to_node;

    void update(TreapNode *node) {
        if (node) {
            node->size = 1;
            node->sum = node->value;
            node->max_value = node->value;
            if (node->left) {
                node->size += node->left->size;
                node->sum += node->left->sum;
                node->max_value = max(node->max_value, node->left->max_value);
                node->left->parent = node;
            }
            if (node->right) {
                node->size += node->right->size;
                node->sum += node->right->sum;
                node->max_value = max(node->max_value, node->right->max_value);
                node->right->parent = node;
            }
        }
    }

    void split(TreapNode *root, int key, TreapNode *&left, TreapNode *&right, int add = 0) {
        if (!root) {
            left = right = nullptr;
            return;
        }
        int curr_key = add + (root->left ? root->left->size : 0) + 1;
        if (key < curr_key) {
            split(root->left, key, left, root->left, add);
            right = root;
        } else {
            split(root->right, key, root->right, right, curr_key);
            left = root;
        }
        update(root);
    }

    void merge(TreapNode *&root, TreapNode *left, TreapNode *right) {
        if (!left || !right) {
            root = left ? left : right;
            return;
        }
        if (left->value > right->value) {
            merge(left->right, left->right, right);
            root = left;
        } else {
            merge(right->left, left, right->left);
            root = right;
        }
        update(root);
    }

    long long findKthHelper(TreapNode *node, int k) {
        int left_size = node->left ? node->left->size : 0;
        if (k == left_size + 1) return node->value;
        if (k <= left_size) return findKthHelper(node->left, k);
        return findKthHelper(node->right, k - left_size - 1);
    }

public:
    Treap() {
        root = nullptr;
    }


    void insert(int position, long long value) {
        TreapNode *node = new TreapNode(value);
        TreapNode *t1, *t2;
        split(root, position - 1, t1, t2);
        merge(t1, t1, node);
        merge(root, t1, t2);
        value_to_node[value] = node;
    }

    void remove(int position) {
        TreapNode *t1, *t2, *t3;
        split(root, position - 1, t1, t2);
        split(t2, 1, t2, t3);
        value_to_node.erase(t2->value);
        delete t2;
        merge(root, t1, t3);
    }

    long long findKth(int k) {
        return findKthHelper(root, k);
    }

    int getIndex(long long value) {
        TreapNode *node = value_to_node[value];
        int index = (node->left ? node->left->size : 0) + 1;
        while (node->parent) {
            if (node->parent->right == node) {
                index += (node->parent->left ? node->parent->left->size : 0) + 1;
            }
            node = node->parent;
        }
        return index;
    }

    long long sumRange(int l, int r) {
        TreapNode *t1, *t2, *t3;
        split(root, l - 1, t1, t2);
        split(t2, r - l + 1, t2, t3);
        long long result = t2->sum;
        merge(t2, t2, t3);
        merge(root, t1, t2);
        return result;
    }

    long long maxRange(int l, int r) {
        TreapNode *t1, *t2, *t3;
        split(root, l - 1, t1, t2);
        split(t2, r - l + 1, t2, t3);
        long long result = t2->max_value;
        merge(t2, t2, t3);
        merge(root, t1, t2);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m,cmd,k1,k2;
    long long x;
    cin >> n >> m;

    Treap treap;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        treap.insert(i, x);
    }

    while (m--) {
        cin >> cmd;
        switch (cmd) {
            case 1: {
                long long x;
                cin >> k1 >> x;
                treap.insert(k1, x);
                break;
            }
            case 2: {
                cin >> k1;
                treap.remove(k1);
                break;
            }
            case 3: {
                cin >> k1;
                cout << treap.findKth(k1) << '\n';
                break;
            }
            case 4: {
                cin >> x;
                cout << treap.getIndex(x) << '\n';
                break;
            }
            case 5: {
                cin >> k1 >> k2;
                cout << treap.sumRange(k1, k2) << '\n';
                break;
            }
            case 6: {
                cin >> k1 >> k2;
                cout << treap.maxRange(k1, k2) << '\n';
                break;
            }
        }

    }
    return 0;
}
