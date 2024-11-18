#include <iostream>
#include <cstdint>
using namespace std;

class S{
    private:
        S * parent;
        S * left;
        S * right;
        int64_t data;
        int64_t sum;

        void removeNode(S * toRemove){
            if (toRemove -> left == NULL && toRemove -> right == NULL){
                if (this -> left == toRemove){
                    this -> left == NULL;
                }
                else{
                    this -> right == NULL;
                }
                delete(toRemove);
                return;
            }
        }

    public:
        S(int64_t input){
            parent = NULL;
            left = NULL;
            right = NULL;
            data = input;
            sum = input;
        }

        S(int64_t input, S * p){
            parent = p;
            left = NULL;
            right = NULL;
            data = input;
            sum = input;
        }

        void Insert(int64_t input){
            if (input < data){
                if (left == NULL){
                    left = new S(input);
                    this -> left -> parent = this;
                }
                else{
                    this->left->Insert(input);
                }
            }
            else{
                if (right == NULL){
                    right = new S(input);
                    this -> right -> parent = this;
                }
                else{
                    this->right->Insert(input);
                }
            }
        }

        void Remove(int64_t input){
            if (input < data){
                if (this -> left -> data == input){
                    removeNode(this -> left);
                    this -> left = NULL;
                }
                else{
                    this -> left -> Remove(input);
                }
            }
            else{
                if (this -> right -> data == input){
                    removeNode(this -> right);
                    this -> right = NULL;
                }
                else{
                    this -> right -> Remove(input);
                }
            }
        } //problematic

        int64_t FindKth(int &k){
            if (this -> left != NULL){
                int64_t result = this -> left -> FindKth(k);
                if (!k){
                    return result;
                }
            }

            k--;
            if (!k){
                return data;
            }

            if (this -> right != NULL){
                return this -> right -> FindKth(k);
            }
            return -1;
        }

        int Index(int64_t x){
            if (x < data){
                this -> 
            }
        }
};


int main(){
    int n;
    int cmd;
    int64_t data;
    S * s;
    cin >> n;
    cin >> cmd >> data;
    if (cmd == 1){
        s = new S(data);
    }
    for (int i = 1; i < n; i++){
        cin >> cmd >> data;
        switch (cmd){
            case 1:
                s->Insert(data);
                break;
            case 2:
                s->Remove(data);
                break;
            case 3:
                cout << s->FinKth(data) << endl;
                break;
            case 4:
                cout << s->Index(data) << endl;
                break;
            case 5:
                cout << s->Sum(data) << endl;
                break;
        }
    }
    return 0;
}