#include "global.h"

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