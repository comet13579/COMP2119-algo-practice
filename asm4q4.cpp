#include <queue>
#include <vector>
#include <iostream>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

public:
    void addNum(int num) {
        lower.push(num);

        if (!lower.empty() && !upper.empty() && lower.top() > upper.top()) {
            int val = lower.top();
            lower.pop();
            upper.push(val);
        }

        if (lower.size() > upper.size() + 1) {
            int val = lower.top();
            lower.pop();
            upper.push(val);
        }
        if (upper.size() > lower.size()) {
            int val = upper.top();
            upper.pop();
            lower.push(val);
        }
    }

    double findMedian() {
        if (lower.size() > upper.size()) {
            return lower.top();
        }
        return (lower.top() + upper.top()) / 2.0;
    }
};

int main() {
    MedianFinder* mf = new MedianFinder();

    // Test case 1: odd number of elements
    cout << "Test case 1:" << endl;
    mf->addNum(1);
    cout << "After adding 1: " << mf->findMedian() << endl;  // Should output 1.0
    mf->addNum(2);
    cout << "After adding 2: " << mf->findMedian() << endl;  // Should output 1.5
    mf->addNum(3);
    cout << "After adding 3: " << mf->findMedian() << endl;  // Should output 2.0

    // Test case 2: more numbers
    cout << "\nTest case 2:" << endl;
    mf->addNum(4);
    cout << "After adding 4: " << mf->findMedian() << endl;  // Should output 2.5
    mf->addNum(5);
    cout << "After adding 5: " << mf->findMedian() << endl;  // Should output 3.0

    // Test case 3: adding numbers in non-sorted order
    cout << "\nTest case 3:" << endl;
    MedianFinder* mf2 = new MedianFinder();
    mf2->addNum(5);
    cout << "After adding 5: " << mf2->findMedian() << endl;
    mf2->addNum(2);
    cout << "After adding 2: " << mf2->findMedian() << endl;
    mf2->addNum(1);
    cout << "After adding 1: " << mf2->findMedian() << endl;

    delete mf;
    delete mf2;
    return 0;
}