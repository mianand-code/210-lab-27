// COMSC-210 | Lab 27 | Mira Anand
// Module 10, Lesson: std::map & STL Algorithms, Assignment: Villager Map
// IDE used: Visual Studio Code for Mac

// Disclaimer about the void searchForVillager(const map<string, tuple<int, string, string>>& villagerMember) function:
// - The function trusts that the user will search for a villager name exactly as it is stored in the std::map. It is case sensitive.

#include <iostream>
#include <map> // to use std::map
#include <string>
#include <tuple> // so we can use std::tuple instead of std::vector as the data structure being held in the std::map
using namespace std;

// function prototypes
void outputVillagerDetails(const map<string, tuple<int, string, string>>& villagerMember);
void main_menu();
void addVillager(map<string, tuple<int, string, string>>& villagerMember);
void deleteVillager(map<string, tuple<int, string, string>>& villagerMember);
void increaseFriendship(map<string, tuple<int, string, string>>& villagerMember);
void decreaseFriendship(map<string, tuple<int, string, string>>& villagerMember);
void searchForVillager(const map<string, tuple<int, string, string>>& villagerMember);

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

// void outputVillagerDetails(const map<string, tuple<int, string, string>>& villagerMember) function header
// DESCRIPTION:
// ARGUMENTS:
// RETURNS: nothing, void function
void outputVillagerDetails(const map<string, tuple<int, string, string>>& villagerMember)
{
    // access the map using a range-based for loop
    cout << "Villager details:" << endl;
    for (auto villager : villagerMember) 
    {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }
}