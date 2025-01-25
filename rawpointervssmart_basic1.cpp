#include <iostream>
#include <memory> 

class Resource {
    public:
    Resource() { std::cout << "called const\n"; }
    ~ Resource() { std::cout << "called dest\n"; }
    void sayHello() {
        std::cout << "Hello from Resource\n";
    }
};
//////////////////////////////// Raw pointer /////////////////////////////////////////////
// int main() {
//     std::cout << "\n***************************OUTPUT************************************\n";
//     Resource* obj1 = new Resource();
//     obj1->sayHello();
//     delete obj1;
//     return 0;
// }

//////////////////////////////// Unique pointer /////////////////////////////////////////////
int main() {
    std::cout << "\n***************************OUTPUT************************************\n";
    std::unique_ptr<Resource> res = std::make_unique<Resource>();
    res->sayHello();
    return 0;
}
