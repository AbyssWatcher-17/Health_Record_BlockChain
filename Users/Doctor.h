#ifndef DOCTOR_INCLUDED
#define DOCTOR_INCLUDED

#pragma once

#include "../Base/User.h"
#include "../Base/BlockChain.h"
#include "../Users/Patient.h"

class Patient; // Forward declaration of Patient

class Doctor : public User {
private:
    std::vector<std::shared_ptr<Patient>> treatedPatients;

public:

    Doctor(const std::string& doctorId, const std::string& doctorName);

    void addTreatedPatient(std::shared_ptr<Patient> patient);
    
    //void saveRecord(const Record* record);
    void broadcastRecord(const Record& record) override;
    void viewPatientHistory(std::shared_ptr<Patient> patient);


};




#endif