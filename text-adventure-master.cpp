#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int selectedItem;
bool hasMonster;
bool hasChest;
bool hasMon1;
bool hasMon2;
int currentRoomX = 0;
int currentRoomY = 0;
int currentRoomZ = 0;
int rooms[5][5][5] = {{0, 1, 2, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 2, 3, 4}};
vector<string>commandBreakdown;

vector<string> splitString(string text) {
    vector<string> result;
    istringstream iss(text);
    for (string text; iss >> text;) {
        result.push_back(text);
    }
    return result;
}

void describeRoom() {
    cout << "You are in room " << currentRoomX << ", " << currentRoomY << "\n";

    if (rooms[currentRoomZ] == 0) {

    }
    /*
    if (rooms[currentRoomX] < 5) {
        cout << "The room is normal\n";
    } else if (rooms[currentRoom] < 10) {
        cout << "The room has a surprise\n";
    } else {
        cout << "The room has a riddle boss\n";
    }

    if (rooms[currentRoom] == 0 || rooms[currentRoom] == 5 || rooms[currentRoom] == 10) {
        cout << "The room is empty\n";
    } else if (rooms[currentRoom] == 1 || rooms[currentRoom] == 6 || rooms[currentRoom] == 11) {
        cout << "Room has one monster and is lit\n";
    } else if (rooms[currentRoom] == 2 || rooms[currentRoom] == 7 || rooms[currentRoom] == 12) {
        cout << "Room has a chance of 2 monsters, and is dark\n";
    } else if (rooms[currentRoom] == 3 || rooms[currentRoom] == 8 || rooms[currentRoom] == 13) {
        cout << "Room has a chance of 3 monsters, a chance to be dark, and a co2 problem\n";
    } else if (rooms[currentRoom] == 4 || rooms[currentRoom] == 9 || rooms[currentRoom] == 14) {
        cout << "The room has a Boss\n";

    } */
}

void describeItem() {
    cout << "Item number is " << selectedItem << "\n";
}

void describe() {
    if (commandBreakdown.size() > 1) {
        if (commandBreakdown[1] == "item") {
            describeItem();
        } else if (commandBreakdown[1] == "room") {
            describeRoom();
        }
        else {
            cout << commandBreakdown[1] << " is not valid for description\n";
        }
    } else {
        cout << "describe requires some thing to describe. ex: describe room\n";
    }
}

void movePlayer() {
    if (commandBreakdown.size() > 1) {
        if (commandBreakdown[1] == "forward") {
            if (currentRoomX < 5) {
                currentRoomX++;
                describeRoom();
            } else {
                cout << "You are in the last room \n";
            }
        } else if (commandBreakdown[1] == "back") {
            if (currentRoomX > 0) {
                currentRoomX--;
                describeRoom();
            } else {
                cout << "You are in the first room \n";
            }
        } else if (commandBreakdown[1] == "right") {
            if (currentRoomY < 5) {
                currentRoomY++;
                describeRoom();
            } else {
                cout << "You can't go right any further,\n";
            }
        } else if (commandBreakdown[1] == "left") {
            if (currentRoomY > 0) {
                currentRoomY--;
                describeRoom();
            } else {
                cout << "You can't go any further left \n";
            }
        } else if (commandBreakdown[1] == "up") {
            if (currentRoomZ < 5) {
                currentRoomZ++;
                describeRoom();
            } else {
                cout << "You're at the top floor of the dungeon \n";
            }
        } else if (commandBreakdown[1] == "down") {
            if (currentRoomZ > 0) {
                currentRoomZ--;
                describeRoom();
            } else {
                cout << "You're at the bottom floor of the dungeon"
            }
        }
         else {
            cout << commandBreakdown[1] << " is not a valid direction\n";
        }
    } else {
        cout << "move requires a direction, ex. move forward\n";
    }
}

int main() {
    string command;
    bool runProgram = true;
    selectedItem = 0;
    hasMonster = false;
    hasChest = false;

    while (runProgram == true) {
        cout << "Please enter a command\n";
        getline(cin, command);
        commandBreakdown = splitString(command);
        if (commandBreakdown.size() > 0) {
            if (commandBreakdown[0] == "describe") {
                describe();
            } else if (commandBreakdown[0] == "exit") {
                runProgram = false;
            } else if (commandBreakdown[0] == "move") {
                movePlayer();
            } else {
                cout << command + " is not a valid command\n";
            }
        }
    }

    cout << "\nGood Bye!";
    return 0;
}
