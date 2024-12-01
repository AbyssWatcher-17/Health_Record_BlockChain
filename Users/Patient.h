#ifndef PATIENT_INCLUDED
#define PATIENT_INCLUDED

#pragma once

#include "../Base/User.h"
#include "../Users/Doctor.h"

class Doctor; // Forward declaration of Doctor

class Patient : public User {
private:
    std::vector<std::shared_ptr<Doctor>> treatingDoctors;

public:
    Patient(const std::string& patientId, const std::string& patientName);
    void addTreatingDoctor(std::shared_ptr<Doctor> doctor);
    void broadcastRecord(const Record& record) override;
};

#endif