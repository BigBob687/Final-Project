//
// Created by hassa on 3/30/2025.
//
#ifndef SYSTEM_H
#define SYSTEM_H

#include "Patient_Registry.h"
#include "Schedule.h"
#include <vector>
using namespace std;

class System {
public:
    System();
    ~System() = default;

    vector<Patient_Registry> Patients;

    // Expose Schedule functionality to main
    /**
     * A function to make appointments through the system
     * @param description
     * @param hours
     * @param minutes
     */
    void makeAppointment(const string& description, int hours, int minutes);

    /**
     * A function to make follow-up appointments through the system
     * @param previousDescription
     * @param followUpDescription
     * @param days
     */
    void followUpAppointment(const string& previousDescription, const string& followUpDescription, int days);

    void displayAppointments() const;

    void mainMenu();             // Already handles user interaction
    void DisplayDetails(string);
    void AddPatient();
    void DeletePatient();        // Optional
    void createFollowUp();

private:
    Schedule schedule;  //  Integration of Schedule
};

#endif // SYSTEM_H