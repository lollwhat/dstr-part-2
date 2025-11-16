#include "../../Header/models/Patient.hpp"

Patient::Patient() {
    patientID = "";
    name = "";
    condition = "";
    admissionTime = "";
}

Patient::Patient(const std::string& id, const std::string& n, 
                 const std::string& c, const std::string& time) {
    patientID = id;
    name = n;
    condition = c;
    admissionTime = time;
}

