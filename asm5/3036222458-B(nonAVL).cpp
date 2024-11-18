#include <vector>
#include <iostream>
#include  <algorithm>
using namespace std;

class S{
    private:
        vector<long long int> v;
    public:
        S(){
            v = vector<long long int>();
        }

        void Insert(long long int x){
            v.push_back(x);
            sort(v.begin(), v.end());
        }

        void Remove(long long int x){
            for (int i = 0; i < v.size(); i++){
                if (v[i] == x){
                    v.erase(v.begin() + i);
                    break;
                }
            }
        }

        long long int FinKth(int k){
            return v[k-1];
        }

        int Index(long long int x){
            for (int i = 0; i < v.size(); i++){
                if (v[i] == x){
                    return i + 1;
                }
            }
            return -1;
        }

        long long int Sum(int k){
            long long int sum = 0;
            for (int i = 0; i < k; i++){
                sum += v[i];
            }
            return sum;
        }

};

int main(){
    S s = S();
    int n;
    cin >> n;
    int cmd;
    long long int data;
    for (int i = 0; i < n; i++){
        cin >> cmd >> data;
        switch (cmd){
            case 1:
                s.Insert(data);
                break;
            case 2:
                s.Remove(data);
                break;
            case 3:
                cout << s.FinKth(data) << endl;
                break;
            case 4:
                cout << s.Index(data) << endl;
                break;
            case 5:
                cout << s.Sum(data) << endl;
                break;
        }
    }
    return 0;
}