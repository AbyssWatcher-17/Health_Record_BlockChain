#include <string>
#include "Record.h"



Record::Record(const std::string& pId, const std::string& dId, 
           RecordType recType, const std::string& recordDetails)
        : patientId(pId), doctorId(dId), type(recType), 
          details(recordDetails), timestamp(time(nullptr)) {}

    std::string Record::toString() const {
        std::string typeStr;
        switch(type) {
            case RecordType::DIAGNOSIS: typeStr = "DIAGNOSIS"; break;
            case RecordType::PRESCRIPTION: typeStr = "PRESCRIPTION"; break;
            case RecordType::TREATMENT: typeStr = "TREATMENT"; break;
            case RecordType::CONSULTATION: typeStr = "CONSULTATION"; break;
        }

        return "Patient: " + patientId + 
               ", Doctor: " + doctorId + 
               ", Type: " + typeStr + 
               ", Details: " + details;
    }