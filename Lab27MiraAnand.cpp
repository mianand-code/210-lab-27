// COMSC-210 | Lab 27 | Mira Anand
// Module 10, Lesson: std::map & STL Algorithms, Assignment: Villager Map
// IDE used: Visual Studio Code for Mac

// Disclaimer about the void searchForVillager(const map<string, tuple<int, string, string>> villagerMember) function:
// - The function trusts that the user will search for a villager name exactly as it is stored in the std::map. It is case sensitive.

#include <iostream>
#include <map> // to use std::map
#include <string>
#include <tuple> // so we can use std::tuple instead of std::vector as the data structure being held in the std::map
using namespace std;

// function prototypes
void outputVillagerDetails(const map<string, tuple<int, string, string>> villagerMember);
void main_menu();
void addVillager(map<string, tuple<int, string, string>>& villagerMember);
void deleteVillager(map<string, tuple<int, string, string>>& villagerMember);
void increaseFriendship(map<string, tuple<int, string, string>>& villagerMember);
void decreaseFriendship(map<string, tuple<int, string, string>>& villagerMember);
void searchForVillager(const map<string, tuple<int, string, string>> villagerMember);

int main() 
{
     // creation of an std::map named "villagerMember"
    // the key is a string that represents the villager's name
    // the value is an std::tuple that holds 3 elements:
    // 1. friendship level, an int value 0-10
    // 2. species, a string value
    // 3. catchphrase, a string value
    map<string, tuple<int, string, string>> villagerMember;

    // insert 3 initial villagers into the std::map, so the user starts off with an std::map that is not empty
    // villager info taken from lab instructions
    villagerMember["Drago"] = tuple<int, string, string>(5, "Alligator", "Snap to It!");
    villagerMember["Kyle"] = tuple<int, string, string>(10, "Wolf", "Hubba hubba!");
    villagerMember["Raymond"] = tuple<int, string, string>(8, "Cat", "Nice fit");

    // display the current std::map
    cout << "These are the initial villagers that have been added -" << endl;
    outputVillagerDetails(villagerMember); // outputVillagerDetails() function call, will display the current contents of the std::map
    
    int userChoice; // to hold the user's choice for the menu option # they would like to select

    do // creation of a do-while loop so that the user can continue to select menu options until they wish to quit program (option #6)
    { 
        main_menu(); // main_menu() function call, will display the menu of task options the user can choose from
        cin >> userChoice; // get user input for option they would like to select
        
        // creation of a switch statement that handles cases of each numbered menu option based on userChoice
        switch (userChoice)
        {
            case 1:
                addVillager(villagerMember); // addVillager() function call, will add a villager to the std::map
                break;

            case 2:
                deleteVillager(villagerMember); // deleteVillager() function call, will delete a specified villager from the std::map
                break;

            case 3:
                increaseFriendship(villagerMember); // increaseFriendship() function call, will increase the friendship level of a certain villager (if within valid range)
                break;
            
            case 4:
                decreaseFriendship(villagerMember); // decreaseFriendship() function call, will decrease the friendship level of a certain villager (if within valid range)
                break;

            case 5:
                searchForVillager(villagerMember); // searchForVillager() function call, will attempt to find a certain villager within the std::map
                break;

            case 6:
                // user wants to exit program
                cout << "Exiting program..." << endl;
                break;
            
            // user input validation for menu option # (has to be 1-6)
            default:
                cout << "Invalid choice. Please try again & enter a valid option between 1-6." << endl << endl;
                continue; // added so villager details are not printed if user selects an invalid menu option
        }

        // after each operation is complete (besides exit), output the map's contents
        if (userChoice != 6)
            outputVillagerDetails(villagerMember); // outputVillagerDetails() function call, will display the current contents of the std::map

    } while (userChoice != 6); // do as long as user does not select option #6 (exit)

    return 0;
}

// void outputVillagerDetails(const map<string, tuple<int, string, string>> villagerMember) function header
// DESCRIPTION: this function will output the map's contents (villager data/members)
// ARGUMENTS: const map<string, tuple<int, string, string>> villagerMember
// - this refers to the std::map "villagerMember"
// - using const to signify that the map should not change
// RETURNS: nothing, void function
void outputVillagerDetails(const map<string, tuple<int, string, string>> villagerMember)
{
    int villagerNumber = 1; // to keep a count of the # of villagers in the std::map
    
    // access the map using a range-based for loop
    cout << endl;
    cout << "Villager details:" << endl;
    for (auto villager : villagerMember) 
    {
        // villager.first accesses the key (villager's name - string) of the map
        // villager.second accesses the value (std::tuple) of the map
        // get<> is used to access specific elements of the tuple (starts at 0)
        cout << villagerNumber++ << "). " << villager.first << " ["; // villager is numbered and key (name) is accessed
        cout << get<0>(villager.second) << ", "; // accesses friendship level
        cout << get<1>(villager.second) << ", "; // accesses species
        cout << get<2>(villager.second) << "]" << endl; // accesses catchphrase
    }

     cout << endl;
}

