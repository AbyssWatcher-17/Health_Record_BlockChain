#include "Base/Block.h"
#include "Base/BlockChain.h"
#include "Base/User.h"

#include "Users/Doctor.h"
#include "Users/Patient.h"


int main() {
    auto dct1 = std::make_shared<Doctor>("DCT001", "Dr. Smith");
    auto dct2 = std::make_shared<Doctor>("DCT002", "Dr. Johnson");

    dct1->addPeer(dct2);
    dct2->addPeer(dct1);

    auto pt1 = std::make_shared<Patient>("PT001", "Alice");
    auto pt2 = std::make_shared<Patient>("PT002", "Bob");
    auto pt3 = std::make_shared<Patient>("PT003", "Charlie");

    // Establish doctor-patient relationships
    dct1->addTreatedPatient(pt1);
    dct1->addTreatedPatient(pt2);
    dct2->addTreatedPatient(pt2);
    dct2->addTreatedPatient(pt3);

    // Relationship between pt1 and pt3
    // They are not directly connected, but they're part of the same blockchain network through their doctors

    Record rec1(pt1->getId(), dct1->getId(), Record::RecordType::DIAGNOSIS, "Annual Checkup");
    Record rec2(pt2->getId(), dct1->getId(), Record::RecordType::PRESCRIPTION, "Blood Pressure Medication");
    Record rec3(pt3->getId(), dct2->getId(), Record::RecordType::TREATMENT, "Flu Vaccination");

    // Broadcast records
    pt1->broadcastRecord(rec1);
    pt2->broadcastRecord(rec2);
    pt3->broadcastRecord(rec3);

    // Demonstrate record sharing
    std::cout << "\n" << dct1->getName() <<" viewing " <<pt2->getName() <<"'s history:" << std::endl;
    dct1->viewPatientHistory(pt2);

    std::cout << "\n" << dct2->getName() <<" viewing " <<pt2->getName() <<"'s history:" << std::endl;
    dct2->viewPatientHistory(pt2);

    std::cout << "\n" << dct2->getName() <<" viewing " <<pt1->getName() <<"'s history:" << std::endl;
    dct2->viewPatientHistory(pt1);

    // Validation
    if (dct1->validateBlockchain()) {
        std::cout << "Dr. Smith's blockchain is valid." << std::endl;
    } else {
        std::cout << "Dr. Smith's blockchain has been tampered with!" << std::endl;
    }


    return 0;
}