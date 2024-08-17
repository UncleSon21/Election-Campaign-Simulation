#include "global.h"

class Party
class Individual{
protected:
    std::string name;
    std::vector<Stance> stances;
    double popularity;
    Party* party;
public:
    Individual();
    Individual(std::string, std::vector<Stance>, double, Party*);
    std::string getName();
    void setName(std::string);
    std::vector<Stance> getStances();
    void addStance(Stance&);
    double getPopularity();
    void setPopularity(double);
    Party* getParty();
    void setParty(Party& party);
    void print();
};