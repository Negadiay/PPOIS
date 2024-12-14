#pragma once
#include <string>
#include <vector>
#include <iostream>

class Diet {
private:
    std::string name;          
    std::vector<std::string> foods; 
    std::string recommendations;    

public:
    Diet(const std::string& name, const std::vector<std::string>& foods, const std::string& recommendations);
    void createDiet();           
    void modifyRecommendations(); 
    void showInfo() const;       
};

