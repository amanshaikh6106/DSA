#include<iostream>
using namespace std;

#define TOTAL_SLOTS 10

int parkingLot[TOTAL_SLOTS];
bool occupied[TOTAL_SLOTS];

int main()
{
    for(int i = 0; i < TOTAL_SLOTS; i++)
    {
        parkingLot[i] = -1;
        occupied[i] = false;
    }

    int choice;

    while(true)
    {
        cout << "\n----- SMART PARKING LOT MENU -----" << endl;
        cout << "1. Park a Vehicle (Insert)" << endl;
        cout << "2. Find a Vehicle (Search)" << endl;
        cout << "3. Remove a Vehicle (Delete)" << endl;
        cout << "4. Display Parking Lot" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            int carNumber;
            cout << "Enter vehicle registration number (numeric): ";
            cin >> carNumber;

            int index = carNumber % TOTAL_SLOTS;
            int startIndex = index;
            int i = 0;
            bool parked = false;

            while(occupied[index])
            {
                if(parkingLot[index] == carNumber)
                {
                    cout << "Vehicle " << carNumber << " is already parked at slot " << index << endl;
                    parked = true;
                    break;
                }
                i++;
                index = (startIndex + i) % TOTAL_SLOTS;

                if(index == startIndex)
                {
                    cout << "Parking Lot is FULL. Cannot park vehicle " << carNumber << endl;
                    parked = true;
                    break;
                }
            }

            if(!parked)
            {
                parkingLot[index] = carNumber;
                occupied[index] = true;
                cout << "Vehicle " << carNumber << " parked successfully at slot " << index << endl;
            }
        }
        else if(choice == 2)
        {
            int carNumber;
            cout << "Enter vehicle registration number to find: ";
            cin >> carNumber;

            int index = carNumber % TOTAL_SLOTS;
            int startIndex = index;
            int i = 0;
            bool found = false;

            while(occupied[index])
            {
                if(parkingLot[index] == carNumber)
                {
                    cout << "Vehicle " << carNumber << " found at slot " << index << endl;
                    found = true;
                    break;
                }
                i++;
                index = (startIndex + i) % TOTAL_SLOTS;

                if(index == startIndex)
                {
                    break;
                }
            }

            if(!found)
            {
                cout << "Vehicle " << carNumber << " not found in the parking lot." << endl;
            }
        }
        else if(choice == 3)
        {
            int carNumber;
            cout << "Enter vehicle registration number to remove: ";
            cin >> carNumber;

            int index = carNumber % TOTAL_SLOTS;
            int startIndex = index;
            int i = 0;
            bool removed = false;

            while(occupied[index])
            {
                if(parkingLot[index] == carNumber)
                {
                    parkingLot[index] = -1;
                    occupied[index] = false;
                    cout << "Vehicle " << carNumber << " removed from slot " << index << endl;
                    removed = true;
                    break;
                }
                i++;
                index = (startIndex + i) % TOTAL_SLOTS;

                if(index == startIndex)
                {
                    break;
                }
            }

            if(!removed)
            {
                cout << "Vehicle " << carNumber << " not found. Cannot remove." << endl;
            }
        }
        else if(choice == 4)
        {
            cout << "\nParking Lot Status:" << endl;
            for(int i = 0; i < TOTAL_SLOTS; i++)
            {
                cout << "Slot " << i << " : ";
                if(occupied[i])
                {
                    cout << parkingLot[i];
                }
                else
                {
                    cout << "Empty";
                }
                cout << endl;
            }
        }
        else if(choice == 5)
        {
            cout << "Exiting. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}