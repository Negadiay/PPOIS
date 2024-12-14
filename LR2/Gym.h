#pragma once
#include <string>
#include <vector>
#include "GymEquipment.h"

class Gym {
private:
    std::string name;                      
    size_t capacity;                       
    std::vector<GymEquipment> equipments;
    GymEquipment* equipment;

public:
    Gym(const std::string& name, size_t capacity);

    void addEquipment(const GymEquipment& equipment); 
    void listEquipments() const;                      
    bool isAvailable() const;                        
    void showInfo() const;                           
};
