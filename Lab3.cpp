#include <iostream>
#include <string>
using namespace std;

// define the student structure
struct Student {
    string name;
    int marks[3];
};

// function to display data of all std
void Display_data(Student std[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Student Name: \n" << std[i].name << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Student marks for course: " << j+1 << endl<< std[i].marks[j] << endl;
        }
        cout << endl;
    }
}

// function to change marks of a student
void Change_Marks(Student& student,int c,int New) {
    student.marks[c] = New;
    cout << "Marks updated successfully!" << endl;
}

// function to calculate average marks of a student
float Calc_Average_Marks(Student student) {
    float sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += student.marks[i];
    }
    sum/=3.0;
    return sum;
}

int main() {
    int N;
    cout<<"How many Students to input data ? ";
    cin>>N;
    Student std[N];
    
    // inputting data
    for(int i=0;i<N;i++){ 
       cout<<"\nEnter Student name: \n";
       cin>>std[i].name;
       for(int j=0;j<3;j++){
           cout<<"Enter Student marks for course: "<<j+1<<endl;
           cin>>std[i].marks[j];
       }
    }

    while(true) {
        cout << "\nMenu:\n"
             << "1. Display Student Data\n"
             << "2. Calculate Average marks\n"
             << "3. Change Marks\n";

        cout << "Please select an Option:\n";
        int choice;
        cin >> choice;
        // to display data
        if (choice == 1) {
            Display_data(std, N);
            
            // to Calculate average
        } else if (choice == 2) {
            int n;
            cout << "Enter the student no:\n";
            cin >> n;
            if (n > N)
                cout << "Student out of bound. \n";
            else
                cout << "Average marks: "<< Calc_Average_Marks(std[n-1])<<endl;
            
            // to change student marks
        } else if (choice == 3) {
            int n, c, New;
            cout << "Enter the student no:\n";
            cin >> n;
            cout << "Enter the course Number to change marks: ";
            cin >> c;
            cout << "Enter the updated marks: ";
            cin >> New;
            Change_Marks(std[n-1], c-1, New);


        }

    }

    return 0;
}
