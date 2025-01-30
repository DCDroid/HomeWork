#include <iostream>
#include <fstream>
#include <string>

class Address
{

private:
    std::string m_town{};
    std::string m_street{};
    uint32_t m_house_number{};
    uint32_t m_flat_number{};
public:
    void add_address(std::string town, std::string street, uint32_t house_number, uint32_t flat_number)
    {
        m_town = town;
        m_street = street;
        m_house_number = house_number;
        m_flat_number = flat_number;
    }
    std::string get_output_address()
    {
        std::string response{m_town + ", " + m_street + ", " +  std::to_string(m_house_number) + ", " + std::to_string(m_flat_number)};
        return response;       
    }
};

void sort(Address* addresses, int size)
{
    Address tmp_address;
    for(int i{}; i < size; i++)
    {
        for(int j{}; j < size - 1; j++) {
            if((int)(addresses[j].get_output_address()[1]) > (int)(addresses[j + 1].get_output_address()[1])) {
                tmp_address = addresses[j];
                addresses[j] = addresses[j + 1];
                addresses[j + 1] = tmp_address;
            }
        }
    }
}

int main()
{
    std::ifstream fin("in.txt");

	if (!fin.is_open()) {
		std::cout << "Open error" << std::endl;
		return 0;
	}

    std::string s;
    std::string tmp_town{};
    std::string tmp_street{};
    uint32_t tmp_house_number{};
    uint32_t tmp_flat_number{};

    
    fin >> s;
    uint32_t address_count = atoi(s.c_str());
    Address* address_array = new Address[address_count];

    uint32_t address_counter{}, addres_member_counter{};

	while (fin >> s) {
        addres_member_counter++;
        if(addres_member_counter == 1){
            tmp_town = s;
        }
        else if(addres_member_counter == 2){
            tmp_street = s;
        }
        else if(addres_member_counter == 3){
            tmp_house_number = atoi(s.c_str());
        }
        else if(addres_member_counter == 4) {
            tmp_flat_number = atoi(s.c_str());
            address_array[address_counter].add_address(tmp_town, tmp_street, tmp_house_number, tmp_flat_number);
            address_counter++;
            addres_member_counter = 0;
            if(address_counter > address_count) {
                delete[] address_array;
                fin.close();
                std::cout << "Count error" << std::endl;
                return 0;
            }
        }
        
	}

    fin.close();

    sort(address_array, address_count);

    std::ofstream fout("out.txt");
	if (!fout.is_open()) {
		std::cout << "Open error" << std::endl;
        delete[] address_array;
		return 0;
	}
    fout << std::to_string(address_count) << "\n";
    for(int i = 0; i < address_count; i++) {
        fout << address_array[i].get_output_address() << std::endl;
    }
    
    fout.close();
    delete[] address_array;

    return 0;
}