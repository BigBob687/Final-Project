//
// Created by hassa on 3/30/2025.
//

#ifndef SYSTEM_H
#define SYSTEM_H
#include "Patient_Registry.h"
#include <vector>
using namespace std;

class System {
    public:
    System();

    ~System() = default;

    //create Vector capable of holding all the data of the patients
    vector<Patient_Registry> Patients;

    //methods
    void mainMenu();
    void DisplayDetails(string name);
    void AddPatient();
    void DeletePatient();
};


#endif //SYSTEM_H
