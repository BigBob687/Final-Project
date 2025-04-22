//
// Created by hassa on 3/30/2025.
//

#include "System.h"

#include <iostream>

System::System() {
    Patients = {};
}
// These wrap Schedule functionality
void System::makeAppointment(const string& description, int hours, int minutes) {
    schedule.makeAppointment(description, hours, minutes);
}

void System::followUpAppointment(const string& previousDescription, const string& followUpDescription, int days) {
    schedule.followUpAppointment(previousDescription, followUpDescription, days);
}

void System::displayAppointments() const {
    schedule.displayAppointments();
}
//Is the main Menu gives the user things to input
void System::mainMenu() {
    int choice;
    int days, hours;
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
            "7. Display ALL appoinments\n"
            "8. Exit\n"
            "(ENTER A NUMBER (1-8)"<< endl;
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
            case 4: {
                cout << "Enter the Patients name of whom wants to make an appointment: " << endl;
                cin >> name;
                for(int i = 0; i < Patients.size(); i++) {
                    if(Patients[i].Name == name) {
                        cout << "Schedule an appointment for this patient:" << endl;
                        cout << "Enter how many days from now: ";
                        cin >> days;
                        cout << "Enter how many hours from now: ";
                        cin >> hours;
                        string appointmentDesc = "Initial appointment for " + name;
                        schedule.makeAppointment(appointmentDesc, days, hours);
                        cin.ignore();
                    }
                    else {
                        cout << "This patient is not found" << endl;
                    }
                }
                break;
            }
            case 5:
                createFollowUp();
            break;
            case 6:
            break;
            case 7:
                displayAppointments();
            break;
            case 8:
                exit(0);
        }

    }
}

//Adds the Patient to Vector
void System::AddPatient() {
    cin.ignore();
    string name, age, gender, illness, doctor, nurse, insurance, medication, dt, fua;

    cout << "Enter Patient's Name: ";
    getline(cin, name);

    cout << "Enter Patient's Age: ";
    getline(cin, age);

    cout << "Enter Patient's Gender: ";
    getline(cin, gender);

    cout << "Enter Patient's Illness: ";
    getline(cin, illness);

    cout << "Enter Patient's Doctor: ";
    getline(cin, doctor);

    cout << "Enter Patient's Nurse: ";
    getline(cin, nurse);

    cout << "Enter Patient's Insurance: ";
    getline(cin, insurance);

    cout << "Enter Patient's Medication: ";
    getline(cin, medication);

    // Ask for appointment time
    int days, hours;
    cout << "Schedule an appointment for this patient:" << endl;
    cout << "Enter how many days from now: ";
    cin >> days;
    cout << "Enter how many hours from now: ";
    cin >> hours;
    cin.ignore(); // Clear input buffer

    string appointmentDesc = "Initial appointment for " + name;
    schedule.makeAppointment(appointmentDesc, days, hours);
    cout << "Patient has been successfully created\n"<<endl;

    // Store appointment info in DT and SA
    dt = "Scheduled in " + to_string(days) + " day(s) and " + to_string(hours) + " hour(s)";

    Patient_Registry patient(name, age, gender, illness, doctor, nurse, insurance, medication, dt, fua);
    patient.SA = appointmentDesc;

    Patients.push_back(patient);
}

//Displays Details for User
void System::DisplayDetails(string name) {
    string choice;
    int selection;
    bool found = false;

    cout << "Is there a certain detail you want to see? If so, enter it. If not, all details will display: (Yes, No)" << endl;
    cin >> choice;

    for (const auto& patient : Patients) {
        if (patient.Name == name) {
            found = true;

            if (choice == "Yes") {
                cout << "What detail would you like to see?\n"
                        "1 for Name\n"
                        "2 for Age\n"
                        "3 for Gender\n"
                        "4 for Illness\n"
                        "5 for Doctor\n"
                        "6 for Nurse\n"
                        "7 for Insurance\n"
                        "8 for Medication\n"
                        "9 for Scheduled Appointment\n"
                        "10 for Date and Time Info\n"
                        "11 for Follow Up Appointment\n" <<endl;
                cin >> selection;

                switch (selection) {
                    case 1: cout << patient.Name << endl; break;
                    case 2: cout << patient.Age << endl; break;
                    case 3: cout << patient.Gender << endl; break;
                    case 4: cout << patient.Illness << endl; break;
                    case 5: cout << patient.DoctorName << endl; break;
                    case 6: cout << patient.NurseName << endl; break;
                    case 7: cout << patient.InsuranceName << endl; break;
                    case 8: cout << patient.Medication << endl; break;
                    case 9: cout << "Scheduled Appointment: " << patient.SA << endl; break;
                    case 10: cout << "Date & Time Info: " << patient.DT << endl; break;
                    case 11: cout << "Follow up appointment: " << patient.FUA << endl; break;
                    default: cout << "Invalid selection.\n"; break;
                }
            } else {
                cout << "Patient Details:\n";
                cout << "Name: " << patient.Name << endl;
                cout << "Age: " << patient.Age << endl;
                cout << "Gender: " << patient.Gender << endl;
                cout << "Illness: " << patient.Illness << endl;
                cout << "Doctor: " << patient.DoctorName << endl;
                cout << "Nurse: " << patient.NurseName << endl;
                cout << "Insurance: " << patient.InsuranceName << endl;
                cout << "Medication: " << patient.Medication << endl;
                cout << "Appointment Info: " << patient.DT << endl;
                cout << "Scheduled Appointment: " << patient.SA << endl;
                cout << "Date & Time Info: " << patient.DT << endl;
                cout << "Follow Up Appointment: " << patient.FUA << endl;break;
            }

            break;
        }
    }

    if (!found) {
        cout << "Patient not found.\n";
    }
}
void System::createFollowUp() {
    cin.ignore();
    string patientName;
    cout << "Enter the patient's name for the follow-up appointment: ";
    getline(cin, patientName);

    string previousDescription;
    cout << "Enter the description of the previous appointment: ";
    getline(cin, previousDescription);

    string followUpDescription;
    cout << "Enter the description for the follow-up appointment: ";
    getline(cin, followUpDescription);

    int days;
    cout << "Enter how many days from the previous appointment the follow-up should be scheduled: ";
    cin >> days;

    // Call Schedule class method
    schedule.followUpAppointment(previousDescription, followUpDescription, days);

    // Optional: Store follow-up info in patient registry
    for (auto& patient : Patients) {
        if (patient.Name == patientName) {
            patient.FUA = followUpDescription;
            cout << "Follow-up scheduled and recorded.\n";
            return;
        }
    }

    cout << "Patient not found, follow-up was still scheduled globally.\n";
}
