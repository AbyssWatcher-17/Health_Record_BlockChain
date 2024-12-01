#include "../Users/Patient.h"




Patient::Patient(const std::string& patientId, const std::string& patientName) 
        : User(patientId, patientName) {}

void Patient::addTreatingDoctor(std::shared_ptr<Doctor> doctor) {
    treatingDoctors.push_back(doctor);
}

void Patient::broadcastRecord(const Record& record) {
    // Add record to personal blockchain
    personalBlockchain->addBlock(record.toString());

    // Broadcast to treating doctors
    for (auto& doctor : treatingDoctors) {
        doctor->receiveUpdate(personalBlockchain->getChain());
    }
}