#include <iostream>
#include <string>
#include <vector>

class Language {
public:
    virtual ~Language() {}

    virtual void sayHello() const = 0;
    virtual void characteristic() const = 0;
    virtual void preparatoryTask() const = 0;
    virtual std::string generateExercise(int index) const = 0;
    virtual bool checkAnswer(const std::string& userAnswer, int index) const = 0;
    virtual int getExerciseCount() const = 0;
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

    std::string generateExercise(int index) const override {
        switch (index) {
            case 0: return "Translate 'Good morning' to Georgian:";
            case 1: return "Translate 'Thanks' to Georgian:";
            case 2: return "Translate 'Goodbye' to Georgian:";
        }
        return "";
    }

    bool checkAnswer(const std::string& userAnswer, int index) const override {
        switch (index) {
            case 0: return userAnswer == "დილა მშვიდობისა" || userAnswer == "dila mshvidobisa";
            case 1: return userAnswer == "მადლობა" || userAnswer == "madloba";
            case 2: return userAnswer == "ნახვამდის" || userAnswer == "nakhvamdis";
        }
        return false;
    }

    int getExerciseCount() const override {
        return 3;
    }
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

    std::string generateExercise(int index) const override {
        switch (index) {
            case 0: return "Translate 'Good morning' to Turkish:";
            case 1: return "Translate 'Thanks' to Turkish:";
            case 2: return "Translate 'Goodbye' to Turkish:";
        }
        return "";
    }

    bool checkAnswer(const std::string& userAnswer, int index) const override {
        switch (index) {
            case 0: return userAnswer == "günaydın" || userAnswer == "gunaydin";
            case 1: return userAnswer == "teşekkür ederim" || userAnswer == "tesekkur ederim";
            case 2: return userAnswer == "hoşça kal" || userAnswer == "hosca kal";
        }
        return false;
    }

    int getExerciseCount() const override {
        return 3;
    }
};


class Chinese : public Language {
public:
    void sayHello() const override {
        std::cout << "Hello: 你好! (Nǐ hǎo!)\n";
    }

    void characteristic() const override {
        std::cout << "Chinese uses characters and is a tonal language.\n";
    }

    void preparatoryTask() const override {
        std::cout << "Learn basic characters: 你 (you), 好 (good), 是 (is), 谢谢 (thank you).\n";
    }

    std::string generateExercise(int index) const override {
        switch (index) {
            case 0: return "Translate 'Good morning' to Chinese:";
            case 1: return "Translate 'Thanks' to Chinese:";
            case 2: return "Translate 'Goodbye' to Chinese:";
        }
        return "";
    }

    bool checkAnswer(const std::string& userAnswer, int index) const override {
        switch (index) {
            case 0: return userAnswer == "早上好" || userAnswer == "zaoshang hao";
            case 1: return userAnswer == "谢谢" || userAnswer == "xie xie";
            case 2: return userAnswer == "再见" || userAnswer == "zai jian";
        }
        return false;
    }

    int getExerciseCount() const override {
        return 3;
    }
};

class Dutch : public Language {
public:
    void sayHello() const override {
        std::cout << "Hello: Hallo!\n";
    }

    void characteristic() const override {
        std::cout << "Dutch is a West Germanic language with many loanwords.\n";
    }

    void preparatoryTask() const override {
        std::cout << "Learn basic words: ja (yes), nee (no), dank je (thanks).\n";
    }

    std::string generateExercise(int index) const override {
        switch (index) {
            case 0: return "Translate 'Good morning' to Dutch:";
            case 1: return "Translate 'Thanks' to Dutch:";
            case 2: return "Translate 'Goodbye' to Dutch:";
        }
        return "";
    }

    bool checkAnswer(const std::string& userAnswer, int index) const override {
        switch (index) {
            case 0: return userAnswer == "goedemorgen";
            case 1: return userAnswer == "dank je" || userAnswer == "dankjewel";
            case 2: return userAnswer == "tot ziens";
        }
        return false;
    }

    int getExerciseCount() const override {
        return 3;
    }
};

int main() {
    std::cout << "Choose a language:\n1. Georgian\n2. Turkish\n3. Chinese\n4. Dutch\n";
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    Language* lang = nullptr;

    if (choice == 1) {
        lang = new Georgian();
    } else if (choice == 2) {
        lang = new Turkish();
    } else if (choice == 3) {
        lang = new Chinese();
    } else if (choice == 4) {
        lang = new Dutch();
    } else {
        std::cout << "Invalid choice.\n";
        return 1;
    }

    std::cout << "\n--- Language Introduction ---\n";
    lang->sayHello();
    lang->characteristic();
    lang->preparatoryTask();

    std::cout << "\n--- Exercises ---\n";
    for (int i = 0; i < lang->getExerciseCount(); ++i) {
        std::cout << lang->generateExercise(i) << "\n";
        std::string answer;
        std::getline(std::cin, answer);

        if (lang->checkAnswer(answer, i)) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "Incorrect.\n";
        }
    }

    delete lang;
    return 0;
}
