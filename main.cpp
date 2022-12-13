#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>
#include "hashing.h"



int main() {

    std::string filename_input="C:/Users/Asus/Desktop/athlete_events.csv";
    std::string filename_output="C:/Users/Asus/Desktop/test.csv";
    std::ifstream work_file(filename_input);
    std::string line;

    std::ofstream file_out;
    file_out.open(filename_output);

    char delimiter=',';
    getline(work_file,line);
    int counter=0;
    while(getline(work_file,line)){
        counter++;
        std::stringstream st(line);
        std::string id_pers, name_pers, sex_pers,age_pers, height_pers, weights_pers, country_pers, city_pers;
        /*now we read it*/
        getline(st,id_pers,delimiter);
        getline(st,name_pers,delimiter);
        getline(st,sex_pers,delimiter);
        getline(st,age_pers,delimiter);
        getline(st,height_pers,delimiter);
        getline(st,weights_pers,delimiter);
        getline(st, country_pers,delimiter);
        getline(st,city_pers,delimiter);

        /* now we write it*/
        file_out<<id_pers<<";"<<name_pers<<";"<<sex_pers<<";"<<age_pers<<";"<<height_pers<<";"<<weights_pers<<";"<<sha256(country_pers)<<";"<<city_pers<<std::endl;
    }
    work_file.close();
    file_out.close();


    return 0;
}
