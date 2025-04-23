#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << &b1;

        b1.incrementGrade();
        std::cout << &b1;

        // Ici ça va throw une exception (trop haut)
        b1.incrementGrade();
        std::cout << &b1;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----------------------" << std::endl;

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << &b2;

        b2.decrementGrade();
        std::cout << &b2;

        // Ici ça va throw une exception (trop bas)
        b2.decrementGrade();
        std::cout << b2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----------------------" << std::endl;

    try {
        Bureaucrat b3("Charlie", 0); // Va throw directement à la construction
    }
    catch (std::exception &e) {
        std::cout << "Exception caught at creation: " << e.what() << std::endl;
    }

    return 0;
}

