//
// Created by hassa on 3/30/2025.
//

#include "Patient_Registry.h"

//Creates the patient Registry
Patient_Registry::Patient_Registry(string name, string age, string gender, string illness, string DN,
    string NN, string IN, string meds, string dt, string fua) {

    Name = name;
    Age = age;
    Gender = Gender;
    Illness = illness;
    DoctorName = DN;
    NurseName = NN;
    InsuranceName = IN;
    Medication = meds;
    DT = dt;
    FUA = fua;
}
