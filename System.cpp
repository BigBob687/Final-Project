//
// Created by hassa on 3/30/2025.
//

#include "System.h"

#include <iostream>


System::System() {
    Patients = {};
}

//Is the main Menu gives the user things to input
void System::mainMenu() {
    int choice;
    string name;
    string temp;
    //while loop for the menu
    while (true) {
        cout << "Welcome to the Medical System, Follow the prompts...\n"
            "1. Add a Patient\n"
            "2. Display a Patient\n"
            "3. Check Patients Insurance\n"
            "4. Schedule a Appointment with Patient\n"
            "5. Create a Follow Up with a Patient\n"
            "6. Display ALL Patients\n"
            "(ENTER A NUMBER (1-6)"<< endl;
        cin >> choice;
        switch (choice) {
            case 1:
                //if input call AddPatient
                AddPatient();
                break;
            case 2:
                //If input call Display Details
                cout << "Enter the name of the patient you wish to see the details of: " << endl;
                cin >> name;
                DisplayDetails(name);
                break;
            case 3:
                //If input call Insurance
                cout << "Enter the Patients name whose insurance you want to see: " << endl;
                cin >> name;
                //Calling this makes it go infinetly for some reason FIX IT
                for(int i = 0; i < Patients.size(); i++) {
                    if(Patients[i].Name == name) {
                         cout << Patients[i].InsuranceName << endl;
                    }
                    else {
                        cout << "This patient is not found" << endl;
                    }
                }
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }

    }
}

//Adds the Patient to Vector
void System::AddPatient() {
    cin.ignore();
    string name;
    cout << "Enter Patients Name: " << endl;
    getline(cin,name);

    string age;
    cout << "Enter Patients Age: " << endl;
    getline(cin,age);

    string gender;
    cout << "Enter Patients Gender: " << endl;
    getline(cin, gender);

    string Ill;
    cout << "Enter Patients Illness: " << endl;
    getline(cin, Ill);

    string Doc;
    cout << "Enter Patients Doctor: " << endl;
    getline(cin, Doc);

    string nurse;
    cout << "Enter Patients Nurse: " << endl;
    getline(cin, nurse);

    string Inscu;
    cout << "Enter Patients Insurance: " << endl;
    getline(cin, Inscu);

    string Med;
    cout << "Enter Patients Medication: " << endl;
    getline(cin, Med);

    string Dt;
    cout << "Enter Date and Time of Appointment: " << endl;
    getline(cin, Dt);

    // Type Variable = definition
    //Patient Registry is connected to the System collection
    Patient_Registry Patient = Patient_Registry(name, age, gender, Ill, Doc, nurse,
        Inscu, Med, Dt);

    //Puts the book in the collection
    Patients.push_back(Patient);
}

//Displays Details for User
void System::DisplayDetails(string name) {
    string choice;
    int selection;
    cout << "Is there a certain detail you want to see? If so Enter it, If not it will display all details: (Yes, No)" << endl;
    cin >> choice;
    if (choice == "Yes") {
        cout << "What detail would you like to see?\n"
                "1 for Name\n"
                "2 for Age\n"
                "3 for Gender\n"
                "4 for Illness\n"
                "5 for Doctor\n"
                "6 for Nurse\n"
                "7 for Insurance\n"
                "8 for Medication\n" << endl;
        cin >> selection;

        //gets details depending on user input
        for(int i = 0; i < Patients.size(); i++) {
            switch (selection) {
                case 1:
                    cout << Patients[i].Name << endl;
                break;
                case 2:
                    cout << Patients[i].Age << endl;
                break;
                case 3:
                    cout << Patients[i].Gender << endl;
                break;
                case 4:
                    cout << Patients[i].Illness << endl;
                break;
                case 5:
                    cout << Patients[i].DoctorName << endl;
                break;
                case 6:
                    cout << Patients[i].NurseName << endl;
                break;
                case 7:
                    cout << Patients[i].InsuranceName << endl;
                break;
                case 8:
                    cout << Patients[i].Medication << endl;
                break;
            }
        }
    }

    //Displays all details all else
    else {
        for(int i = 0; i < Patients.size();i++) {

            cout << "Patients Name: " << Patients[i].Name << endl;
            cout << "Patients Age: " << Patients[i].Age << endl;
            cout << "Patients Gender:" << Patients[i].Gender << endl;
            cout << "Patients Illness: " << Patients[i].Illness << endl;
            cout << "Patients Doctor: " << Patients[i].DoctorName << endl;
            cout << "Patients Nurse: " << Patients[i].NurseName << endl;
            cout << "Patients Insurance " << Patients[i].InsuranceName << endl;
            cout << "Patients Medication: " << Patients[i].Medication << endl;
            cout << "Patients Time in and Date: " << Patients[i].DT << endl;
            cout << endl;
        }
    }
}

