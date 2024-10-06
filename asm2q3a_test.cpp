#include <iostream>
#include <cassert>
#include "asm2q3a.cpp"

void runTestCases() {
    FreqStack fs;

    // Test case 1: Basic push and pop
    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);

    assert(fs.pop() == 5);
    assert(fs.pop() == 7);
    assert(fs.pop() == 5);
    assert(fs.pop() == 4);

    // Test case 2: Equal frequency, return most recent
    FreqStack fs2;
    fs2.push(1);
    fs2.push(2);
    fs2.push(1);
    fs2.push(2);

    assert(fs2.pop() == 2);
    assert(fs2.pop() == 1);

    // Test case 3: Single element
    FreqStack fs3;
    fs3.push(42);
    assert(fs3.pop() == 42);

    // Test case 4: Multiple pushes and pops
    FreqStack fs4;
    fs4.push(1);
    fs4.push(2);
    fs4.push(3);
    fs4.push(2);
    fs4.push(1);
    fs4.push(2);

    assert(fs4.pop() == 2);
    assert(fs4.pop() == 1);
    assert(fs4.pop() == 2);
    assert(fs4.pop() == 3);

    std::cout << "All test cases passed!" << std::endl;
}
int main() {
    runTestCases();
    return 0;
}
