#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include "hashing.h"
#include "gamma.h"

#define size_of_char(x) (sizeof(x) / sizeof(x[0]))

int main() {

    std::string filename_input="C:/Users/Asus/Desktop/athlete_events.csv";
    std::string filename_output="C:/Users/Asus/Desktop/test.csv";
    std::string filename_output_gamma="C:/Users/Asus/Desktop/test_g.csv";
    std::ifstream work_file(filename_input);
    std::string line;

    std::ofstream file_out;
    file_out.open(filename_output);

    std::ofstream file_out_g;
    file_out_g.open(filename_output_gamma);

    char delimiter=',';
    getline(work_file,line);
    int counter=0;
    char key[5]="123";
    while(getline(work_file,line)){
        counter++;
        std::stringstream st(line);
        std::string id_pers, name_pers, sex_pers,age_pers, height_pers, weights_pers, country_pers, city_pers;

        char id_c[id_pers.length()+1];
        char name_c[name_pers.length()+1];
        char sex_c[sex_pers.length()+1];
        char age_c[age_pers.length()+1];
        char height_c[height_pers.length()+1];
        char weight_c[weights_pers.length()+1];
        char country_c[country_pers.length()+1];
        char city_c[city_pers.length()+1];

        /*now we read it*/
        getline(st,id_pers,delimiter);
        getline(st,name_pers,delimiter);
        getline(st,sex_pers,delimiter);
        getline(st,age_pers,delimiter);
        getline(st,height_pers,delimiter);
        getline(st,weights_pers,delimiter);
        getline(st,country_pers,delimiter);
        getline(st,city_pers,delimiter);

        /* now we write it*/
        /*в этом методе одно из значений (country_pers) хэшируется по алгоритму sha256.
         * Такой подход можно назвать надежным, однако при хранении такие данные обратно получить не выйдет.
         */
        file_out<<id_pers<<","<<name_pers<<","<<sex_pers<<","<<age_pers<<","<<height_pers<<","<<weights_pers<<","<<sha256(country_pers)<<","<<city_pers<<'\n';

        /*воспользуемся гаммированием для шифрования данных так, что их можно будет получить обратно, если знать ключ*/

        strcpy(id_c,id_pers.c_str());
        strcpy(name_c,name_pers.c_str());
        strcpy(sex_c,sex_pers.c_str());
        strcpy(age_c,age_pers.c_str());
        strcpy(height_c,height_pers.c_str());
        strcpy(weight_c,weights_pers.c_str());
        strcpy(country_c,country_pers.c_str());
        strcpy(city_c,city_pers.c_str());

        file_out_g<<id_c<<","<<name_c<<","<<sex_c<<","<<age_c<<","<<height_c<<","<<weight_c<<","<<gamming(country_c, size_of_char(country_c),key,size_of_char(key))<<","<<city_c<<'\n';
    }
    work_file.close();
    file_out.close();
    file_out_g.close();

    return 0;
}
