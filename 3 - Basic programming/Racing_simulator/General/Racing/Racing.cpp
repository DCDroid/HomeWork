#include "Racing.h"

void Racing::add_vehicle_air(vehicle_type vehicle) {
    switch (vehicle)
    {
    case broom:
        if(available_vehicle[broom - 1] == false) {
            this->vehicleList.push_back(new Broom());
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
            this->vehicleList.push_back(new Eagle());
            this->available_vehicle[eagle - 1] = true;
            this->racers_count++;
        }
        else 
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        break;
    case airplaneCarpet:
        if(available_vehicle[airplaneCarpet - 1] == false) {
            this->vehicleList.push_back(new AirplaneCarpet());
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
        if(available_vehicle[camel - 1] == false) {
            this->vehicleList.push_back(new Camel());
            this->available_vehicle[camel - 1] = true;
            this->racers_count++;
        }
        else 
        {
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        }
        break;
    case fastCamel:
        if(available_vehicle[fastCamel - 1] == false) {
            this->vehicleList.push_back(new FastCamel());
            this->available_vehicle[fastCamel - 1] = true;
            this->racers_count++;
        }
        else 
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");   
        break;
    case centaur:
        if(available_vehicle[centaur - 1] == false) {
            this->vehicleList.push_back(new Centau());
            this->available_vehicle[centaur - 1] = true;
            this->racers_count++;
        }
        else 
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        break;
    case offRoadBoots:
        if(available_vehicle[offRoadBoots - 1] == false) {
            this->vehicleList.push_back(new OffRoadBoots());
            this->available_vehicle[offRoadBoots - 1] = true;
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

void Racing::add_vehicle_general(vehicle_type vehicle) {
    switch (vehicle)
    {
    case broom:
        if(available_vehicle[broom - 1] == false) {
            this->vehicleList.push_back(new Broom());
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
            this->vehicleList.push_back(new Eagle());
            this->available_vehicle[eagle - 1] = true;
            this->racers_count++;
        }
        else 
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        break;
    case airplaneCarpet:
        if(available_vehicle[airplaneCarpet - 1] == false) {
            this->vehicleList.push_back(new AirplaneCarpet());
            this->available_vehicle[airplaneCarpet - 1] = true;
            this->racers_count++;
        }
        else 
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        break;
        case camel:
        if(available_vehicle[camel - 1] == false) {
            this->vehicleList.push_back(new Camel());
            this->available_vehicle[camel - 1] = true;
            this->racers_count++;
        }
        else 
        {
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        }
        break;
    case fastCamel:
        if(available_vehicle[fastCamel - 1] == false) {
            this->vehicleList.push_back(new FastCamel());
            this->available_vehicle[fastCamel - 1] = true;
            this->racers_count++;
        }
        else 
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        break;
    case centaur:
        if(available_vehicle[centaur - 1] == false) {
            this->vehicleList.push_back(new Centau());
            this->available_vehicle[centaur - 1] = true;
            this->racers_count++;
        }
        else 
            throw std::string("Attempt to register the wrong vehicle type. To many this type vehicle\n");
        break;
    case offRoadBoots:
        if(available_vehicle[offRoadBoots - 1] == false) {
            this->vehicleList.push_back(new OffRoadBoots());
            this->available_vehicle[offRoadBoots - 1] = true;
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

void Racing::add_vehicle(vehicle_type vehicle) {
    switch (m_race_type)
    {
        case air:
            add_vehicle_air(vehicle);
        break;
        case ground:
            add_vehicle_ground(vehicle);
        break;
        case general:
            add_vehicle_general(vehicle);
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
    
    this->length = length;
    std::cout << "Length: " << this->length << std::endl;
}

bool Racing::is_ready() {
    if(racers_count > 1) this->ready = true;
    return this->ready;
}

void Racing::start_race()
{
    for(auto i : vehicleList) {
        i->calculate_time(this->length);
    }

    vehicleList.sort([](Vehicle* a, Vehicle* b) { // как это работает? нагуглил 
        return a->get_time() > b->get_time();
    });
}

race_type Racing::get_type()
{
    return m_race_type;
}

int Racing::get_distance()
{
    return this->length;
}

std::list<Vehicle> Racing::get_vehicle_list()
{
    std::list<Vehicle> result;
    for (auto vehicle : this->vehicleList) {
        result.push_back(*vehicle);
    }
    return result;
}

Racing::~Racing()
{
    for (Vehicle* vehicle : vehicleList) {
        delete vehicle;
    }
    vehicleList.clear();
}
