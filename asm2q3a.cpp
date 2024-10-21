//C++
#define MAX_SIZE 10

class FreqStack {
    private:
        int stack[MAX_SIZE];
        int count[10] = {0}; // only 10 possible values
        int itemInList;
        int maxoccur() {
            int max = 0;
            for (int i = 0; i < MAX_SIZE; i++) {
                if (count[i] > max) {
                    max = count[i];
                }
            }
            return max;
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
            count[value]++;
            itemInList++;
        }
        int pop(){
            int max = maxoccur();
            for (int i = itemInList - 1; i >= 0; i--){
                if (count[stack[i]] == max){
                    int temp = stack[i];
                    remove(i);
                    count[temp]--;
                    return temp;
                }
            }
            return -1;
        }
};