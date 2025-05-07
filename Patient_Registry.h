//
// Created by hassa on 3/30/2025.
//

#ifndef PATIENT_REGISTRY_H
#define PATIENT_REGISTRY_H
#include <string>

using namespace std;

class Patient_Registry {
    public:
    string Name;
    string Age;
    string Gender;
    string Illness;
    string DoctorName;
    string NurseName;
    string InsuranceName;
    string Medication;
    //Date/Time of appointment
    string DT;
    //Scheduling Appointment
    string SA;
    //Follow Up Appointemnt
    string FUA;

    //Creating the Registry Constructor
    /**
     * 
     * @param name 
     * @param age 
     * @param gender 
     * @param illness 
     * @param DN 
     * @param NN 
     * @param IN 
     * @param meds 
     * @param dt 
     * @param fua 
     */
    Patient_Registry(string name, string age, string gender, string illness, string DN,
                     string NN, string IN, string meds, string dt, string fua);
};





#endif //PATIENT_REGISTRY_H