// void main_menu() function header
// DESCRIPTION: this function will display the villager map menu that a user can choose from
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
// DESCRIPTION: this function prompts the user to enter information in order to add a new villager to the std::map
// - all user input is validated and the user will continue to be prompted to enter information until they enter a valid response
// ARGUMENTS: map<string, tuple<int, string, string>>& villagerMember
// - this refers to the std::map "villagerMember"
// - passing by reference because the map will be modified
// RETURNS: nothing, void function
void addVillager(map<string, tuple<int, string, string>>& villagerMember)
{
    // declaration of variables section
    string name; // to hold villager's name
    int friendshipLevel; // to hold friendship level (0-10)
    string species; // to hold species of villager
    string catchphrase; // to hold villager's catchphrase

    cout << "Please enter all required information to add a villager -" << endl;
    cin.ignore();

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
    do 
    {
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

    // add this new villager to the std::map, "villagerMember"
    // user-entered "name" is used as the key 
    // for the value - create a tuple with the user-entered data and assign/associate it to the std::map's key
    villagerMember[name] = tuple<int, string, string>(friendshipLevel, species, catchphrase);
    cout << name << " added." << endl;
}

// void deleteVillager(map<string, tuple<int, string, string>>& villagerMember) function header
// DESCRIPTION: this function prompts the user to enter a villager they would like to delete from the std::map
// - a numbered menu of villagers is provided for the user to choose from and the user must enter a valid numbered option
// - user input validation is included (no # less than 1, no # greater than the size of the std::map)
// - the user will be prompted to enter a response until it is valid
// ARGUMENTS: map<string, tuple<int, string, string>>& villagerMember
// - this refers to the std::map "villagerMember"
// - passing by reference because the map will be modified
// RETURNS: nothing, void function
void deleteVillager(map<string, tuple<int, string, string>>& villagerMember)
{
    int userChoice; // to hold the numbered option of the villager that the user would like to delete

    cout << "Please select the villager # that you would like to delete -" << endl;
    outputVillagerDetails(villagerMember); // outputVillagerDetails() function call, to display the current std::map of villagers

    // get user input for villager # they would like to delete
    // user input validation is included, to ensure the user does not enter any number less than 1 or greater than the size of the std::map
    while (true) // user will be prompted to enter a choice until it is valid
    {
        cout << "Choice --> ";
        cin >> userChoice;

        if (userChoice >= 1 && userChoice <= villagerMember.size()) // using .size() member function to measure the current size of the std::map
        {
            auto it = villagerMember.begin(); // create an iterator and initialize it to start at the beginning of the std::map by using .begin() member function
            for (int i = 1; i < userChoice; i++) // using a for loop to advance the iterator to the position of the villager we want to delete
            {
                it++;
            }

            villagerMember.erase(it); // using .erase() member function, to erase the villager at the position of the iterator
            break;
        }
        else
            cout << "ERROR: Choice must be greater than 0 and cannot exceed size of map. Please try again." << endl;
    }
}

// void increaseFriendship(map<string, tuple<int, string, string>>& villagerMember) function header
// DESCRIPTION: this function will increase the friendship level of a villager by 1 point
// - the user will be prompted to provide a choice for which villager they would like to perform this action on
// - a numbered menu of villagers is provided for the user to choose from and the user must enter a valid numbered option
// - the user will be prompted to enter a choice until it is valid
// - the friendship level will only be increased as long as it is within range (not more than 10)
// ARGUMENTS: map<string, tuple<int, string, string>>& villagerMember
// - this refers to the std::map "villagerMember"
// - passing by reference because the map will be modified
// RETURNS: nothing, void function
void increaseFriendship(map<string, tuple<int, string, string>>& villagerMember)
{
    int userChoice; // to hold the numbered option of the villager that the user would like to increase the friendship level for

    cout << "Please select the villager # that you would like to increase the friendship level for -" << endl;
    outputVillagerDetails(villagerMember); // outputVillagerDetails() function call, to display the current std::map of villagers

    // get user input for villager # they would like to increase the friendship level for
    // user input validation is included, to ensure the user does not enter any number less than 1 or greater than the size of the std::map
    while (true) // user will be prompted to enter a choice until it is valid
    {
        cout << "Choice --> ";
        cin >> userChoice;

        // if - determines if the user choice for villager is within a valid range
        if (userChoice >= 1 && userChoice <= villagerMember.size()) // using .size() member function to measure the current size of the std::map
        {
            auto it = villagerMember.begin(); // create an iterator and initialize it to start at the beginning of the std::map by using .begin() member function
            for (int i = 1; i < userChoice; i++) // using a for loop to advance the iterator to the position of the villager we want to delete
            {
                it++;
            }

            // retrieve the current friendship level of the villager and store it in "friendshipLevel" variable
            // to ensure we increase the friendship level only if its within valid range (no more than 10)
            // it->second accesses the tuple within the map
            // get<0> accesses first element of the tuple, which is friendship level
            int friendshipLevel = get<0>(it->second);
            
            // if - perform a check to ensure increasing friendship level will keep the level within the valid range
            if (friendshipLevel < 10)
            {
                friendshipLevel++; // increase level by a point
                get<0>(it->second) = friendshipLevel; // update friendship level in the tuple to the new value stored in "friendshipLevel"
                cout << "The friendship level has been increased by a point." << endl;
            }
            else
                cout << "Friendship level cannot be increased. Level is already at the maximum (10)." << endl;

            break; // break out of while (true) loop, meaning userChoice is valid
        }
        else
            cout << "ERROR: Choice must be greater than 0 and cannot exceed size of map. Please try again." << endl;
            
    }
}

// void decreaseFriendship(map<string, tuple<int, string, string>>& villagerMember) function header
// DESCRIPTION: this function will decrease the friendship level of a villager by 1 point
// - the user will be prompted to provide a choice for which villager they would like to perform this action on
// - a numbered menu of villagers is provided for the user to choose from and the user must enter a valid numbered option
// - the user will be prompted to enter a choice until it is valid
// - the friendship level will only be decreased as long as it is within range (not less than 0)
// ARGUMENTS: map<string, tuple<int, string, string>>& villagerMember
// - this refers to the std::map "villagerMember"
// - passing by reference because the map will be modified
// RETURNS: nothing, void function
void decreaseFriendship(map<string, tuple<int, string, string>>& villagerMember)
{
    int userChoice; // to hold the numbered option of the villager that the user would like to decrease the friendship level for

    cout << "Please select the villager # that you would like to decrease the friendship level for -" << endl;
    outputVillagerDetails(villagerMember); // outputVillagerDetails() function call, to display the current std::map of villagers

    // get user input for villager # they would like to decrease the friendship level for
    // user input validation is included, to ensure the user does not enter any number less than 1 or greater than the size of the std::map
    while (true) // user will be prompted to enter a choice until it is valid
    {
        cout << "Choice --> ";
        cin >> userChoice;

        // if - determines if the user choice for villager is within a valid range
        if (userChoice >= 1 && userChoice <= villagerMember.size()) // using .size() member function to measure the current size of the std::map
        {
            auto it = villagerMember.begin(); // create an iterator and initialize it to start at the beginning of the std::map by using .begin() member function
            for (int i = 1; i < userChoice; i++) // using a for loop to advance the iterator to the position of the villager we want to delete
            {
                it++;
            }

            // retrieve the current friendship level of the villager and store it in "friendshipLevel" variable
            // to ensure we decrease the friendship level only if its within valid range (no less than 0)
            // it->second accesses the tuple within the map
            // get<0> accesses first element of the tuple, which is friendship level
            int friendshipLevel = get<0>(it->second);
            
            // if - perform a check to ensure decreasing friendship level will keep the level within the valid range
            if (friendshipLevel > 0)
            {
                friendshipLevel--; // decrease level by a point
                get<0>(it->second) = friendshipLevel; // update friendship level in the tuple to the new value stored in "friendshipLevel"
                cout << "The friendship level has been decreased by a point." << endl;
            }
            else
                cout << "Friendship level cannot be decreased. Level is already at the minimum (0)." << endl;

            break; // break out of while (true) loop, meaning userChoice is valid
        }
        else
            cout << "ERROR: Choice must be greater than 0 and cannot exceed size of map. Please try again." << endl;
            
    }
}

// void searchForVillager(const map<string, tuple<int, string, string>> villagerMember) function header
// DESCRIPTION: this function will prompt the user to enter a villager name and this name/key will be searched for within the std::map
// - name entry is case sensitive and the user is informed of this. I have it this way so I could re-use the demo code from the module as much as possible
// - if the villager is found, the villager's information (tuple) will be printed
// - the user will be informed if the villager is not found
// ARGUMENTS: const map<string, tuple<int, string, string>> villagerMember
// - this refers to the std::map "villagerMember"
// - using const to signify that the map should not change
// RETURNS: nothing, void function
void searchForVillager(const map<string, tuple<int, string, string>> villagerMember)
{
   // get user input for villager they want to search for (by name/key)
    string searchKey; // to hold the villager's name (key) to be searched for
    cin.ignore();
    cout << "Please enter the name of the villager you want to search for (case sensitive): ";
    getline(cin, searchKey);
    while (searchKey.empty()) // user input validation, to ensure the field is not left blank
    {
        cout << "ERROR: Name field cannot remain blank. Please try again & enter a name: ";
        getline(cin, searchKey);
    }

    auto it = villagerMember.find(searchKey); // create an iterator and set it to search for the villager using .find() member function

    if (it != villagerMember.end()) // perform a check using .end() to ensure that the iterator has not gone beyond the range of the std::map
    { 
        // display the villager information since it was found
        cout << "Found the information for " << searchKey << ":" << endl;
        cout << "Friendship level = " << get<0>(it->second) << endl;
        cout << "Species = " << get<1>(it->second) << endl;
        cout << "Catchphrase = " << get<2>(it->second) << endl;
    } 
    else
        cout << endl << searchKey << " not found." << endl;
}