//
//  main.cpp
//  week5
//
//  Created by Jordon Marchesano on 11/13/24.
//

#include <iostream>
#include <string>
using namespace std;


const int MONTHS = 12;
string months[MONTHS] = {
    "January", "February", "March", "April","May", "June",
        "July", "August", "September", "October", "November", "December"
    };
struct Airport  {
    int planesLanded[MONTHS];
    int planesDeparted[MONTHS];
    int greatestNumLanded[MONTHS];
    int smallestNumLanded[MONTHS];
  
};


Airport lax;
void promptFunc();
int findSmallest(int[]);
int findLargest(int[]);
int findTotal(int[]);
int findAverage(int[]);
void promptFunc (Airport &lax){
    string planesDepartedPrompt = "Please enter the number of planes that departed in ";
    string planesLandedPrompt = "Please enter the number of planes that landed in ";
    string leastLanded = "Please enter the least number of planes that landed in a single day in ";
    string mostLanded = "Please enter the greatest number of planes that landed in a single day in ";


    for (int j = 0; j < MONTHS; j ++){

        cout << planesLandedPrompt << months[j] << ": ";
        cin >> lax.planesLanded[j];
        cout << planesDepartedPrompt << months[j] << ": " ;
        cin >> lax.planesDeparted[j];
        cout << mostLanded << months[j] << ": " ;
        cin >> lax.greatestNumLanded[j];
        cout << leastLanded << months[j] << ": " ;
        cin >> lax.smallestNumLanded[j];
    }
    
}

int findSmallest(int values[]) {
    int temp = values[0];
    int index = 0;
    
    for (int i = 0; i < MONTHS; i++) {
        if (values[i] == 0) {
            return i;
        } else if (values[i] < temp) {
            temp = values[i];
            index = i;
        }
    }
    return index;
}

int findLargest(int values[]) {
    int temp = values[0];
    int index = 0;
    for (int i = 0; i < MONTHS; i++) {
        if (values[i] > temp) {
            temp = values[i];
            index = i;
        }
    }
    return index;
}
int findTotal(int values[]){
    int total = 0;
    for (int i = 0; i < MONTHS; i++){
        total += values[i];
    }
    return total;
}

int findAverage(int values[]){
    return findTotal(values) / 4;
}


int main(int argc, const char * argv[]) {
    int studentId1, studentId2;
    studentId1 = 900536880;
    studentId2 = 900914917;
    string nameStudent1, nameStudent2;
    nameStudent1 = "Jordon Marchesano";
    nameStudent2 = "Glen Dsouza";
    cout  << left << setw(18) << "Student Name: " << nameStudent1 << endl;
    cout  << left << setw(18) << "Student ID: " << studentId1 << endl;
    cout  << left << setw(18) << "Student Name: " << nameStudent2 << endl;
    cout  << left << setw(18) << "Student ID: " << studentId2 << "\n" << endl;
    promptFunc(lax);
    int largestDepartIndex = findLargest(lax.planesDeparted);
    int largestLandingIndex = findLargest(lax.planesLanded);
    int smallestNumLanded = findSmallest(lax.smallestNumLanded);
    cout << "The average monthly landings for the year is " << findAverage(lax.planesLanded) << endl;
    cout << "The average monthly departures for the year is " << findAverage(lax.planesDeparted) << endl;
    cout << "The total landings for the year is " << findTotal(lax.planesLanded) << endl;
    cout << "The total departures for the year is " << findTotal(lax.planesDeparted) << endl;
    cout << largestDepartIndex << endl;
    cout << largestLandingIndex << endl;
    
    cout << "The greatest number of planes that landed in a single day is " << lax.planesLanded[largestLandingIndex] << " which occured in the month of " << months[largestLandingIndex] << endl;
    
    cout << "The greatest number of planes that departed in a single day is " << lax.planesDeparted[largestDepartIndex] << " which occured in the month of " << months[largestDepartIndex] << endl;
    
    cout << "The least number of planes that departed in a single day is " << findSmallest(lax.smallestNumLanded) << " which occured in the month of " << months[smallestNumLanded] << endl;
    
    
    return 0;
}
