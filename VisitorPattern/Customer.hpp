#include <iostream>

class Publisher;
class Subscriber;

class Customer : public Subscriber
{
public:
    Customer(std::string user, std::string doing, std::string todo, Publisher* publisher)
    : _user(user), _doing(doing), _todo(todo), _publisher(publisher) {}
    ~Customer() {}
    void update() override
    {
        std::string msg = _publisher->getMsg();
        if (msg == "on sale")
        {
            std::cout << _user << " will " << _todo << std::endl;
        }
        else
        {
            std::cout << _user << " keeps " << _doing << std::endl;
        }
    }
    std::string getUser() { return _user; }

private:
    std::string _user;
    std::string _doing;
    std::string _todo;
    Publisher* _publisher;
};