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
// DESCRIPTION: this function will output the map's contents of villager data/members
// ARGUMENTS: const map<string, tuple<int, string, string>>& villagerMember
// - this refers to the std::map "villagerMember"
// - using const to signify that the map should not change
// RETURNS: nothing, void function
void outputVillagerDetails(const map<string, tuple<int, string, string>>& villagerMember)
{
    // access the map using a range-based for loop
    cout << "Villager details:" << endl;
    for (auto villager : villagerMember) 
    {
        // villager.first accesses the key (villager's name - string) of the map
        // villager.second accesses the value (std::tuple) of the map
        // get<> is used to access specific elements of the tuple (starts at 0)
        cout << villager.first << " [" << get<0>(villager.second) << ", "; // accesses friendship level
        cout << get<1>(villager.second) << ", "; // accesses species
        cout << get<2>(villager.second) << "]" << endl; // accesses catchphrase
    }
}

// void main_menu() function header
// DESCRIPTION: this function will display the villager map menu of numbered options that a user can choose from
// ARGUMENTS: no arguments/parameters
// RETURNS: nothing, void function
void main_menu()
{
    cout << "Villager Map Main Menu:" << endl;
    cout << "[1] Add Villager" << endl;
    cout << "[2] Delete Villager" << endl;
    cout << "[3] Increase Friendship" << endl;
    cout << "[4] Decrease Friendship" << endl;
    cout << "[5] Search for Villager" << endl;
    cout << "[6] Exit" << endl;
    cout << "Choice --> ";
}

// void addVillager(map<string, tuple<int, string, string>>& villagerMember) function header
// DESCRIPTION:
// ARGUMENTS: map<string, tuple<int, string, string>>& villagerMember
// - this refers to the std::map "villagerMember"
// RETURNS: nothing, void function
void addVillager(map<string, tuple<int, string, string>>& villagerMember)
{
    // declaration of variables section
    string name; // to hold villager's name
    int friendshipLevel; // to hold friendship level (0-10)
    string species; // to hold species of villager
    string catchphrase; // to hold villager's catchphrase

    cout << "Please enter all required information to add a villager -" << endl;

    // get user input for villager's name
    cout << "Villager name: ";
    getline(cin, name);
    while (name.empty()) // user input validation, to ensure the field is not left blank
    {
        cout << "ERROR: Name field cannot remain blank. Please try again & enter a name: ";
        getline(cin, name);
    }

    // get user input for friendship level
    // creation of a do-while loop for user input validatio - ensure the friendship level entered is within the valid range 0-10 
    do {
        cout << "Friendship level (must be between 0-10): ";
        cin >> friendshipLevel;

        if (friendshipLevel < 0 || friendshipLevel > 10)
            cout << "ERROR: Friendship level must be within the range of 0-10. Please enter a valid level and try again." << endl;

    } while (friendshipLevel < 0 || friendshipLevel > 10);
    cin.ignore(); // needed before we can read another string input

    // get user input for species of villager
    cout << "Species: ";
    getline(cin, species);
    while (species.empty()) // user input validation, to ensure the field is not left blank
    {
        cout << "ERROR: Species field cannot remain blank. Please try again & enter a species: ";
        getline(cin, species);
    }

    // get user input for villager's catchphrase
    cout << "Catchphrase: ";
    getline(cin, catchphrase);
    while (catchphrase.empty()) // user input validation, to ensure the field is not left blank
    {
        cout << "ERROR: Catchphrase field cannot remain blank. Please try again & enter a catchphrase: ";
        getline(cin, catchphrase);
    }

    // create a tuple with the user-entered data and add it to the std::map
    // user-entered "name" is used as the key for the std::map
    villagerMember[name] = tuple<int, string, string>(friendshipLevel, species, catchphrase);
    cout << name << " added." << endl;
}