#include <iostream>
#include <random>
#include "library.h"
//Individual class
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
//Leader class
Leader::Leader(){}
Leader::Leader(std::string _name, std::vector<Stance> _stances, double _popularity, Party* _party, double _leadership):Individual(_name, _stances, _popularity, _party){
    leadership = _leadership;
}
void Leader::setLeadership(double leadership){
    this->leadership = leadership;
}
double Leader::getLeadership(){
    return leadership;
}
void Leader::print(){
    std::cout<<"\tLeader: "<<name<<std::endl;
    Individual::print();
    std::cout<<"\tLeadership skill: "<<leadership<<std::endl;
}
//Candidate class
Candidate::Candidate(){}
Candidate::Candidate(std::string _name, std::vector<Stance> _stances, double _popularity, Party* _party,double _debateSkill, ElectoralDivision* _division):Individual(_name, _stances, _popularity, _party){
    debateSkill = _debateSkill;
    division = _division;
}
double Candidate::getDebateSkill(){
    return debateSkill;
}
void Candidate::setDebateSkill(double debateSkill){
    this->debateSkill = debateSkill;
}
ElectoralDivision* Candidate::getDivision(){
    return division;
}
void Candidate::setDivision(ElectoralDivision& _division){
    division = &_division;
}
void Candidate::print(){
    std::cout<<"\tName: "<<name<<std::endl;
    Individual::print();
    std::cout<<"\tDebate skill: "<<debateSkill<<std::endl;
}
//Campaign team class
CampaignTeam::CampaignTeam():creativity(), communication(), planOrientation(){}
CampaignTeam::CampaignTeam(double _creativity, double _communication, double _planOrientation)
        :creativity(_creativity), communication(_communication), planOrientation(_planOrientation){}
void CampaignTeam::setCommunication(double communication){
    this->communication = communication;
}
double CampaignTeam::getCommunication(){
    return communication;
}
void CampaignTeam::setCreativity(double creativity){
    this->creativity = creativity;
}
double CampaignTeam::getCreativity(){
    return creativity;
}
void CampaignTeam::setPlanOrientation(double planOrientation){
    this->planOrientation = planOrientation;
}
double CampaignTeam::getPlanOrientation(){
    return planOrientation;
}
void CampaignTeam::print(){
    std::cout<<"\tCampaign Team skills: "<<std::endl;
    std::cout<<"\t- Creativity skill: "<<creativity<<std::endl;
    std::cout<<"\t- Communication skill: "<<communication<<std::endl;
    std::cout<<"\t- Plan Orientation skill: "<<planOrientation<<std::endl;
}
//Issue class
Issue::Issue():name(){}
std::string Issue::getName(){
    return this->name;
}
Issue::Issue(std::string _name):name(_name){}
void Issue::setName(std::string name){
    this->name = name;
}
void Issue::print(){
    std::string issueName = getName();
    std::cout<<"Issue: "<<issueName<<std::endl;
    if(issueName == "Tsunami")
    {
        std::cout<<"The tsunami had wiped out 3 suburbs causing a destructive loss and there's a possibility of another upcoming tsunami"<<std::endl;
    }
    if (issueName == "Plague pandemic")
    {
        std::cout<<"There has been an outbreak of an unknown globally contagious plague"<<"\n"<<"We need a solution to prevent this."<<std::endl;
    }
    if (issueName == "Wildlife rampage")
    {
        std::cout<<"Many citizens have reported about being assaulted by wild animals causing tremendous damage including deaths"<<"\n"<<"Wee need to put this under control"<<std::endl;
    }
    if (issueName == "Racism")
    {
        std::cout<<"There still exists many inappropriate racist behaviour among the society"<<"\n"<<"What approach should we have?"<<std::endl;
    }
    if (issueName == "Child labour")
    {
        std::cout<<"Many region still abuse children and deprive them from their childhood to work"<<"\n"<<"Many owners want to keep their cost low"<<std::endl;
    }
}
//Stance class
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
//Stance Range class
StanceRange::StanceRange(){
    this->minSignificance = 0;
    this->maxSignificance = 10;
    this->minApproach = 0;
    this->maxApproach = 10;
}
StanceRange::StanceRange(double _minSignificance, double _maxSignificance, double _minApproach, double _maxApproach)
    : minSignificance(_minSignificance), maxSignificance(_maxSignificance), minApproach(_minApproach), maxApproach(_maxApproach){}
