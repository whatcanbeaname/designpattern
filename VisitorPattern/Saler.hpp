#include <iostream>
#include "Publisher.hpp"

class Saler : public Publisher
{
public:
    Saler(std::string saler) : _saler(saler) {}
    ~Saler() {}
    void setMsg(std::string msg)
    {
        _msg = msg;
        std::cout << "saler " << _saler << " promotes a new ad: " << _msg << std::endl;
    }

private:
    std::string _saler;
};