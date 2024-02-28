#include <string>
#include <random>
class Stance;
class Individual;
class Candidate;
class Leader;
class CampaignTeam;
class StanceRange;
class Issue;
class Party;
class ElectoralDivision;
class Event;
class DebateEvent;
class CandidateEvent;
class LeaderEvent;
class IssueEvent;
class Randomness;
class Generator;
class Simulation;
enum class EventType{
    none, 
    Debate,
    Candidate_voluntary,
    Candidate_presentation,
    Leader_speech,
    Leader_guidance,
    Issue_solution,
    Issue_planning
};
class Stance{
private:
    double significance;
    double approach;
public:
    Stance();
    Stance(double, double);
    double getSignificance() const;
    void setSignificance(double);
    double getApproach() const;
    void setApproach(double);
    void print();
};
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
class Candidate : public Individual{
private:
    double debateSkill;
    ElectoralDivision* division;
public:
    Candidate();
    Candidate(std::string, std::vector<Stance>, double, Party*, double, ElectoralDivision*);
    double getDebateSkill();
    void setDebateSkill(double);
    ElectoralDivision* getDivision();
    void setDivision(ElectoralDivision&);
    void print();
};
class Leader : public Individual{
private:
    double leadership;
public:
    Leader();
    Leader(std::string, std::vector<Stance>, double, Party*, double);
    void setLeadership(double);
    double getLeadership();
    void print();
};
class CampaignTeam{
private:
    double creativity;
    double communication;
    double planOrientation;
public:
    CampaignTeam();
    CampaignTeam(double, double, double);
    void setCreativity(double);
    double getCreativity();
    void setCommunication(double);
    double getCommunication();
    void setPlanOrientation(double);
    double getPlanOrientation();
    void print();
};
class Issue{
private: 
    std::string name;
public:
    Issue();
    Issue(std::string);
    std::string getName();
    void setName(std::string);
    void print();
};
class StanceRange{
private:
    double minSignificance;
    double maxSignificance;
    double minApproach;
    double maxApproach;
public:
    StanceRange();
    StanceRange(double, double, double, double);
    double getMinSignificance();
    void setMinsignificance(double);
    double getMaxSignificance();
    void setMaxSignificance(double);
    double getMinApproach();
    void setMinApproach(double);
    double getMaxApproach();
    void setMaxApproach(double);
    double getRandomSignificance() const;
    double getRandomApproach() const;
    void print();
};
class Party{
private:
    std::string name;
    Leader leader;
    StanceRange range;
    std::vector<Issue> issues;
    std::vector<Stance> stances;
    CampaignTeam team;
public:
    Party();
    Party(std::string, Leader, const StanceRange&, std::vector<Issue>, std::vector<Stance>, CampaignTeam);
    std::string getName();
    void setName(std::string);
    Leader getLeader();
    CampaignTeam getTeam();
    std::vector<Issue> getIssues();
    void setLeader(Leader);
    std::vector<Stance> getStance();
    void print();
};
class ElectoralDivision{
private:
    std::string name;
    int support;
    std::vector<Stance> stances;
    std::vector<Issue> issues;
    std::vector<Candidate> candidates;
public:
    ElectoralDivision();
    ElectoralDivision(std::string, int, std::vector<Stance>, std::vector<Issue>);
    std::string getName();
    void setName(std::string);
    int getSupport();
    void setSupport(int);
    std::vector<Stance> getStances();
    std::vector<Candidate> getCandidates();
    Candidate* getCandidate(std::string);
    void addCandidate(const Candidate&);
    void print();
};
class Event{
protected:
    EventType type;
    ElectoralDivision* division;
public:
    Event();
    Event(EventType, ElectoralDivision* division);
    EventType getType() const;
    virtual void process() = 0;
};
class DebateEvent : public Event{
public:
    DebateEvent() = default;
    DebateEvent(ElectoralDivision*);
    void process() override;
};
class CandidateEvent : public Event{
private:
    std::shared_ptr<Candidate> candidate;
public:
    CandidateEvent() = default;
    CandidateEvent(EventType, ElectoralDivision*, std::shared_ptr<Candidate>);
    void process() override;
};
class LeaderEvent : public Event{
private:
    std::shared_ptr<Leader> leader;
public:
    LeaderEvent() = default;
    LeaderEvent(EventType, ElectoralDivision*, std::shared_ptr<Leader>);
    void process() override;
};
class IssueEvent : public Event{
private:
    std::shared_ptr<Issue> issue;
    std::shared_ptr<Candidate> candidate;
public:
    IssueEvent() = default;
    IssueEvent(EventType, ElectoralDivision*, std::shared_ptr<Issue>, std::shared_ptr<Candidate>);
    void process() override;
};
class Randomness{
private:
    static std::default_random_engine rnd;
public:
    static int randomInt(int, int);
    static double randomDouble(double, double);
    static double getNormalDistribution(double mean, double deviation = 0.3);
};
class Generator{
private:
    static const std::string Issues_types[];
    static const std::string parties_names[];
    static const std::string leader_names[];
    static const std::vector<std::string> candidate_names;
    static const std::vector<std::string> division_names;
    static void generateIssues();
    static void generateParties();
    static void generateDivisions(int);
    static Stance generateStance(const StanceRange& range = StanceRange());
    static void generateLeader();
    static void generateCandidate();
    static CampaignTeam generateCampaignTeam();
public:
    static void generate(int n, int m);
};
class Simulation{
private:
    int numberOfDivisions;
    int numberOfDays;
    std::vector<Issue> issues;
    std::vector<Party> parties;
    std::vector<ElectoralDivision> divisions;
    Simulation() : numberOfDivisions(0), numberOfDays(0) {}
public:
    static Simulation& call();
    void setNumberOfDivisions(int);
    void setNumberOfDays(int);
    std::vector<Issue>& getIssues();
    std::vector<Party>& getParties();
    std::vector<ElectoralDivision>& getDivisions();
    double candidateTotalPopularity(ElectoralDivision*);
    double candidateTotalSkillset(ElectoralDivision*);
    double leaderTotalPopularity();
    double leaderTotalSkillset();
    static double updateSkillSet(double, double);
    static void moveStance(Stance* beginStance, Stance* destinationStance, double, double, bool significanceFlag = true, bool approachFlag = true);
    void addIssue(const Issue&);
    void addParty(const Party&);
    void addDivision(const ElectoralDivision&);
    std::shared_ptr<Event> randomEvent(ElectoralDivision&);
    double calculateStanceRange(const Stance*, const Stance*);
    double calculateStanceDifferenceForIssue(const int, ElectoralDivision*, Party*);
    void printInfo();
    void processSimulation();
    void votingDay();
};