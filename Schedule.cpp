//
// Created by mjhut on 3/30/2025.
//
#include "Schedule.h"

// Constructor

Schedule::Schedule() {}

// Make an appointment
/**
 *
 * @param description
 * @param days
 * @param hours
 */
void Schedule::makeAppointment(const string& description, int days, int hours) {
    auto now = chrono::system_clock::now();
    auto appointmentTime = now + chrono::days(days) + chrono::hours(hours);
    appointments.push_back({description, appointmentTime});
}

// Follow up on an existing appointment
/**
 *
 * @param previousDescription
 * @param followUpDescription
 * @param days
 */
void Schedule::followUpAppointment(const string& previousDescription, const string& followUpDescription, int days) {
    for (const auto& appointment : appointments) {
        if (appointment.description == previousDescription) {
            auto followUpTime = appointment.time + chrono::hours(days * 24);
            appointments.push_back({followUpDescription, followUpTime});
            return;
        }
    }
    cout << "Previous appointment not found for follow-up." << endl;
}

// Display all appointments

void Schedule::displayAppointments() const {
    cout << "Scheduled Appointments:" << endl;
    for (const auto& appointment : appointments) {
        time_t appointmentTime = chrono::system_clock::to_time_t(appointment.time);
        cout << "- " << appointment.description << " at " << ctime(&appointmentTime);
    }
}

// Check if an appointment is scheduled at a given time
/**
 *
 * @param time
 * @return bool
 */
bool Schedule::isAppointmentScheduled(const chrono::system_clock::time_point& time) const {
    for (const auto& appointment : appointments) {
        if (chrono::duration_cast<chrono::minutes>(appointment.time - time).count() == 0) {
            return true;
        }
    }
    return false;
}
