//
// Created by hassa on 4/28/2025.
//

#include "DataBase.h"
#include "Patient_Registry.h"
#include "System.h"
using namespace std;

/**
 * A function to output all the patients in the Patient_Registry class
 * @param system
 */
void DataBase::callAllPatients(System& system) {

//Prints out the patients Vector to see all the patients inside of it
    for(auto & Patient : system.Patients) {
        cout << "Patient Details:\n";
        cout << "Name: " << Patient.Name << endl;
        cout << "Age: " << Patient.Age << endl;
        cout << "Gender: " << Patient.Gender << endl;
        cout << "Illness: " << Patient.Illness << endl;
        cout << "Doctor: " <<Patient.DoctorName << endl;
        cout << "Nurse: " << Patient.NurseName << endl;
        cout << "Insurance: " << Patient.InsuranceName << endl;
        cout << "Medication: " << Patient.Medication << endl;
        cout << "Appointment Info: " << Patient.DT << endl;
        cout << "Scheduled Appointment: " << Patient.SA << endl;
        cout << "Date & Time Info: " << Patient.DT << endl;
        cout << "Follow Up Appointment: " << Patient.FUA << endl;
        cout << endl;
        cout << endl;
    }
}
