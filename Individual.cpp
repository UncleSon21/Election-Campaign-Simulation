#include "Individual.h"

Individual::Individual():name(),popularity(){}
Individual::Individual(std::string _name, std::vector<Stance> _stances, double _popularity, Party* _party)
    :name(_name), stances(std::move(_stances)), popularity(_popularity), party(_party){
}
std::string Individual::getName(){
    return name;
}
void Individual::setName(std::string name){
    this->name = name;
}
std::vector<Stance> Individual::getStances(){
    return stances;
}
void Individual::addStance(Stance& _stance){
    stances.push_back(_stance);
}
double Individual::getPopularity(){
    return popularity;
}
void Individual::setPopularity(double popularity){
    this->popularity = popularity;
}
Party* Individual::getParty(){
    return party;
}
void Individual::setParty(Party& _party){
    party = &_party;
}
void Individual::print(){
    std::cout<<"\tPopularity: "<<popularity<<std::endl;
}