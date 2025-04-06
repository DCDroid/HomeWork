#include "Racing.h"

void Racing::add_vehicle_air(vehicle_type vehicle) {
    switch (vehicle)
    {
    case broom:
        // std::cout << "| " << available_vehicle[broom - 1] << " |" << std::endl; 
        if(available_vehicle[broom - 1] == false) {
            this->vehicleList.push_back(Broom());
            this->available_vehicle[broom - 1] = true;
            this->racers_count++;
        }
        else 
        {
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        }
        break;
    case eagle:
        if(available_vehicle[eagle - 1] == false) {
            this->vehicleList.push_back(Eagle());
            this->available_vehicle[eagle - 1] = true;
            this->racers_count++;
        }
        else 
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        break;
    case airplaneCarpet:
        if(available_vehicle[airplaneCarpet - 1] == false) {
            this->vehicleList.push_back(AirplaneCarpet());
            this->available_vehicle[airplaneCarpet - 1] = true;
            this->racers_count++;
        }
        else 
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        break;
    default:
        throw std::string("Attempt to register the wrong vehicle type");
        break;
    }
}

void Racing::add_vehicle_ground(vehicle_type vehicle) {
    switch (vehicle)
    {
    case camel:
        // vehicleList.push_back();
        break;
    case fastCamel:
        // vehicleList.push_back();
        break;
    case centaur:
        // vehicleList.push_back();
        break;
    case offRoadBoots:
        // vehicleList.push_back();
    break;
    
    default:
        throw std::string("Attempt to register the wrong vehicle type");
        break;
    }
}

void Racing::add_vehicle_general(vehicle_type vehicle) {
    switch (vehicle)
    {
    case broom:
        // vehicleList.push_back();
        break;
    case eagle:
        // vehicleList.push_back();
        break;
    case airplaneCarpet:
        // vehicleList.push_back();
        break;
        case camel:
        // vehicleList.push_back();
        break;
    case fastCamel:
        // vehicleList.push_back();
        break;
    case centaur:
        // vehicleList.push_back();
        break;
    case offRoadBoots:
        // vehicleList.push_back();
    break;
    
    default:
        throw std::string("Attempt to register the wrong vehicle type");
        break;
    }
}

void Racing::add_vehicle(vehicle_type vehicle) {
    switch (m_race_type)
    {
        case air:
            add_vehicle_air(vehicle);
        break;
        default:
            throw std::string("Attempt to register the wrong vehicle type");
        break;
    }
    
}

void Racing::set_air_type() {
    m_race_type = air;
}

void Racing::set_ground_type() {
    m_race_type = ground;
}

void Racing::set_general_type() {
    m_race_type = general;
}

void Racing::set_length(int length)
{
    this->lenght = lenght;
}

bool Racing::is_ready() {
    if(racers_count > 1) this->ready = true;
    return this->ready;
}

void Racing::start_race()
{
    for(auto i : vehicleList) {
        std::cout << i.get_time(lenght) << std::endl;
    }
}
