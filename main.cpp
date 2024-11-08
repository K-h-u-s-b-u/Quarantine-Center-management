#include <iostream>
#include <unordered_map>
#include <vector>
#include "room_check.h"
#include "person.h"
#include "covid_positive.h"
#include "covid_negative.h"

using namespace std;

int main() {
    unordered_map<int, person*> covid_map;  // Map to track rooms and their occupants
    vector<person*> healthy;                 // Vector to store healthy (COVID negative) persons
    vector<person*> unhealthy;               // Vector to store unhealthy (COVID positive) persons

    cout << "                                         Welcome to the Quarantine Centre of NIT Silchar " << endl;

    int choice;
    while (true) {
        cout << "Press 1 for new entry \nPress 2 for search \nPress 3 for deleting \nPress 4 for vacant rooms \nPress 5 for list of all COVID negative people \nPress 6 for list of all COVID positive people\nPress 0 to exit" << endl;
        cin >> choice;

        if (choice < 0 || choice > 6) {
            cout << "Please choose a valid choice: ";
            cin >> choice;
            cout << endl;
            continue; // Return to the beginning of the loop
        }

        if (choice == 0) {
            break; // Exit the loop
        }

        if (choice == 1) {
            cout << "You have chosen 1 :)" << endl;
            int total_entries;
            cout << "Enter the total number of entries: ";
            cin >> total_entries;
            cout << endl;

            for (int checker = 0; checker < total_entries; checker++) {
                bool available = true; // Track room availability
                cout << "Entry No. " << checker + 1 << " : " << endl;
                cout << "Please fill the asked information" << endl;

                string name;
                cout << "Write your name: ";
                cin >> name;

                string address;
                cout << "Write your permanent address: ";
                cin >> address;

                int age;
                cout << "Write your age: ";
                cin >> age;

                int covid_status;
                cout << "If positive enter 1, else enter 2: ";
                cout << "COVID status: ";
                cin >> covid_status;

                if (covid_status == 2) {
                    // Create a new covid_negative instance
                    person* p = new covid_negative(name, address, age, -1, -1);
                    healthy.push_back(p);
                    cout << "COVID Negative, please take care, no need for room allotment" << endl;
                    continue;
                } else {
                    string viral_strain;
                    cout << "Viral strain type: ";
                    cin >> viral_strain;

                    if (age <= 0) {
                        cout << "You have entered an invalid age, please enter a valid age: ";
                        cin >> age;
                    }

                    int room;
                    int floor;

                    if (age > 0 && age <= 40) {
                        if (room_check(1, 100, covid_map)) {
                            cout << "Your room will be on the ground floor, please choose a room between 1-100 (both inclusive): ";
                            cin >> room;
                            floor = 0;

                            // Check room availability
                            while (covid_map.find(room) != covid_map.end() || (room <= 0 || room > 100)) {
                                if (room <= 0 || room > 100) {
                                    cout << "Attention! You have chosen an invalid room number, please choose a room between 1 to 100: ";
                                    cin >> room;
                                } else {
                                    cout << "Choose any other room, this room is already occupied." << endl;
                                    cin >> room;
                                }
                            }
                            cout << endl << "Congratulations!, room no. : " << room << " is now allocated to you." << endl;
                        } else {
                            cout << "No room is available." << endl;
                            available = false;
                        }
                    } else if (age > 40 && age <= 60) {
                        if (room_check(101, 300, covid_map)) {
                            cout << "Your room will be on the first floor, please choose a room between 101-300 (both inclusive): ";
                            cin >> room;
                            floor = 1;

                            // Check room availability
                            while (covid_map.find(room) != covid_map.end() || (room <= 100 || room > 300)) {
                                if (room <= 100 || room > 300) {
                                    cout << "Attention! You have chosen an invalid room number, please choose a room between 101 to 300: ";
                                    cin >> room;
                                } else {
                                    cout << "Choose any other room, this room is already occupied." << endl;
                                    cin >> room;
                                }
                            }
                            cout << endl << "Congratulations!, room no. : " << room << " is now allocated to you." << endl;
                        } else {
                            cout << "No room is available." << endl;
                            available = false;
                        }
                    } else {
                        if (room_check(301, 500, covid_map)) {
                            cout << "Your room will be on the second floor, please choose a room between 301-500 (both inclusive): ";
                            cin >> room;
                            floor = 2;

                            // Check room availability
                            while (covid_map.find(room) != covid_map.end() || (room <= 300 || room > 500)) {
                                if (room <= 300 || room > 500) {
                                    cout << "Attention! You have chosen an invalid room number, please choose a room between 301 to 500: ";
                                    cin >> room;
                                } else {
                                    cout << "Choose any other room, this room is already occupied." << endl;
                                    cin >> room;
                                }
                            }
                            cout << endl << "Congratulations!, room no. : " << room << " is now allocated to you." << endl;
                        } else {
                            cout << "No room is available." << endl;
                            available = false;
                        }
                    }

                    if (available) {
                        // Create a new covid_positive instance
                        person* p = new covid_positive(name, address, age, room, floor, viral_strain);
                        unhealthy.push_back(p);
                        covid_map[room] = p;
                    }
                }
            }
        } else if (choice == 2) {
            cout << "Choose 1 for search by room or choose 2 for search by name: ";
            int search_choice;
            cin >> search_choice;

            if (search_choice == 1) {  // Searching in constant time
                int search_room;
                cout << "Enter room no. to be searched: ";
                cin >> search_room;

                if (covid_map.find(search_room) == covid_map.end()) {
                    cout << "Room is vacant." << endl;
                } else {
                    person* p1 = covid_map[search_room];
                    p1->get_info();
                }
            } else if (search_choice == 2) {   // Searching in O(n)
                string choice_name;
                cout << "Please enter the name of the person: ";
                cin >> choice_name;

                bool found = false;
                for (const auto& it : covid_map) {
                    person* temp = it.second;
                    if (temp->get_name() == choice_name) {
                        temp->get_info();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Sorry, there is no person named: " << choice_name << " in the Quarantine centre right now." << endl;
                }
            }
        } else if (choice == 3) {
            cout << "Enter the room no. to delete: ";
            int delete_room;
            cin >> delete_room;

            if (covid_map.find(delete_room) != covid_map.end()) {
                person* temp = covid_map[delete_room];
                cout << "We are deleting the information of the person in room no. : " << delete_room << endl;
                temp->get_info();
                delete temp;  // Free the allocated memory
                covid_map.erase(delete_room);
            } else {
                cout << "No record found for room number: " << delete_room << endl;
            }
        } else if (choice == 4) {
            cout << "List of vacant rooms are: " << endl;
            for (int i = 1; i <= 500; i++) {
                if (covid_map.find(i) == covid_map.end()) {
                    cout << i << " ";
                }
            }
            cout << endl; // Add a new line for better readability
        } else if (choice == 5) {
            cout << "List of COVID negative people: " << endl;
            for (const auto& person : healthy) {
                cout << person->get_name() << endl;
            }
        } else if (choice == 6) {
            cout << "List of COVID positive people: " << endl;
            for (const auto& person : unhealthy) {
                cout << person->get_name() << endl;
            }
        }
    }
    return 0;
}