double StanceRange::getMinSignificance(){
    return minSignificance;
}
void StanceRange::setMinsignificance(double min){
    this->minSignificance = min;
}
double StanceRange::getMaxSignificance(){
    return maxSignificance;
}
void StanceRange::setMaxSignificance(double max){
    this->maxSignificance = max;
}
double StanceRange::getMinApproach(){
    return minApproach;
}
void StanceRange::setMinApproach(double min){
    this->minApproach = min;
}
double StanceRange::getMaxApproach(){
    return maxApproach;
}
void StanceRange::setMaxApproach(double max){
    this->maxApproach = max;
}
double StanceRange::getRandomSignificance() const{
    return Randomness::randomDouble(minSignificance, maxSignificance);
}
double StanceRange::getRandomApproach() const{
    return Randomness::randomDouble(minApproach, maxApproach);
}
void StanceRange::print(){
    std::cout<<"The significance range of the stance is from "<<minSignificance<<" to " <<maxSignificance<<std::endl;
    std::cout<<"The approach range of the stance is from "<<minApproach<<" to "<<maxApproach<<std::endl;
}
//Party class
Party::Party():name(), leader(), range(), team(){}
Party::Party(std::string _name, Leader _leader, const StanceRange& _range, std::vector<Issue> _issues, std::vector<Stance> _stances, CampaignTeam _team)
    : name(_name), leader(_leader), range(_range), team(_team){
    for (int i = 0; i < 5; i++)
    {
        issues.push_back(_issues[i]);
        stances.push_back(_stances[i]);
    }
}
std::string Party::getName(){
    return name;
}
void Party::setName(std::string name){
    this->name = name;
}
Leader Party::getLeader(){
    return leader;
}
CampaignTeam Party::getTeam(){
    return team;
}
void Party::setLeader(Leader leader){
    this->leader = leader;
}
std::vector<Issue> Party::getIssues(){
    return issues;
}
std::vector<Stance> Party::getStance(){
    return stances;
}
void Party::print(){
    std::cout<<"Party "<<name<<std::endl<<std::endl;
    leader.print();
    std::cout<<std::endl;
    range.print();
    for (int i = 0; i < 5; ++i){
        std::cout<<"The stance on "<<issues[i].getName()<<": "<<std::endl;
        stances[i].print();
    }
    team.print();
}
//Electoral Division
ElectoralDivision::ElectoralDivision():name(){}
ElectoralDivision::ElectoralDivision(std::string _name, int _support, std::vector<Stance> _stances, std::vector<Issue> _issues):name(_name), support(_support){
    for (int i = 0; i < 5; i++)
    {
        stances.push_back(_stances[i]);
        issues.push_back(_issues[i]);
    }
}
std::string ElectoralDivision::getName(){
    return name;
}
void ElectoralDivision::setName(std::string name){
    this->name = name;
}
int ElectoralDivision::getSupport(){
    return support;
}
void ElectoralDivision::setSupport(int _support){
    this->support = _support;
}
std::vector<Stance> ElectoralDivision::getStances(){
    return stances;
}
std::vector<Candidate> ElectoralDivision::getCandidates(){
    return candidates;
}
Candidate* ElectoralDivision::getCandidate(std::string partyName){
    for(auto &candidate:candidates){
        if (candidate.getParty()->getName() == partyName)
        {
            return &candidate;
        }
    }
    return nullptr;
}
void ElectoralDivision::addCandidate(const Candidate& _candidate){
    candidates.push_back(_candidate);
}
void ElectoralDivision::print(){
    std::cout<<"Electoral Division: "<<name<<std::endl;
    std::cout<<"The support from the community: "<<support<<std::endl;
    std::cout<<"With the list of candidates: "<<std::endl;
    for(int i = 0; i<3;i++){
        std::cout<<"Candidate of the division "<<name<<" from the party "<<candidates[i].getParty()->getName()<<std::endl;
        candidates[i].print();
    }
    std::cout<<"With the list of issues along with their stances: "<<std::endl;
    for(int i =0; i<5; i++){
        std::cout<<"The stance on "<<issues[i].getName()<<": "<<std::endl;
        stances[i].print();
    }
}
//Event class
Event::Event():type(EventType::none), division(nullptr){}
Event::Event(EventType _type, ElectoralDivision* _division):type(_type), division(_division){}
EventType Event::getType() const {
    return type;
}
//Debate event class
DebateEvent::DebateEvent(ElectoralDivision* _division):Event(EventType::Debate, _division){}
void DebateEvent::process(){
    std::cout<<"A debate event has occurred"<<std::endl;
    auto candidates = division->getCandidates();
    Candidate* winner;
    auto totalSet = 0.5 * Simulation::call().candidateTotalPopularity(division) + 0.5 * Simulation::call().candidateTotalSkillset(division);
    //winner update loop
    for (auto &candidate:candidates)
    {
        auto skillSet = 0.5 * candidate.getDebateSkill() + 0.5 * candidate.getPopularity();
        if (Randomness::randomDouble(0, totalSet) <= skillSet)
        {
            winner = &candidate;
            std::cout<< "The candidate "<<winner->getName()<<" is the winner of the debate event."<<std::endl;
            auto oldSkillSet = winner->getDebateSkill();
            winner->setDebateSkill(Simulation::call().updateSkillSet(oldSkillSet, Simulation::call().candidateTotalSkillset(division)));
            auto oldPopularity = winner->getPopularity();
            winner->setPopularity(Simulation::call().updateSkillSet(oldPopularity, Simulation::call().candidateTotalPopularity(division)));
            std::cout<<"The winner will earn a reward:"<<std::endl;
            std::cout<<"\t- The Debate skill is increased from "<<oldSkillSet<<" to "<<winner->getDebateSkill()<<std::endl;
            std::cout<<"\t- The popularity is increased from "<<oldPopularity<<" to "<<winner->getPopularity()<<std::endl;
            break;
        }
        totalSet -= skillSet;
    }
    //loser update loop
    std::cout<<"For other candidate: "<<std::endl;
    for (auto &candidate:candidates)
    {
        if(candidate.getName() != winner->getName()){
            auto oldSkillSet = candidate.getDebateSkill();
            candidate.setDebateSkill(Simulation::call().updateSkillSet(oldSkillSet, Simulation::call().candidateTotalSkillset(division))/3);
            std::cout<<"\t- Candidate "<<candidate.getName()<<" has earned a small increase in the skill set from "<<oldSkillSet<<" to "<<candidate.getDebateSkill()<<std::endl;
        }
    }
    int i = 0;
    for(auto &issue: Simulation::call().getIssues()){
        std::cout<<"- The electoral division's stance on issue "<< issue.getName() <<std::endl;
        auto data = winner->getDebateSkill() + winner->getPopularity();
        auto totalValue = Simulation::call().candidateTotalPopularity(division) + Simulation::call().candidateTotalSkillset(division);
        auto firstStance = division->getStances()[i];
        Simulation::moveStance(&division->getStances()[i], &winner->getStances()[i], data, totalValue);
        std::cout<<"Significance changed from " <<firstStance.getSignificance()<<" to "<< winner->getStances()[i].getSignificance()<<std::endl;
        std::cout<<"Approach changed from "<<firstStance.getApproach()<<" to "<<winner->getStances()[i].getApproach()<<std::endl;
        i++;
    }
}
//Candidate event class
CandidateEvent::CandidateEvent(EventType _type, ElectoralDivision* _division, std::shared_ptr<Candidate> _candidate):Event(_type, _division), candidate(std::move(_candidate)){}
void CandidateEvent::process(){
   if (type == EventType::Candidate_presentation)
   {
        std::cout<<"Candidate "<<candidate->getName()<<" has performed a presentation."<<std::endl;
        auto oldSkillSet = candidate->getDebateSkill();
        candidate->setDebateSkill(Simulation::call().updateSkillSet(oldSkillSet, Simulation::call().candidateTotalSkillset(division)));
        std::cout<<"\t- The candidate's debate skill has increased from "<<oldSkillSet<<" to "<<candidate->getDebateSkill()<<std::endl;
        int i = 0;
        auto divisionStances = division->getStances();
        auto candidateStances = candidate->getStances();
        size_t numIssues = Simulation::call().getIssues().size();
        for (; i < numIssues && i < divisionStances.size() && i < candidateStances.size(); ++i) {
            std::cout << "- The electoral division's stance on issue " << Simulation::call().getIssues()[i].getName() << std::endl;
            auto data = candidate->getDebateSkill() + candidate->getPopularity();
            auto totalValue = Simulation::call().candidateTotalPopularity(division) + Simulation::call().candidateTotalSkillset(division);
            auto firstStance = divisionStances[i];
            if (i < divisionStances.size() && i < candidateStances.size()) {
                Simulation::moveStance(&divisionStances[i], &candidateStances[i], data, totalValue);
                std::cout << "Significance changed from " << firstStance.getSignificance() << " to " << candidateStances[i].getSignificance() << std::endl;
                std::cout << "Approach changed from " << firstStance.getApproach() << " to " << candidateStances[i].getApproach() << std::endl;
            }
        }
    }
   if (type == EventType::Candidate_voluntary)
   {
        std::cout<<"Candidate "<<candidate->getName()<<" has volunteered for an activity."<<std::endl;
        auto oldPopularity = candidate->getPopularity();
        candidate->setPopularity(Simulation::call().updateSkillSet(oldPopularity, Simulation::call().candidateTotalPopularity(division)));
        std::cout<<"\t - The candidate's popularity has increased from "<<oldPopularity<<" to "<<candidate->getPopularity()<<std::endl;
   }
}
//Leader event class
LeaderEvent::LeaderEvent(EventType _type, ElectoralDivision* _division, std::shared_ptr<Leader> _leader):Event(_type, _division), leader(std::move(_leader)){}
void LeaderEvent::process(){
    //increase popularity
    if (type == EventType::Leader_speech)
    {
        std::cout<<"The leader "<<leader->getName()<<" from party "<<leader->getParty()->getName()<<" has performed a speech in front of the community."<<std::endl;
        auto oldPopularity = leader->getPopularity();
        leader->setPopularity(Simulation::call().updateSkillSet(oldPopularity, Simulation::call().leaderTotalPopularity()));
        std::cout<<"\t- The leader's popularity has increased from "<<oldPopularity<<" to "<<leader->getPopularity()<<std::endl;
    }
    //Increase leadership
    if (type == EventType::Leader_guidance)
    {
        std::cout<<"The leader "<<leader->getName()<<" from party "<<leader->getParty()->getName()<<" has provided a guideline solution for the issue."<<std::endl;
        auto oldSkillSet = leader->getLeadership();
        leader->setLeadership(Simulation::call().updateSkillSet(oldSkillSet, Simulation::call().leaderTotalSkillset()));
        std::cout<<"\t- The leadership skill set has increased from "<<oldSkillSet<<" to "<<leader->getLeadership()<<std::endl;
    }
}
//Issue event class
IssueEvent::IssueEvent(EventType _type, ElectoralDivision* _division, std::shared_ptr<Issue> _issue, std::shared_ptr<Candidate> _candidate):Event(_type, _division), issue(std::move(_issue)), candidate(std::move(_candidate)){}
void IssueEvent::process(){
    //if type is planning, increase the significance
    if (type == EventType::Issue_planning)
    {
        int index = Randomness::randomInt(0,Simulation::call().getIssues().size()-1);
        std::cout<<candidate->getName()<<" has made a different plan on issue "<<issue->getName()<<" due to unexpected occurance"<<std::endl;
        auto division = candidate->getDivision();
        auto stance = candidate->getStances()[index];
        auto totalValue = Simulation::call().candidateTotalPopularity(division) + Simulation::call().candidateTotalSkillset(division);
        auto data = candidate->getDebateSkill() + candidate->getPopularity();
        auto oldSignificance = stance.getSignificance();
        Simulation::call().moveStance(&stance, &candidate->getDivision()->getStances()[index], data, totalValue, true, false);
        auto newSignificance = stance.getSignificance();
        std::cout<<"\t- Thereby increasing the significance of the issue from "<<oldSignificance<<" to "<<newSignificance<<std::endl;
    }
    //if type is solution, increase the approach
    if (type == EventType::Issue_solution)
    {
        int index = Randomness::randomInt(0,Simulation::call().getIssues().size()-1);
        std::cout<<candidate->getName()<<" has provided a solution on issue "<<issue->getName()<<", pushing the process speed to solve the problem."<<std::endl;
        auto division = candidate->getDivision();
        auto stance = candidate->getStances()[index];
        auto totalValue = Simulation::call().candidateTotalPopularity(division) + Simulation::call().candidateTotalSkillset(division);
        auto data = candidate->getDebateSkill() + candidate->getPopularity();
        auto oldApproach = stance.getApproach();
        Simulation::call().moveStance(&stance, &candidate->getDivision()->getStances()[index], data, totalValue, false, true);
        auto newApproach = stance.getApproach();
        std::cout<<"\t- Increasing the approach on the issue from "<<oldApproach<<" to "<<newApproach<<std::endl;
    }    
}
//Randomness class
std::default_random_engine Randomness::rnd(time(0));
int Randomness::randomInt(int n, int m){
    std::uniform_int_distribution<int> distribution(n,m);
    return distribution(rnd);
}
double Randomness::randomDouble(double m, double n){
    std::uniform_real_distribution<double> distribution(m, n);
    return distribution(rnd);
}
double Randomness::getNormalDistribution(double mean, double deviation){
    std::normal_distribution<double> dis(mean, deviation);
    return dis(rnd);
}
//Generator class
const std::string Generator::Issues_types[5] = {
    "Tsunami",
    "Plague pandemic",
    "Wildlife rampage",
    "Racism",
    "Child labour"
};
const std::string Generator::parties_names[3]={"Galactic Unity Party", "Enchanted Garden Gathering","TechnoFusion Extravaganza"};
const std::string Generator::leader_names[3]={"Jose","Jim","Bombay"};
const std::vector<std::string> Generator::candidate_names = 
    {"Sarah Johnson", "David Martinez", "Jennifer Smith"
    "Michael Anderson", "Emily Davis", "Christopher Wilson"
    "Samantha Taylor", "Robert Jackson", "Olivia Brown"
    "William Lee", "Jessica Robinson", "James Harris"
    "Ashley White", "Daniel Thompson", "Elizabeth Clark"
    "Benjamin Turner", "Victoria Garcia", "Matthew Martin"
    "Sophia Adams", "Andrew Lewis", "Emma Hall"
    "Nicholas Wright", "Lauren Thomas", "Joshua King"
    "Ava Mitchell", "Ethan Rodriguez", "Grace Hernandez"
    "John Williams", "Mia Davis", "Jacob Taylor"};
