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


int main() {
    std::cout << "\n***************************OUTPUT************************************\n";
    std::unique_ptr<Resource> res1 = std::make_unique<Resource>();
    std::unique_ptr<Resource> res2 = res1; //wont compile since copying not allowed
    res1->sayHello();
    return 0;
}
                ======================== ||==================
                =========================\/==================
int main() {
    std::cout << "\n***************************OUTPUT************************************\n";
    std::unique_ptr<Resource> res1 = std::make_unique<Resource>();
    std::unique_ptr<Resource> res2 = std::move(res1); // Ownership transferred

    if (res1) {
        res1->sayHello(); // Safe only if res1 is not null
    } else {
        std::cout << "res1 is null after move!" << std::endl;
    }

    return 0;
}
