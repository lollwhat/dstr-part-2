#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

struct Patient {
    std::string patientID;      // Unique patient identifier
    std::string name;           // Patient's full name
    std::string condition;      // Medical condition/reason for admission
    std::string admissionTime;  // Time of admission (formatted string)
    
    // Constructors
    Patient();
    Patient(const std::string& id, const std::string& n, 
            const std::string& c, const std::string& time);
};

#endif

