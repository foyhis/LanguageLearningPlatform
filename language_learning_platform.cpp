#include <iostream>
#include <string>

class Language {
public:
    virtual ~Language() {}
    virtual void sayHello() const = 0;
    virtual void characteristic() const = 0;
    virtual void preparatoryTask() const = 0;
    virtual std::string generateExercise() const = 0;
};

class Turkish : public Language {
public:
    void sayHello() const override {
        std::cout << "Hello: Merhaba!\n";
    }

    void characteristic() const override {
        std::cout << "Turkish uses the Latin alphabet and has vowel harmony.\n";
    }

    void preparatoryTask() const override {
        std::cout << "Learn special letters: ç, ğ, ı, ö, ş.\n";
    }

    std::string generateExercise() const override {
        return "Translate 'Good morning' to Turkish:";
    }
};

int main() {
    Turkish turkish;

    turkish.sayHello();
    turkish.characteristic();
    turkish.preparatoryTask();

    std::cout << "\n--- Exercise ---\n";
    std::cout << turkish.generateExercise() << "\n";

    std::string answer;
    std::getline(std::cin, answer);

    std::cout << "Your answer: " << answer << "\n";
    std::cout << "Thanks for trying!\n";

    return 0;
}
