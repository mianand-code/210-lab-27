// COMSC-210 | Lab 27 | Mira Anand
// Module 10, Lesson: std::map & STL Algorithms, Assignment: Villager Map
// IDE used: Visual Studio Code for Mac

#include <iostream>
#include <map> // to use std::map
#include <string>
#include <tuple> // in order to use std::tuple instead of std::vector as the data structure being held in the std::map
using namespace std;

// function prototypes
void outputVillagerDetails()

int main() 
{
    // creation of an std::map named "villagerMember"
    // the key is a string that represents the villager's name
    // the value is an std::tuple that holds 3 elements:
    // 1. friendship level, an int value 0-10
    // 2. species, a string value
    // 3. catchphrase, a string value
    map<string, tuple<int, string, string>> villagerMember;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    return 0;
}