#include <iostream>
#include <string>
using namespace std;

int main() {
    int choice;
    bool machineOn = false;
    int speed = 0;
    int timer = 0;

    const int MAX_SPEED = 100;
    const int AUTO_SHUTDOWN_LIMIT = 10;

    do {
        cout << "\n================ MACHINE CONTROL SYSTEM ================\n";
        cout << "1. Turn Machine ON\n";
        cout << "2. Turn Machine OFF\n";
        cout << "3. Set Speed\n";
        cout << "4. Set Working Timer\n";
        cout << "5. Show Machine Status\n";
        cout << "6. Run Machine\n";
        cout << "0. Exit\n";
        cout << "========================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            if (machineOn) {
                cout << "Error: Machine is already ON.\n";
            }
            else {
                machineOn = true;
                cout << "Machine has been turned ON successfully.\n";
            }
            break;

        case 2:
            if (!machineOn) {
                cout << "Error: Machine is already OFF.\n";
            }
            else {
                machineOn = false;
                speed = 0;
                timer = 0;
                cout << "Machine has been turned OFF successfully.\n";
            }
            break;

        case 3:
            if (!machineOn) {
                cout << "Error: You must turn the machine ON before setting speed.\n";
            }
            else {
                int newSpeed;
                cout << "Enter speed (0 - " << MAX_SPEED << "): ";
                cin >> newSpeed;

                if (newSpeed < 0 || newSpeed > MAX_SPEED) {
                    cout << "Error: Invalid speed. Maximum allowed speed is " << MAX_SPEED << ".\n";
                }
                else {
                    speed = newSpeed;
                    cout << "Speed has been set to " << speed << ".\n";
                }
            }
            break;

        case 4:
            if (!machineOn) {
                cout << "Error: You must turn the machine ON before setting timer.\n";
            }
            else {
                int newTimer;
                cout << "Enter working timer in minutes: ";
                cin >> newTimer;

                if (newTimer <= 0) {
                    cout << "Error: Timer must be greater than 0.\n";
                }
                else {
                    timer = newTimer;
                    cout << "Timer has been set to " << timer << " minute(s).\n";
                }
            }
            break;

        case 5:
            cout << "\n---------------- MACHINE STATUS ----------------\n";
            cout << "Power Status : " << (machineOn ? "ON" : "OFF") << endl;
            cout << "Speed        : " << speed << endl;
            cout << "Timer        : " << timer << " minute(s)" << endl;
            cout << "Max Speed    : " << MAX_SPEED << endl;
            cout << "------------------------------------------------\n";
            break;

        case 6:
            if (!machineOn) {
                cout << "Error: Machine is OFF. Please turn it ON first.\n";
            }
            else if (speed == 0) {
                cout << "Error: Speed is 0. Please set the speed first.\n";
            }
            else if (timer == 0) {
                cout << "Error: Timer is not set. Please set the working timer first.\n";
            }
            else {
                cout << "\nMachine is now running...\n";
                cout << "Speed: " << speed << endl;
                cout << "Working time: " << timer << " minute(s)\n";

                if (timer >= AUTO_SHUTDOWN_LIMIT) {
                    cout << "Warning: Auto shutdown activated because the timer reached the safety limit.\n";
                    machineOn = false;
                    speed = 0;
                    timer = 0;
                    cout << "Machine has been automatically turned OFF.\n";
                }
                else {
                    cout << "Machine completed its task successfully.\n";
                }
            }
            break;

        case 0:
            cout << "Exiting the system...\n";
            break;

        default:
            cout << "Error: Invalid menu choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}