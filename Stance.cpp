#include "Stance.h"

Stance::Stance():significance(),approach(){}
Stance::Stance(double _significance, double _approach) : significance(_significance), approach(_approach){}
double Stance::getSignificance() const{
    return significance;
}
void Stance::setSignificance(double significance){
    this->significance = significance;
}
double Stance::getApproach() const{
    return approach;
}
void Stance::setApproach(double approach){
    this->approach = approach;
}
void Stance::print(){
    std::cout<<"\tSignificance: "<<significance<<std::endl;
    std::cout<<"\tApproach: "<<approach<<std::endl;
}