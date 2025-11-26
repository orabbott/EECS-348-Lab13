#include <vector>
#include <iostream>

using namespace std;


//Error version
bool fail_lecture(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i) { // Fault
        absent_count += attendance_records[i] == 0;
    }
    return absent_count >= 3;
}

// Correct version
bool fail_lecture_correct(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 0; i < attendance_records.size(); ++i) {
        absent_count += attendance_records[i] == 0;
    }
    return absent_count >= 3;
}


int main() {
    cout << fail_lecture_correct({0, 0, 0, 1, 1, 1, 1, 1, 1}) << endl;
}
/*

1. Is there a fault in the program? If so, locate it and explain.

There is a fault at line 9, as identified above. As it currently runs, 
it starts at index 0, meaning it misses the first attendance record. 
Because of this, if a student misses the first lecture, it is not
added to the absence count.

2. Define a test case that does not execute the fault. Start from this ques-
tion, if it is possible, you should give the test case (the attendance record
with 10 values), the expected output and the actual output. If impossible,
explains the reason. Besides, you should implement the complete program,
including the functions under test, and verify your inputs along with their
corresponding outputs.

It is impossible to avoid executing the fault, as there are 10 lectures in total,
meaning the for loop which contains the fault will always execute. (Will always
run "1 < 10")

3. Define a test case that executes the fault but does not result in an error
state.

Any case where first value is [1], as it won't impact the final result. Example:

[1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

4. Define a test case that results in an error state but not a failure.

[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

This is because the first absence is not recorded, but the student still fails.

5. Define a test case that results in failure.

[0, 0, 1, 1, 1, 1, 1, 1, 0]

This is because the first absence is not recorded, and the student is given a "pass",
even though they missed 3 classes.

*/