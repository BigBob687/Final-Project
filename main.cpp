#include <iostream>
#include "Schedule.h"

int main() {
    Schedule mySchedule;

    // Create appointments

    mySchedule.makeAppointment("Doctor's Appointment", 2, 30);
    mySchedule.makeAppointment("Meeting with Client", 5, 0);
    mySchedule.makeAppointment("Dinner with Family", 8, 15);

    // Display current appointments
    mySchedule.displayAppointments();

    // Schedule a follow-up appointment
    mySchedule.followUpAppointment("Doctor's Appointment", "Follow-up Checkup", 7);

    // Display updated appointments
    mySchedule.displayAppointments();

    return 0;
}