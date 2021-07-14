#include <iostream>
#include <list>
#include <string>
using namespace std;

class Subscriber
{
public:
    ~Subscriber() {}
    virtual void update() = 0;
    virtual string getUser() = 0;

protected:
    Subscriber() {}
};

class Publisher
{
public:
    ~Publisher() {}
    void addSubscriber(Subscriber* s)
    {
        cout << "new subscriber: " << s->getUser() << endl;
        _subscribers.push_back(s);
    }
    void removeSubscriber(Subscriber* s)
    {
        cout << s->getUser() << " cancelled subscribe!" << endl;
        _subscribers.remove(s);
    }
    void notifySubscriber()
    {
        list<Subscriber*>::iterator iter = _subscribers.begin();
        for (; iter != _subscribers.end(); iter++)
        {
            (*iter)->update();
        }
    }
    virtual void setMsg(string msg) { _msg = msg; }
    virtual string getMsg() { return _msg; }

protected:
    Publisher() {}
    string _msg;

private:
    list<Subscriber*> _subscribers;
};

class Customer : public Subscriber
{
public:
    Customer(string user, string doing, string todo, Publisher* publisher)
    : _user(user), _doing(doing), _todo(todo), _publisher(publisher) {}
    ~Customer() {}
    void update() override
    {
        string msg = _publisher->getMsg();
        if (msg == "on sale")
        {
            cout << _user << " will " << _todo << endl;
        }
        else
        {
            cout << _user << " keeps " << _doing << endl;
        }
    }
    string getUser() { return _user; }

private:
    string _user;
    string _doing;
    string _todo;
    Publisher* _publisher;
};

class Saler : public Publisher
{
public:
    Saler(string saler) : _saler(saler) {}
    ~Saler() {}
    void setMsg(string msg)
    {
        _msg = msg;
        cout << "saler " << _saler << " promotes a new ad: " << _msg << endl;
    }

private:
    string _saler;
};