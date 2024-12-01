#ifndef RECORD_INCLUDED
#define RECORD_INCLUDED

#include <chrono>
#include <string>
#include <iostream>
#include <thread>

class Record {
public:
    enum class RecordType {
        DIAGNOSIS,
        PRESCRIPTION,
        TREATMENT,
        CONSULTATION
    };

private:
    std::string patientId;
    std::string doctorId;
    RecordType type;
    std::string details;
    time_t timestamp;

public:
    Record(const std::string& pId, const std::string& dId, 
           RecordType recType, const std::string& recordDetails);

    std::string toString() const;
};


#endif