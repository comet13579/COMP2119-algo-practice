#include <vector>
#include <unordered_map>

class FreqStack {
    private:
        std::vector<int> stack;
        int lastmode(){
            std::unordered_map<int, int> map;
            for(int i = 0; i < stack.size(); i++){
                map[stack[i]]++;
            }
            int max = 0;
            int mode;
            for(int i = stack.size() - 1; i >= 0; i--){
                if(map[stack[i]] > max){
                    max = map[stack[i]];
                    mode = stack[i];
                }
            }
            return mode;
        }

    public:
        FreqStack(){
            stack = {};
        }
        void push(int value){
            stack.push_back(value);
        }
        int pop(){
            int mode = lastmode();
            for (int i = stack.size() - 1; i >= 0; i--){
                if(stack[i] == mode){
                    stack.erase(stack.begin() + i);
                    return mode;
                }
            }
            return -1;
        }
};