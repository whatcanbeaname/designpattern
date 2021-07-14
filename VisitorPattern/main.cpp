/*
Visitor pattern:
Example:
Customer will subscrib to salers and watch a sale info he advertized.
when the product is not on sale, customer will wait.
when the product is on sale, customer will go to buy it.
*/

#include <iostream>
#include "visitor.hpp"
using namespace  std;

int main()
{
    Publisher* saler = new Saler("KFC");
    Subscriber* A = new Customer("A", "waiting at home", "go to buy", saler);
    Subscriber* B = new Customer("B", "waiting at school", "buy on line", saler);

    saler->addSubscriber(A);
    saler->addSubscriber(B);
    saler->setMsg("not on sale");
    saler->notifySubscriber();
    cout << endl;

    saler->setMsg("on sale");
    saler->notifySubscriber();
    cout << endl;

    saler->removeSubscriber(B);
    saler->setMsg("on sale");
    saler->notifySubscriber();
    cout << endl;

    delete saler;
    delete A;
    delete B;
    return 0;
}
