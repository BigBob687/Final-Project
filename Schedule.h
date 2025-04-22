#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <chrono>
#include <vector>
#include <string>
using namespace std;
struct Appointment {
    string description;
    chrono::system_clock::time_point time;
};

class Schedule {
public:
    // Constructor
    Schedule();

    // Make an appointment with a description and scheduled time (in hours and minutes from now)
    /**
     *
     * @param description
     * @param hours
     * @param days
     */
    void makeAppointment(const string& description, int days, int hours);

    // Follow up on an existing appointment by scheduling a follow-up after a given duration
    /**
     *
     * @param previousDescription
     * @param followUpDescription
     * @param days
     */
    void followUpAppointment(const string& previousDescription, const std::string& followUpDescription, int days);

    // Display all scheduled appointments
    void displayAppointments() const;

    // Check if an appointment is scheduled at a given time
    /**
     *
     * @param time
     * @return bool
     */
    bool isAppointmentScheduled(const chrono::system_clock::time_point& time) const;

private:
    vector<Appointment> appointments;
};

#endif // SCHEDULE_H