//
//  main.cpp
//  week5
//
//  Created by Jordon Marchesano on 11/13/24.
//

#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
using namespace std;


const int MONTHS = 12;
string months[MONTHS] = {
    "January", "February", "March", "April","May", "June",
        "July", "August", "September", "October", "November", "December"
    };
struct Airport  {
    int planesLanded;
    int planesDeparted;
    int greatestLanded;
    int leastLanded;
  
};

Airport lax[MONTHS];
void promptFunc();
int findSmallest(int[]);
int findLargest(int[]);
int findTotal(int[]);
float findAverage(int[]);
void promptFunc (Airport lax[]){
    string planesDepartedPrompt = "Please enter the number of planes that departed in ";
    string planesLandedPrompt = "Please enter the number of planes that landed in ";
    string leastLanded = "Please enter the least number of planes that landed in a single day in ";
    string greatestLanded = "Please enter the greatest number of planes that landed in a single day in ";


    for (int j = 0; j < MONTHS; j ++){

        cout << planesLandedPrompt << months[j] << ": ";
        cin >> lax[j].planesLanded;
        cout << planesDepartedPrompt << months[j] << ": " ;
        cin >> lax[j].planesDeparted;
        cout << greatestLanded << months[j] << ": " ;
        cin >> lax[j].greatestLanded;
        cout << leastLanded << months[j] << ": " ;
        cin >> lax[j].leastLanded;
    }
    
}

int findSmallest(Airport lax[], string type) {
    int temp = 0;
    int index = 0;

    if (type == "planesLanded") {
        temp = lax[0].planesLanded;
        for (int i = 0; i < MONTHS; i++) {
            if (lax[i].planesLanded == 0) {
                return i;
            } else if (lax[i].planesLanded < temp) {
                temp = lax[i].planesLanded;
                index = i;
            }
        }
    } else if (type == "planesDeparted") {
        temp = lax[0].planesDeparted;
        for (int i = 0; i < MONTHS; i++) {
            if (lax[i].planesDeparted == 0) {
                return i;
            } else if (lax[i].planesDeparted < temp) {
                temp = lax[i].planesDeparted;
                index = i;
            }
        }
    } else if (type == "leastLanded") {
        temp = lax[0].leastLanded;
        for (int i = 0; i < MONTHS; i++) {
            if (lax[i].leastLanded == 0) {
                return i;
            } else if (lax[i].leastLanded < temp) {
                temp = lax[i].leastLanded;
                index = i;
            }
        }
    } else if (type == "greatestLanded") {
        temp = lax[0].greatestLanded;
        for (int i = 0; i < MONTHS; i++) {
            if (lax[i].greatestLanded == 0) {
                return i;
            } else if (lax[i].greatestLanded < temp) {
                temp = lax[i].greatestLanded;
                index = i;
            }
        }
    }

    return index;
}


int findLargest(Airport lax[], string type) {
    int temp = 0, index = 0;

    if (type == "planesLanded") {
        temp = lax[0].planesLanded;
        for (int i = 0; i < MONTHS; i++) {
            if (lax[i].planesLanded > temp) {
                temp = lax[i].planesLanded;
                index = i;
            }
        }
    } else if (type == "planesDeparted") {
        temp = lax[0].planesDeparted;
        for (int i = 0; i < MONTHS; i++) {
            if (lax[i].planesDeparted > temp) {
                temp = lax[i].planesDeparted;
                index = i;
            }
        }
    } else if (type == "leastLanded") {
        temp = lax[0].leastLanded;
        for (int i = 0; i < MONTHS; i++) {
            if (lax[i].leastLanded > temp) {
                temp = lax[i].leastLanded;
                index = i;
            }
        }
    } else if (type == "greatestLanded") {
        temp = lax[0].greatestLanded;
        for (int i = 0; i < MONTHS; i++) {
            if (lax[i].greatestLanded > temp) {
                temp = lax[i].greatestLanded;
                index = i;
            }
        }
    }
    return index;
}



int findTotal(Airport lax[], string type){
    int total = 0;
    if (type == "planesDeparted") {
        
        for (int i = 0; i < MONTHS; i++){
            total += lax[i].planesDeparted;
        }
    }
    else if (type == "planesLanded"){
        for (int i = 0; i < MONTHS; i++){
            total += lax[i].planesLanded;
        }
    }
    return total;
}

float findAverage(Airport lax[], string type){
    int total = 0;
    if (type == "planesDeparted") {
        
        for (int i = 0; i < MONTHS; i++){
            total += lax[i].planesDeparted;
        }
    }
    else if (type == "planesLanded"){
        for (int i = 0; i < MONTHS; i++){
            total += lax[i].planesLanded;
        }
    }
    return total / 12;

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
    int largestLandingIndex = findLargest(lax, "greatestLanded");
    int smallestLandingIndex = findSmallest(lax, "leastLanded");
    cout << "The average monthly landings for the year is " << fixed << setprecision(2) << findAverage(lax, "planesLanded") << endl;
    cout << "The average monthly departures for the year is " << fixed << setprecision(2) << findAverage(lax, "planesDeparted") << endl;
    cout << "The total landings for the year is " << findTotal(lax, "planesLanded") << endl;
    cout << "The total departures for the year is " << findTotal(lax, "planesDeparted") << endl;
    cout << "The greatest number of planes that landed in a single day is " << lax[largestLandingIndex].greatestLanded<< " which occured in the month of " << months[largestLandingIndex] << endl;
    cout << "The least number of planes that departed in a single day is " << lax[smallestLandingIndex].leastLanded << " which occured in the month of " << months[smallestLandingIndex] << endl;
    cin.ignore();
    cin.get();

    return 0;
}
