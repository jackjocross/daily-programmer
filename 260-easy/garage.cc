#include <iostream>
#include <string>

using namespace std;

string determineNextState(string currentState, string action);

int main(int argc, const char** argv) {
    const int INPUT_LENGTH = 8;
  
    string inputs[INPUT_LENGTH];

    inputs[0] = "button_clicked";
    inputs[1] = "cycle_complete";
    inputs[2] = "button_clicked";
    inputs[3] = "button_clicked";
    inputs[4] = "button_clicked";
    inputs[5] = "button_clicked";
    inputs[6] = "button_clicked";
    inputs[7] = "cycle_complete";

    string currentState = "CLOSED";
    cout << "Door " << currentState << endl;

    for (int i = 0;i < INPUT_LENGTH; i++) {
        
        currentState = determineNextState(currentState, inputs[i]);
        cout << "> " << inputs[i] << endl;
        cout << "Door " << currentState << endl;
    }

    return 0;
}

string determineNextState(string currentState, string action) {
    if (currentState == "CLOSED") {
        if (action == "button_clicked") {
            return "OPENING";
        } else {
            return "CLOSED";
        }
    } else if (currentState == "OPENING") {
        if (action == "button_clicked") {
            return "STOPPED_WHILE_OPENING";
        } else {
            return "OPENED";
        }
    } else if (currentState == "STOPPED_WHILE_OPENING") {
        if (action == "button_clicked") {
            return "CLOSING";
        } else {
            return "STOPPED_WHILE_OPENING";
        }
    } else if (currentState == "CLOSING") {
        if (action == "button_clicked") {
            return "STOPPED_WHILE_CLOSING";
        } else {
            return "CLOSED";
        }
    } else if (currentState == "STOPPED_WHILE_CLOSING") {
        if (action == "button_clicked") {
            return "OPENING";
        } else {
            return "STOPPED_WHILE_CLOSING";
        }
    } else if (currentState == "OPENED") {
        if (action == "button_clicked") {
            return "CLOSING";
        } else {
            return "OPENED";
        }
    }
    return "CLOSED";
}
