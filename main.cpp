#include <iostream>
#include <map>
#include <vector>

using namespace std;

// COMSC-210 | Lab 27 | Ian Kusmiantoro

const int INCREASE = 1;
const int DECREASE = 2;
const int SEARCH = 3;
const int EXIT = 4;

void printMenu();
void printVillagers(const map<string, tuple<int, string, string>>&);
void increaseFriendship(map<string, tuple<int, string, string>>&);
void decreaseFriendship(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    // Friendship, Species, Catchphrase
    map<string, tuple<int, string, string>> villagerData;

    // // insert elements into the map
    // // note how the right-hand side of the assignment are the vector elements
    // // villagerData["Audie"] = {"Orange", "Yellow", "Red"};
    // // villagerData["Raymond"] = {"Black", "Gray", "White"};
    // // villagerData.insert({"Marshal", {"Blue", "White", "Black"}});
    // villagerData["Audie"] = make_tuple(7, "Cat", "Meow!");
    // villagerData["Raymond"] = make_tuple(3, "Human", "Get of my lawn!");
    // villagerData.insert({"Marshal", make_tuple(10, "Dalmation", "Woof!")});

    // // access the map using a range-based for loop
    // cout << "Villagers and their data (range-based for loop):" << endl;
    // for (auto pair : villagerData) {
    //     cout << pair.first << ": ";
    //     cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second);
    //     cout << endl;
    // }

    // // access the map using iterators
    // cout << "\nVillagers and their data (iterators):" << endl;
    // for (map<string, tuple<int, string, string>>::iterator it = villagerData.begin(); 
    //                                            it != villagerData.end(); ++it) {
    //     cout << it->first << ": ";
    //     cout << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second);
    //     cout << endl;
    // }

    // // delete an element
    // villagerData.erase("Raymond");

    // // search for an element using .find() to avoid errors
    // string searchKey = "Audie";
    // auto search = villagerData.find(searchKey);
    // if (search != villagerData.end()) { // the iterator points to beyond the end of the map
    //                                    // if searchKey is not found
    //     cout << "\nFound " << searchKey << "'s data: ";
    //     cout << get<0>(search->second) << ", " << get<1>(search->second) << ", " << get<2>(search->second);
    // } else {
    //     cout << endl << searchKey << " not found." << endl;
    // }

    // // report size, clear, report size again to confirm map operations
    // cout << "\nSize before clear: " << villagerData.size() << endl;
    // villagerData.clear();
    // cout << "Size after clear: " << villagerData.size() << endl;

    // MENU STUFF

    int choice = -1;
    while (choice != EXIT) {
        printMenu();
        cin >> choice;

        if (choice == INCREASE) {

        } else {
            cout << "Invalid choice, try again: " << endl;
        }

        printVillagers(villagerData);
    }

    return 0;
}

// printMenu() prints the menu options to the user
// parameters: none
// returns: void
void printMenu() {
    cout << "1. Increase Friendship" << endl;
    cout << "2. Decrease Friendship" << endl;
    cout << "3. Search for Villager" << endl;
    cout << "4. Exit" << endl;
}

// printVillagers() prints details of all villagers
// parameters: const map<string, tuple<int, string, string>>& data - the map containing villager data
// returns: void
void printVillagers(const map<string, tuple<int, string, string>>& data) {
    cout << "Villager details:" << endl;
    for (auto pair : data) {
        cout << pair.first << ": ";
        cout << "[" << get<0>(pair.second) << ", ";
        cout << get<1>(pair.second) << ", " ;
        cout << get<2>(pair.second) << "]" << endl;
    }
}

// increaseFriendship() increases friendship level of all villagers by 1
// parameters: map<string, tuple<int, string, string>>& data - the map containing villager data
// returns: void
void increaseFriendship(map<string, tuple<int, string, string>>& data) {
    for (auto& pair : data) {
        if (get<0>(pair.second) < 10) { // don't allow exceed 10
            get<0>(pair.second)++;
        }
    }
}

// decreaseFriendship() decreases friendship level of all villagers by 1
// parameters: map<string, tuple<int, string, string>>& data - the map containing villager data
// returns: void
void decreaseFriendship(map<string, tuple<int, string, string>>& data) {
    for (auto& pair : data) {
        if (get<0>(pair.second) > 0) { // don't allow below 0
            get<0>(pair.second)--;
        }
    }
}