#include <iostream>
#include <cstring>
using namespace std;

// Checking if the char is present in the frames or not
bool Present(string frame, char k) {
    for (int i=0;i<frame.length();i++) {
        if (k == frame[i]) return true;
    }
    return false;
}

int main() {
    cout << "FIFO" << endl;
    int n;
    cout << "Enter no. of frames : ";
    cin >> n;
    string frame(n,' '); 
    string str;
    cout << "Enter input string : ";
    cin >> str;
    int k = 0, pageFaults = 0;
    for (int i=0;i<str.length();i++) {
        if (Present(frame,str[i])) continue;
        else {
            frame[k++] = str[i];
            ++pageFaults;
        }
        if (k == n) k = 0;
    }
    cout << "No. of page faults for the given string = " << pageFaults << endl;
    return 0;
}