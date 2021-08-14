#ifndef _IPUBLISHER_HPP_
#define _IPUBLISHER_HPP_

#include <iostream>
#include <list>
#include "Subscriber.hpp"

class Publisher
{
public:
    ~Publisher() { std::cout << "deleting publisher..." << std::endl; }
    void addSubscriber(Subscriber* s)
    {
        std::cout << "new subscriber: " << s->getUser() << std::endl;
        _subscribers.push_back(s);
    }
    void removeSubscriber(Subscriber* s)
    {
        std::cout << s->getUser() << " cancelled subscribe!" << std::endl;
        _subscribers.remove(s);
    }
    void notifySubscriber()
    {
        std::list<Subscriber*>::iterator iter = _subscribers.begin();
        for (; iter != _subscribers.end(); iter++)
        {
            (*iter)->update();
        }
    }
    virtual void setMsg(std::string msg) { _msg = msg; }
    virtual std::string getMsg() { return _msg; }

protected:
    Publisher() {}
    std::string _msg;

private:
    std::list<Subscriber*> _subscribers;
};

#endif
