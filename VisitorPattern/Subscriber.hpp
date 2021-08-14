#ifndef _SUBSCRIBER_HPP_
#define _SUBSCRIBER_HPP_

class Subscriber
{
public:
    ~Subscriber() {std::cout<< "deleting subscriber..." << std::endl; }
    virtual void update() = 0;
    virtual std::string getUser() = 0;

protected:
    Subscriber() {}
};

#endif