const std::vector<std::string> Generator::division_names = {
    "Willowdale", "Cypress", "Qu'Appelle", "Okefenokee", "Adirondack",
    "Saguenay", "Biscayne", "Dandenong", "Napa", "Gila"
};
void Generator::generateIssues(){
    Simulation* simulationPtr = &Simulation::call();

    for (auto issueType : Issues_types) {
        Issue issue(issueType);
        simulationPtr->addIssue(issue);
    }
}
void Generator::generateParties(){
    for(int i = 0; i<3; i++){
        StanceRange range;
        std::vector<Issue> issues;
        std::vector<Stance> stances;
        for (int j = 0; j < 5; j++)
        {
            issues.push_back(Simulation::call().getIssues()[j]);
            stances.push_back(generateStance(range));
        }
        Leader leader;
        CampaignTeam team = generateCampaignTeam();
        Party party(parties_names[i], leader, range, issues, stances, team);
        Simulation::call().addParty(party);
    }
}
void Generator::generateDivisions(int numberOfDivisions){
    auto inputDivision = Generator::division_names;
    for (int i = 0; i < numberOfDivisions; i++)
    {
        int index = Randomness::randomInt(0, inputDivision.size()-1);
        auto newName = inputDivision[index];
        inputDivision.erase(inputDivision.begin()+index);
        int support = Randomness::randomInt(1000, 10000);
        std::vector<Issue> issues;
        std::vector<Stance> stances;
        for (int i = 0; i < Simulation::call().getIssues().size(); i++)
        {
            issues.push_back(Simulation::call().getIssues()[i]);
            stances.push_back(generateStance());
        }

        ElectoralDivision division = ElectoralDivision(newName, support, stances, issues);
        Simulation::call().addDivision(division);
    }
}
Stance Generator::generateStance(const StanceRange& range){
    auto newApproach = range.getRandomApproach();
    auto newSignificance = range.getRandomSignificance();
    Stance newStance(newApproach, newSignificance);
    return newStance;
}
void Generator::generateLeader(){
    for (int i = 0; i<Simulation::call().getParties().size();i++){
        auto leader = Leader();
        leader.setName(leader_names[i]);
        leader.setPopularity(Randomness::randomDouble(0.1, 10.0));
        leader.setLeadership(Randomness::randomDouble(0.1, 10.0));
        std::vector<Stance> stances;
        for (int k = 0; k < 5; k++)
        {
            stances.push_back(Simulation::call().getParties()[i].getStance()[k]);
            leader.addStance(stances[k]);
        }
        Simulation::call().getParties()[i].setLeader(leader);
    }
}
void Generator::generateCandidate(){
    auto candidate_list = Generator::candidate_names;
    for(int i = 0; i<Simulation::call().getDivisions().size(); i++){
        for (int j = 0; j < Simulation::call().getParties().size(); j++)
        {
            auto &party = Simulation::call().getParties()[j];
            int index = Randomness::randomInt(0, candidate_list.size()-1);
            auto name = candidate_list[index];
            candidate_list.erase(candidate_list.begin()+index);
            auto candidate = Candidate();
            auto &division = Simulation::call().getDivisions()[i];
            candidate.setName(name);
            candidate.setPopularity(Randomness::randomDouble(0.1, 10.0));
            candidate.setDebateSkill(Randomness::randomDouble(0.1, 10.0));
            candidate.setParty(party);
            candidate.setDivision(division);
            int k = 0;
            for(auto &issue:Simulation::call().getIssues()){
                auto stance = party.getStance()[k];
                candidate.addStance(stance);
                k++;
            }
            Simulation::call().getDivisions()[i].addCandidate(candidate);
        }
    }
}
CampaignTeam Generator::generateCampaignTeam(){
    auto team = CampaignTeam();
    double min = 0.1;
    double max = 10.0;
    team.setCreativity(Randomness::randomDouble(min, max));
    team.setCommunication(Randomness::randomDouble(min, max));
    team.setPlanOrientation(Randomness::randomDouble(min, max));
    return team;
}
void Generator::generate(int numberOfDivisions, int numberOfDays){
    Simulation::call().setNumberOfDivisions(numberOfDivisions);
    Simulation::call().setNumberOfDays(numberOfDays);
    Generator::generateIssues();
    Generator::generateParties();
    Generator::generateDivisions(numberOfDivisions);
    Generator::generateLeader();
    Generator::generateCandidate();
}
//Simulation class
Simulation& Simulation::call(){
    static Simulation simulation;
    return simulation;
}
void Simulation::setNumberOfDivisions(int n){
    numberOfDivisions = n;
}
void Simulation::setNumberOfDays(int m){
    numberOfDays = m;
}
std::vector<Issue>& Simulation::getIssues(){
    return issues;
}
std::vector<Party>& Simulation::getParties(){
    return parties;
}
std::vector<ElectoralDivision>& Simulation::getDivisions(){
    return divisions;
}
double Simulation::candidateTotalPopularity(ElectoralDivision* divisions){
    double total = 0;
    auto candidates = divisions->getCandidates();
    for(auto &candidate : candidates){
        total += candidate.getPopularity();
    }
    return total;
}
double Simulation::candidateTotalSkillset(ElectoralDivision* divisions){
    double total = 0;
    auto candidates = divisions->getCandidates();
    for (auto &candidate : candidates){
        total += candidate.getDebateSkill();
    }
    return total;
}
double Simulation::leaderTotalPopularity(){
    double total = 0;
    for (auto &party: parties)
    {
        total+=party.getLeader().getPopularity();
    }
    return total;
}
double Simulation::leaderTotalSkillset(){
    double total = 0;
    for (auto &party:parties)
    {
        total += party.getLeader().getLeadership();
    }
    return total;
}
double Simulation::updateSkillSet(double oldValue, double totalValue){
    auto limit = (10 - oldValue)*(oldValue/totalValue);
    auto increment = Randomness::randomDouble(0.0, limit);
    if (increment < 0.0)
    {
        increment = 0.0;
    }
    double constraint = 10.0 - oldValue;
    if (increment > constraint)
    {
        increment = constraint;
    }
    return oldValue + increment;
}
void Simulation::moveStance(Stance* beginStance, Stance* destinationStance, 
            double data, double totalValue, bool significanceFlag, bool approachFlag){
    auto ratio = (totalValue != 0.0) ? data / totalValue : 0.0;
    if (significanceFlag)
    {
        auto significanceRange = destinationStance->getSignificance() - beginStance->getSignificance();
        beginStance->setSignificance(beginStance->getSignificance() + fabs(significanceRange) * ratio);
    }
    if (approachFlag)
    {
        auto approachRange = destinationStance->getApproach() - beginStance->getApproach();
        beginStance->setApproach(beginStance->getApproach() + fabs(approachRange) * ratio);
    }
}
void Simulation::addIssue(const Issue& issue){
    issues.push_back(issue);
}
void Simulation::addParty(const Party& party){
    parties.push_back(party);
}
void Simulation::addDivision(const ElectoralDivision &division){
    divisions.push_back(division);
}
std::shared_ptr<Event> Simulation::randomEvent(ElectoralDivision &division){
    double randomValue1 = Randomness::randomDouble(0.0,1.0);
    std::shared_ptr<Event> event;
    if (randomValue1 <=0.5)
    {
        event= nullptr;
    }
    else
    {
        double randomValue = Randomness::randomDouble(0.0,1.0);
        if (randomValue <= 0.25)
        {
            event = std::make_shared<DebateEvent>(&division);
        }
        else if (randomValue > 0.25 && randomValue <= 0.5)
        {
            int subEvent = Randomness::randomInt(1, 2);
            if (subEvent == 1)
            {
                auto randomCandidate = division.getCandidates()[Randomness::randomInt(0, division.getCandidates().size()-1)];
                event = std::make_shared<CandidateEvent>(EventType::Candidate_presentation, &division, std::make_shared<Candidate>(randomCandidate));
            }
            else
            {
                auto randomCandidate = division.getCandidates()[Randomness::randomInt(0, division.getCandidates().size()-1)];
                event = std::make_shared<CandidateEvent>(EventType::Candidate_voluntary, &division, std::make_shared<Candidate>(randomCandidate));
            }  
        }
        else if (randomValue > 0.5 && randomValue<=0.75)
        {
            int subEvent = Randomness::randomInt(1, 2);
            if (subEvent == 1)
            {
                std::vector<Leader> leaders;
                for (Party &party:parties)
                {
                    leaders.push_back(party.getLeader());
                }
                auto randomLeader = leaders[Randomness::randomInt(0, leaders.size()-1)];
                event = std::make_shared<LeaderEvent>(EventType::Leader_guidance, &division, std::make_shared<Leader>(randomLeader));
            }
            else
            {
                std::vector<Leader> leaders;
                for (Party &party:parties)
                {
                    leaders.push_back(party.getLeader());
                }
                auto randomLeader = leaders[Randomness::randomInt(0, leaders.size()-1)];
                event = std::make_shared<LeaderEvent>(EventType::Leader_speech, &division, std::make_shared<Leader>(randomLeader));
            }
        }
        else if (randomValue > 0.75)
        {
            int subEvent = Randomness::randomInt(1, 2);
            if (subEvent == 1)
            {
                auto randomIssue = issues[Randomness::randomInt(0, issues.size() - 1)];
                auto randomCandidate = division.getCandidates()[Randomness::randomInt(0, division.getCandidates().size()-1)];
                event = std::make_shared<IssueEvent>(EventType::Issue_planning, &division, std::make_shared<Issue>(randomIssue), std::make_shared<Candidate>(randomCandidate));
            }
            else
            {
                auto randomIssue = issues[Randomness::randomInt(0, issues.size() - 1)];
                auto randomCandidate = division.getCandidates()[Randomness::randomInt(0, division.getCandidates().size()-1)];
                event = std::make_shared<IssueEvent>(EventType::Issue_solution, &division, std::make_shared<Issue>(randomIssue), std::make_shared<Candidate>(randomCandidate));
            }
        }
    }
    return event;
}
//calculate Euclidean Distance
double Simulation::calculateStanceRange(const Stance* stance1, const Stance* stance2){
    auto significanceRange = stance1->getSignificance() - stance2->getSignificance();
    auto approachRange = stance1->getApproach() - stance2->getApproach();
    auto euclideanDistance = sqrt(significanceRange * significanceRange + approachRange * approachRange);
    auto maxDistance = sqrt(10 * 10 + 10 * 10);
    auto normalisedDistance = euclideanDistance/maxDistance;
    return normalisedDistance;
}
//function return stance difference for an issue
double Simulation::calculateStanceDifferenceForIssue(int index, ElectoralDivision* division, Party* party ){
    const std::vector<Stance>& divisionStances = division->getStances();
    const std::vector<Stance>& candidateStances = division->getCandidate(party->getName())->getStances();
    const std::vector<Stance>& leaderStances = party->getLeader().getStances();
    const std::vector<Stance>& partyStances = party->getStance();
    const Stance* divisionStance = &divisionStances[index];
    const Stance* candidateStance = &candidateStances[index];
    const Stance* leaderStance = &leaderStances[index];
    const Stance* partyStance = &partyStances[index];

    //calculate stance range
    auto candidateStanceRange = calculateStanceRange(divisionStance, candidateStance);
    auto leaderStanceRange = calculateStanceRange(divisionStance, leaderStance);
    auto partyStanceRange = calculateStanceRange(divisionStance, partyStance);
    
    auto totalWeight = candidateStanceRange * Randomness::getNormalDistribution(5) + 
                       leaderStanceRange * Randomness::getNormalDistribution(3) + 
                       partyStanceRange * Randomness::getNormalDistribution(2);

    return std::max(0.0, std::min(10.0, totalWeight));
}
void Simulation::printInfo(){
    std::cout<<std::string(20,'-')<<"CAMPAIGN DAY"<<std::string(20,'-')<<std::endl;
    std::cout<<"The five issues: "<<std::endl;
    for (auto &issue:issues){
        issue.print();
    }
    std::cout<<"The 3 present parties: "<<std::endl;
    for (auto &party:parties){
        party.print();
    }
    std::cout<<"There are "<<numberOfDivisions<<" electoral divisions in the election."<<std::endl;
    int i = 0;
    for(auto &division:divisions){
        std::cout<<"- The electoral divsion number "<<i+1<<": "<<std::endl;
        division.print();
        i++;
    }
    std::cout<<"The number of campaign days before the election: "<<numberOfDays<<std::endl;
    while (numberOfDays--)
    {
        processSimulation();
    }
}
void Simulation::processSimulation(){
    std::cout<< numberOfDays+1 << "day(s) until the election day."<<std::endl<<std::endl;
    for(auto &division : divisions){
        std::cout<<"The electoral division "<<division.getName() <<std::endl<<std::endl;
        auto event = randomEvent(division);
        if (event) {
            event->process();
        } else {
            std::cout << "No event occurred." <<std::endl;
        }
    }
    std::cout<<std::string(50, '-')<<std::endl;
}
void Simulation::votingDay() {
    std::cout << std::string(20, '-') << "ELECTION DAY" << std::string(20, '-') << std::endl;
    std::cout << "With 3 parties: " << std::endl;
    for (auto &party : parties) {
        party.print();
    }
    std::cout << std::string(50, '-') << std::endl;
    for (auto &division : divisions) {
        division.print();
    }
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Start voting" << std::endl;

    // Initialize variables to keep track of overall results
    std::vector<std::pair<std::string, double>> partyVotes;  // Vector to store total votes for each party
    int maxVotes = 0;
    std::string winningParty;

    for (auto &division : divisions) {
        std::cout << "Electoral division " << division.getName() << ": " << std::endl;

        // Vector to store voting scores for each candidate in this division
        std::vector<std::pair<std::string, double>> candidateScores;
        double maxScore = -1.0;
        std::string winningCandidate;

        for (auto &party : parties) {
            // Calculate average stance difference for this division and party
            double averageStanceDifference = 0.0;
            for (int issueIndex = 0; issueIndex < division.getStances().size(); ++issueIndex) {
                double stanceDifference = calculateStanceDifferenceForIssue(issueIndex, &division, &party);
                averageStanceDifference += stanceDifference;
            }
            averageStanceDifference /= division.getStances().size();

            // retrieve candidate, leader and team impact
            double candidateImpact = (division.getCandidate(party.getName())->getPopularity() + division.getCandidate(party.getName())->getDebateSkill())/2;
            double leaderImpact = (party.getLeader().getPopularity() + party.getLeader().getLeadership())/2;
            double campaignTeamImpact = (party.getTeam().getCommunication() + party.getTeam().getCreativity() + party.getTeam().getPlanOrientation())/3;
            // Calculate the voting score for this candidate
            double votingScore = averageStanceDifference * 0.5 + candidateImpact * 0.2 + leaderImpact * 0.2+ campaignTeamImpact * 0.1 *Randomness::randomDouble(2.0,7.0);

            candidateScores.emplace_back(party.getName(), votingScore);

            // Determine the winning candidate in this division
            if (votingScore > maxScore) {
                maxScore = votingScore;
                winningCandidate = party.getName();
            }
        }
        // Store the winning candidate's party for this division
        partyVotes.emplace_back(winningCandidate, division.getSupport());

        // Announce the party that won this division
        std::cout << "\t" << winningCandidate << " party is voted by the division of " << division.getName() << ".\n";
    }

    std::cout << "\nOverall results:\n";

    // Calculate the national summary and decide the winner
    std::vector<std::pair<std::string, int>> partyWins;
    for (auto &partyVote : partyVotes) {
        std::cout << "\t" << partyVote.first << " party is voted by " << partyVote.second << " voters.\n";
        bool found = false;
        for (auto &partyWin : partyWins) {
            if (partyWin.first == partyVote.first) {
                partyWin.second+= partyVote.second;
                found = true;
                break;
            }   
        }
        if (!found) {
            partyWins.emplace_back(partyVote.first, partyVote.second);
        }
    }
    // Determine the winning party and maximum votes
    for (const auto &entry : partyWins) {
        if (entry.second > maxVotes) {
            maxVotes += entry.second;
            winningParty = entry.first;
        }
    }
    // Check if any party has won more than 50% of the electoral divisions
    if (maxVotes > divisions.size() / 2) {
        std::cout << "\n" << winningParty << " is the winner party.\n";
        // Set the winning party as the new leader or perform any other necessary actions.
    } else {
        std::cout << "\nA hung parliament is declared.\n";
    }
}