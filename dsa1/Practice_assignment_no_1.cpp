#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    float marks[100];
    int choice;

    do
    {
        cout << "\n===== STUDENT MARK ANALYSIS SYSTEM =====\n";
        cout << "1. Insert Marks\n";
        cout << "2. Delete Marks\n";
        cout << "3. Update Marks\n";
        cout << "4. Analyze Marks\n";
        cout << "5. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            
        case 1:
        {
            if (n >= 100)
            {
                cout << "Array is full!\n";
                break;
            }

            float newMarks;
            int position;

            cout << "Enter position to insert (1-" << n + 1 << "): ";
            cin >> position;

            if (position < 1 || position > n + 1)
            {
                cout << "Invalid position!\n";
                break;
            }

            cout << "Enter marks: ";
            cin >> newMarks;

            
            for (int i = n; i >= position; i--)
            {
                marks[i] = marks[i - 1];
            }

            marks[position - 1] = newMarks;
            n++;

            cout << "Marks inserted successfully!\n";

            break;
        }

        
        case 2:
        {
            if (n == 0)
            {
                cout << "No marks available to delete!\n";
                break;
            }

            int position;

            cout << "Enter position to delete (1-" << n << "): ";
            cin >> position;

            if (position < 1 || position > n)
            {
                cout << "Invalid position!\n";
                break;
            }

            
            for (int i = position - 1; i < n - 1; i++)
            {
                marks[i] = marks[i + 1];
            }

            n--;

            cout << "Marks deleted successfully!\n";

            break;
        }

        
        case 3:
        {
            if (n == 0)
            {
                cout << "No marks available to update!\n";
                break;
            }

            int position;
            float newMarks;

            cout << "Enter position to update (1-" << n << "): ";
            cin >> position;

            if (position < 1 || position > n)
            {
                cout << "Invalid position!\n";
                break;
            }

            cout << "Enter new marks: ";
            cin >> newMarks;

            marks[position - 1] = newMarks;

            cout << "Marks updated successfully!\n";

            break;
        }

        
        case 4:
        {
            if (n == 0)
            {
                cout << "No marks available for analysis!\n";
                break;
            }

            float total = 0;
            float highest = marks[0];
            float lowest = marks[0];

            for (int i = 0; i < n; i++)
            {
                total = total + marks[i];

                if (marks[i] > highest)
                    highest = marks[i];

                if (marks[i] < lowest)
                    lowest = marks[i];
            }

            float percentage = total / n;

            cout << "\n===== STUDENT MARK ANALYSIS =====\n";

            cout << "Marks: ";
            for (int i = 0; i < n; i++)
            {
                cout << marks[i] << " ";
            }

            cout << "\nTotal Marks: " << total << endl;
            cout << "Average Marks: " << percentage << endl;
            cout << "Highest Marks: " << highest << endl;
            cout << "Lowest Marks: " << lowest << endl;

            if (percentage >= 75)
                cout << "Grade: A\n";
            else if (percentage >= 60)
                cout << "Grade: B\n";
            else if (percentage >= 50)
                cout << "Grade: C\n";
            else if (percentage >= 40)
                cout << "Grade: D\n";
            else
                cout << "Grade: Fail\n";

            break;
        }

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}