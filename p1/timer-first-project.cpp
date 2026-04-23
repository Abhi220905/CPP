#include <iostream>
using namespace std;

class TimeConverter {
private:
    int hours, minutes, seconds;

public:
    // Seconds to HH:MM:SS
    void secondsToTime(int totalSeconds) {
        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;

        cout << "HH:MM:SS => "
             << hours << ":" << minutes << ":" << seconds << endl;
    }

    // HH:MM:SS to Seconds
    void timeToSeconds(int h, int m, int s) {
        int totalSeconds = (h * 3600) + (m * 60) + s;
        cout << "Total seconds: " << totalSeconds << endl;
    }

    void menu() {
        int choice;

        
        
        do{
            cout << "1. Seconds to HH:MM:SS\n";
            cout << "2. HH:MM:SS to Seconds\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: {
                    int totalSeconds;
                    cout << "Enter total seconds: ";
                    cin >> totalSeconds;
                    secondsToTime(totalSeconds);
                    break;
                }
    
                case 2: {
                    int h, m, s;
                    cout << "Enter hours: ";
                    cin >> h;
                    cout << "Enter minutes: ";
                    cin >> m;
                    cout << "Enter seconds: ";
                    cin >> s;
                    timeToSeconds(h, m, s);
                    break;
                }

                case 3:{
                    cout << "Exiting program...\n";
                    break;
                }
    
                default:
                    cout << "Invalid choice!" << endl;
            }

        }while(choice != 3);
        
        

    }

    
};

int main() {
    
    TimeConverter t;

    t.menu();

    return 0;
}