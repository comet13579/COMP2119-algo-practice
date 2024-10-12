//C++
#define MAX_SIZE 10

class FreqStack {
    private:
        int stack[MAX_SIZE];
        int itemInList;
        int lastmode() {
            int mode = stack[itemInList - 1];
            int maxFreq = 1;
            int currentFreq;

            for (int i = itemInList - 1; i >= 0; i--){
                currentFreq = 1;
                for (int j = i - 1; j >= 0; j--) {
                    if (stack[i] == stack[j]) {
                    currentFreq++;
                    }
                }
                if (currentFreq > maxFreq) {
                    maxFreq = currentFreq;
                    mode = stack[i];
                }
            }
            return mode;
        }

        void remove(int index){
            for (int i = index; i < itemInList - 1; i++){
                stack[i] = stack[i + 1];
            }
            itemInList--;
        }

    public:
        FreqStack() {
            itemInList = 0;
        }
        void push(int value){
            stack[itemInList] = value;
            itemInList++;
        }
        int pop(){
            int mode = lastmode();
            for (int i = itemInList - 1; i >= 0; i--){
                if(stack[i] == mode){
                    remove(i);
                    return mode;
                }
            }
            return -1;
        }
};