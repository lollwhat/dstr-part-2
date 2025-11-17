#pragma once

#include <string>

struct MedicalSupply {
    std::string id;
    std::string name;
    std::string type;
    int quantity; // Use int for quantity!
    std::string batch;
};