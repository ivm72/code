//Write a program to simulate Go back N and Selective Repeat Modes of Sliding Window Protocol in Peer-to-Peer mode.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void transmission(int &i, int N, int tf, int &tt) {
    while (i <= tf) {
        int sentFrames = 0;

        // Send frames in window
        for (int k = i; k < i + N && k <= tf; k++) {
            cout << "Sending Frame " << k << "..." << endl;
            tt++;
        }

        // Acknowledge frames or retransmit if there's a timeout
        for (int k = i; k < i + N && k <= tf; k++) {
            if (rand() % 2 == 0) {
                cout << "Acknowledgment for Frame " << k << "..." << endl;
                sentFrames++;
            } else {
                cout << "Timeout!! Frame " << k << " Not Received" << endl;
                cout << "Retransmitting Window..." << endl;
                break;  // Retransmit if one frame fails
            }
        }

        // Move the window
        i += sentFrames;
        cout << "\n";
    }
}

int main() {
    int tf, N, tt = 0;
    srand(time(0));

    cout << "Enter the Total number of frames: ";
    cin >> tf;
    cout << "Enter the Window Size: ";
    cin >> N;

    int i = 1;
    transmission(i, N, tf, tt);

    cout << "Total number of frames sent and resent: " << tt << endl;
    return 0;
}





