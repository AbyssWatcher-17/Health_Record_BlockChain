#include "../Users/Doctor.h"

    Doctor::Doctor(const std::string& doctorId, const std::string& doctorName) 
            : User(doctorId, doctorName) {}

    

    void Doctor::addTreatedPatient(std::shared_ptr<Patient> patient) {
        treatedPatients.push_back(patient);
        patient->addTreatingDoctor(std::dynamic_pointer_cast<Doctor>(shared_from_this()));
    }

    void Doctor::broadcastRecord(const Record& record){
        // Add record to personal blockchain
        personalBlockchain->addBlock(record.toString());

        // Broadcast to treating patients and peers (other doctors)
        for (auto& patient : treatedPatients) {
            patient->receiveUpdate(personalBlockchain->getChain());
        }
        
        for (auto& peer : peers) {
            peer->receiveUpdate(personalBlockchain->getChain());
        }
    }

    void Doctor::viewPatientHistory(std::shared_ptr<Patient> patient) {
        std::cout << "Patient History for " << patient->getName() << ":" << std::endl;
        patient->printBlockchain();
    }