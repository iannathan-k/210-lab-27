#include <iostream>
#include <map>
#include <vector>

using namespace std;

// COMSC-210 | Lab 27 | Ian Kusmiantoro

int main() {
    // declarations
    // Friendship, Species, Catchphrase
    map<string, tuple<int, string, string>> villagerData;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    // villagerData["Audie"] = {"Orange", "Yellow", "Red"};
    // villagerData["Raymond"] = {"Black", "Gray", "White"};
    // villagerData.insert({"Marshal", {"Blue", "White", "Black"}});
    villagerData["Audie"] = make_tuple(7, "Cat", "Meow!");
    villagerData["Raymond"] = make_tuple(3, "Human", "Get of my lawn!");
    villagerData.insert({"Marshal", make_tuple(10, "Dalmation", "Woof!")});

    // access the map using a range-based for loop
    cout << "Villagers and their data (range-based for loop):" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second);
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their data (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerData.begin(); 
                                               it != villagerData.end(); ++it) {
        cout << it->first << ": ";
        cout << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second);
        cout << endl;
    }

    // delete an element
    villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto search = villagerData.find(searchKey);
    if (search != villagerData.end()) { // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s data: ";
        cout << get<0>(search->second) << ", " << get<1>(search->second) << ", " << get<2>(search->second);
    } else {
        cout << endl << searchKey << " not found." << endl;
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}