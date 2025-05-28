#include <iostream>
#include <string>

class Language {
public:
    virtual ~Language() {}

    virtual void sayHello() const = 0;
    virtual void characteristic() const = 0;
    virtual void preparatoryTask() const = 0;
    virtual std::string generateExercise() const = 0;
    virtual bool checkAnswer(const std::string& userAnswer) const = 0;
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

    bool checkAnswer(const std::string& userAnswer) const override {
        return (userAnswer == "günaydın" || userAnswer == "gunaydin");
    }
};


class Georgian : public Language {
public:
    void sayHello() const override {
        std::cout << "Hello: გამარჯობა! (Gamajoba!)\n";
    }

    void characteristic() const override {
        std::cout << "Georgian uses its unique Mkhedruli alphabet.\n";
    }

    void preparatoryTask() const override {
        std::cout << "Learn these letters: ა (a), ბ (b), გ (g), დ (d), ე (e).\n";
    }

    std::string generateExercise() const override {
        return "Translate 'Thanks' to Georgian:";
    }

    bool checkAnswer(const std::string& userAnswer) const override {
        return (userAnswer == "მადლობა" || userAnswer == "madloba");
    }
};

int main() {
    std::cout << "Choose a language:\n1. Turkish\n2. Georgian\n";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    Language* lang = nullptr;

    if (choice == 1) {
        lang = new Turkish();
    } else if (choice == 2) {
        lang = new Georgian();
    } else {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    std::cout << "\n--- Language Introduction ---\n";
    lang->sayHello();
    lang->characteristic();
    lang->preparatoryTask();

    std::cout << "\n--- Exercise ---\n";
    std::cout << lang->generateExercise() << "\n";

    std::string answer;
    std::getline(std::cin, answer);

    if (lang->checkAnswer(answer)) {
        std::cout << "Correct!\n";
    } else {
        std::cout << "Incorrect.\n";
    }

    delete lang;
    return 0;
}
