#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

// COMSC-210 | Lab 27 | Ian Kusmiantoro

const int ADD = 1;
const int DELETE = 2;
const int INCREASE = 3;
const int DECREASE = 4;
const int SEARCH = 5;
const int EXIT = 6;

void printMenu();
void printVillagers(const map<string, tuple<int, string, string>>&);
void increaseFriendship(map<string, tuple<int, string, string>>&);
void decreaseFriendship(map<string, tuple<int, string, string>>&);
void searchVillager(const map<string, tuple<int, string, string>>&);
void addVillager(map<string, tuple<int, string, string>>&);
void deleteVillager(map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    // Friendship, Species, Catchphrase
    map<string, tuple<int, string, string>> villagerData;

    // Gonna assume the driver stuff can go away because we're fiating the rest of the
    // assignment now

    // MENU STUFF

    int choice = -1;
    while (choice != EXIT) {
        printMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == ADD) {
            addVillager(villagerData);
        } else if (choice == DELETE) {
            deleteVillager(villagerData);
        } else if (choice == INCREASE) {
            increaseFriendship(villagerData);
        } else if (choice == DECREASE) {
            decreaseFriendship(villagerData);
        } else if (choice == SEARCH) {
            searchVillager(villagerData);
        } else if (choice != EXIT){
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
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
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

// Originally I thought it would increase everyone's but now I think its just of a specific villagers
// So I am changing this, but the instructions are a bit ambiguous
// increaseFriendship() increases friendship level of a villagers by 1
// parameters: map<string, tuple<int, string, string>>& data - the map containing villager data
// returns: void
void increaseFriendship(map<string, tuple<int, string, string>>& data) {
    string name;
    cout << "Villager to increase: ";
    cin >> name;

    auto search = data.find(name);
    if (search != data.end()) {
        if (get<0>(search->second) < 10) { // don't allow exceed 10
            get<0>(search->second)++;
            cout << name << "'s friendship increased" << endl;
        } else {
            cout << name << "'s friendship maxed out" << endl;
        }
    } else {
        cout << name << " not found." << endl;
    }
}

// decreaseFriendship() decreases friendship level of a villagers by 1
// parameters: map<string, tuple<int, string, string>>& data - the map containing villager data
// returns: void
void decreaseFriendship(map<string, tuple<int, string, string>>& data) {
    string name;
    cout << "Villager to decrease: ";
    cin >> name;

    auto search = data.find(name);
    if (search != data.end()) {
        if (get<0>(search->second) > 0) { // don't allow below 0
            get<0>(search->second)--;
            cout << name << "'s friendship decreased" << endl;
        } else {
            cout << name << "'s friendship already 0 :(" << endl;
        }
    } else {
        cout << name << " not found." << endl;
    }
}

// searchVillager() searches for a villager prints details
// parameters: const map<string, tuple<int, string, string>>& data - the map containing villager data
// returns: void
void searchVillager(const map<string, tuple<int, string, string>>& data) {
    string name;
    cout << "Enter villager's name: ";
    cin >> name;

    auto search = data.find(name);
    if (search != data.end()) {
        cout << "Found " << name << "'s data: ";
        cout << "[" << get<0>(search->second) << ", ";
        cout << get<1>(search->second) << ", " ;
        cout << get<2>(search->second) << "]" << endl;
    } else {
        cout << name << " not found." << endl;
    }
}

// addVillager() adds a new villager to map
// parameters: map<string, tuple<int, string, string>>& data - the map containing villager data
// returns: void
void addVillager(map<string, tuple<int, string, string>>& data) {
    string name;
    int friendship;
    string species;
    string catchphrase;

    cout << "Villager name: ";
    cin >> name;

    cout << "Friendship level: ";
    cin >> friendship;
    while (friendship < 0 || friendship > 10) {
        cout << "Friendship level must be 0 to 10 inclusive: ";
        cin >> friendship;
    }

    cout << "Species: ";
    cin >> species;

    cout << "Catchphrase: ";
    cin.ignore(); // When using getline after cin you have to clear the newline characters
    getline(cin, catchphrase);
    
    data[name] = make_tuple(friendship, species, catchphrase);

    cout << name << " added." << endl;
}

// deleteVillager() deletes a villager from map
// parameters: map<string, tuple<int, string, string>>& data - the map containing villager data
// returns: void
void deleteVillager(map<string, tuple<int, string, string>>& data) {
    string name;
    cout << "Enter villager to delete: ";
    cin >> name;

    auto search = data.find(name);
    if (search != data.end()) { // check if name even exists
        data.erase(name);
        cout << name << " deleted." << endl;
    } else {
        cout << name << " not found." << endl;
    }
}