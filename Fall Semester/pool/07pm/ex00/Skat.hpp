#include <string>
#ifndef SCAT_FILE
#define SCAT_FILE

class Skat
{
public:
    Skat(const std::string &name = "bob", int stimPaks = 15);
    ~Skat();

    int &stimPaks();
    int stimPaks(int stimPaks);
    const std::string &name();
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
    void status();

    std::string _name;
    int _stimpaks; 
};

#endif