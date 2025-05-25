#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to simulate the receiver's behavior
bool receiveFrame(int frameNumber) {
    // Simulate a 90% chance of successfully receiving a frame
    return rand() % 10 < 9;
}

// Function to simulate the sender's behavior
void sender(int totalFrames, int windowSize) {
    int nextFrameToSend = 0;
    vector<bool> frameStatus(totalFrames, false); // Track acknowledgment status

    while (nextFrameToSend < totalFrames) {
        // Send frames within the window
        for (int i = 0; i < windowSize && nextFrameToSend < totalFrames; ++i) {
            cout << "Sender: Sending Frame " << nextFrameToSend << endl;
            nextFrameToSend++;
        }

        // Wait for acknowledgments
        for (int i = 0; i < windowSize && nextFrameToSend - i - 1 >= 0; ++i) {
            int frameIndex = nextFrameToSend - i - 1;
            if (receiveFrame(frameIndex)) {
                frameStatus[frameIndex] = true;
                cout << "Sender: Acknowledgment received for Frame " << frameIndex << endl;
            } else {
                cout << "Sender: Timeout! Frame " << frameIndex << " not received." << endl;
                // Retransmit the frame
                cout << "Sender: Retransmitting Frame " << frameIndex << endl;
                nextFrameToSend = frameIndex + 1; // Reset to retransmit this frame
                break;
            }
        }
    }
    cout << "Sender: All frames sent successfully." << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int totalFrames, windowSize;
    cout << "Enter the total number of frames: ";
    cin >> totalFrames;
    cout << "Enter the window size: ";
    cin >> windowSize;

    sender(totalFrames, windowSize);

    return 0;
}

