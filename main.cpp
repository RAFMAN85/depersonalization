#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>
#include "sha256.h"

int main() {

    std::string filename_input="C:/Users/Asus/Desktop/athlete_events.csv";
    std::ifstream work_file(filename_input);
    std::string line;
    char delimiter=',';
    getline(work_file,line);
    while(getline(work_file,line)){

        std::stringstream st(line);
        std::string id_pers, name_pers, sex_pers,age_pers, height_pers, weights_pers, country_pers, city_pers;
        getline(st,id_pers,delimiter);
        getline(st,name_pers,delimiter);
        getline(st,sex_pers,delimiter);
        getline(st,age_pers,delimiter);
        getline(st,height_pers,delimiter);
        getline(st,weights_pers,delimiter);
        getline(st, country_pers,delimiter);
        getline(st,city_pers,delimiter);
        std::cout<<"country: "<<sha256(country_pers)<<std::endl;

    }
    work_file.close();


    return 0;
}
