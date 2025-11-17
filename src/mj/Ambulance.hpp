#include <string>

struct Ambulance {
  std::string id;
  std::string driverName;
  std::string status;  // "On-Duty", "On-Call", "Maintenance"
  
  Ambulance(std::string i = "", std::string driver = "", std::string s = "On-Duty"): id(i), driverName(driver), status(s) {}
};