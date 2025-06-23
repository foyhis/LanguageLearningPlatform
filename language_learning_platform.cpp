
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include "header_language.hpp"

std::string toLower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return result;
}

bool equalsIgnoreCase(const std::string& a, const std::string& b) {
    return toLower(a) == toLower(b);
}



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
    void keyboardInfo() const override {
        std::cout << "Special keyboard needed: Yes, Georgian Mkhedruli alphabet keyboard.\n";
    }

    std::string generateExercise(int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return "Translate 'Good morning' to Georgian:";
                    case 1: return "\nTranslate 'Thanks' to Georgian:";
                    case 2: return "\nTranslate 'Goodbye' to Georgian:";
                    default: return "";
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return "Write the Georgian word for 'water':";
                    case 1: return "\nTranslate 'friend' to Georgian:";
                    case 2: return "\nWrite the Georgian word for 'love':";
                    default: return "";
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return "Translate: 'I am learning Georgian'";
                    case 1: return "\nTranslate: 'This is my friend'";
                    case 2: return "\nTranslate: 'Georgia is a beautiful country'";
                    default: return "";
            }
            break;
        }
        return "";
    }

    bool checkAnswer(const std::string& userAnswer, int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "დილა მშვიდობისა") || equalsIgnoreCase(userAnswer, "dila mshvidobisa");
                    case 1: return equalsIgnoreCase(userAnswer, "მადლობა") || equalsIgnoreCase(userAnswer, "madloba");
                    case 2: return equalsIgnoreCase(userAnswer, "ნახვამდის") || equalsIgnoreCase(userAnswer, "nakhvamdis");
                    default: return false;
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "წყალი") || equalsIgnoreCase(userAnswer, "tsqali");
                    case 1: return equalsIgnoreCase(userAnswer, "მეგობარი") || equalsIgnoreCase(userAnswer, "megobari");
                    case 2: return equalsIgnoreCase(userAnswer, "სიყვარული") || equalsIgnoreCase(userAnswer, "siqvaruli");
                    default: return false;
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "მე ვსწავლობ ქართულს") || equalsIgnoreCase(userAnswer, "me vstskhov karthuls");
                    case 1: return equalsIgnoreCase(userAnswer, "ეს არის ჩემი მეგობარი") || equalsIgnoreCase(userAnswer, "es aris chemi megobari");
                    case 2: return equalsIgnoreCase(userAnswer, "საქართველო ლამაზი ქვეყანაა") || equalsIgnoreCase(userAnswer, "sakartvelo lamazi kveqana");
                    default: return false;
            }
            break;
        }
        return false;
    }

    int getExerciseCount(Level level) const override {
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
    void keyboardInfo() const override {
        std::cout << "Special keyboard needed: No, uses standard Latin alphabet with some additional letters available on Turkish keyboard layout.\n";
    }

    std::string generateExercise(int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return "Translate 'Good morning' to Turkish:";
                    case 1: return "\nTranslate 'Thanks' to Turkish:";
                    case 2: return "\nTranslate 'Goodbye' to Turkish:";
                    default: return "";
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return "Conjugate the verb 'to go' for 'I go' in Turkish:";
                    case 1: return "\nWrite the Turkish word for 'friend':";
                    case 2: return "\nWrite the Turkish word for 'water':";
                    default: return "";
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return "Translate 'I am learning Turkish' to Turkish:";
                    case 1: return "\nTranslate 'This is my friend' to Turkish:";
                    case 2: return "\nTranslate 'Turkey is a beautiful country' to Turkish:";
                    default: return "";
            }
            break;
        }
    }

    bool checkAnswer(const std::string& userAnswer, int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "günaydın") || equalsIgnoreCase(userAnswer, "gunaydin");
                    case 1: return equalsIgnoreCase(userAnswer, "teşekkür ederim") || equalsIgnoreCase(userAnswer, "tesekkur ederim");
                    case 2: return equalsIgnoreCase(userAnswer, "hoşça kal") || equalsIgnoreCase(userAnswer, "hosca kal");
                    default: return false;
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "gidiyorum");
                    case 1: return equalsIgnoreCase(userAnswer, "arkadaş") || equalsIgnoreCase(userAnswer, "arkadas");
                    case 2: return equalsIgnoreCase(userAnswer, "su");
                    default: return false;
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "Türkçe öğreniyorum") || equalsIgnoreCase(userAnswer, "Turkce ogreniyorum");
                    case 1: return equalsIgnoreCase(userAnswer, "Bu benim arkadaşım") || equalsIgnoreCase(userAnswer, "Bu benim arkadasim");
                    case 2: return equalsIgnoreCase(userAnswer, "Türkiye güzel bir ülke") || equalsIgnoreCase(userAnswer, "Turkiye guzel bir ulke");
                    default: return false;
            }
            break;
        }
    }

    int getExerciseCount(Level level) const override {
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
    void keyboardInfo() const override {
        std::cout << "Special keyboard needed: Yes, Chinese input method editor (IME) is required for typing characters.\n";
    }

    std::string generateExercise(int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return "Translate 'Good morning' to Chinese:";
                    case 1: return "\nTranslate 'Thanks' to Chinese:";
                    case 2: return "\nTranslate 'Goodbye' to Chinese:";
                    default: return "";
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return "Write the character for 'water':";
                    case 1: return "\nWrite the character for 'friend':";
                    case 2: return "\nWrite the character for 'love':";
                    default: return "";
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return "Translate: 'I am learning Chinese'";
                    case 1: return "\nTranslate: 'This is my friend'";
                    case 2: return "\nTranslate: 'China is a beautiful country'";
                    default: return "";
            }
            break;
        }
    }

    bool checkAnswer(const std::string& userAnswer, int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "早上好") || equalsIgnoreCase(userAnswer, "zaoshang hao");
                    case 1: return equalsIgnoreCase(userAnswer, "谢谢") || equalsIgnoreCase(userAnswer, "xie xie");
                    case 2: return equalsIgnoreCase(userAnswer, "再见") || equalsIgnoreCase(userAnswer, "zai jian");
                    default: return false;
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "水") || equalsIgnoreCase(userAnswer, "shui");
                    case 1: return equalsIgnoreCase(userAnswer, "朋友") || equalsIgnoreCase(userAnswer, "pengyou");
                    case 2: return equalsIgnoreCase(userAnswer, "爱") || equalsIgnoreCase(userAnswer, "ai");
                    default: return false;
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "我正在学中文") || equalsIgnoreCase(userAnswer, "wo zhengzai xue zhongwen");
                    case 1: return equalsIgnoreCase(userAnswer, "这是我的朋友") || equalsIgnoreCase(userAnswer, "zhe shi wo de pengyou");
                    case 2: return equalsIgnoreCase(userAnswer, "中国是一个美丽的国家") || equalsIgnoreCase(userAnswer, "zhongguo shi yi ge meili de guojia");
                    default: return false;
            }
            break;
        }
    }

    int getExerciseCount(Level level) const override {
        return 3;
    }
};

class Dutch : public Language {
public:
    void sayHello() const override {
        std::cout << "Hello: Hallo!\n";
    }
    void characteristic() const override {
        std::cout << "Dutch is a Germanic language with some unique vowels and consonants.\n";
    }
    void preparatoryTask() const override {
        std::cout << "Learn common greetings: Hallo, Goedemorgen, Bedankt.\n";
    }
    void keyboardInfo() const override {
        std::cout << "Special keyboard needed: No, uses standard Latin alphabet.\n";
    }

    std::string generateExercise(int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return "Translate 'Good morning' to Dutch:";
                    case 1: return "\nTranslate 'Thanks' to Dutch:";
                    case 2: return "\nTranslate 'Goodbye' to Dutch:";
                    default: return "";
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return "Write the Dutch word for 'water':";
                    case 1: return "\nWrite the Dutch word for 'friend':";
                    case 2: return "\nWrite the Dutch word for 'love':";
                    default: return "";
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return "Translate: 'I am learning Dutch'";
                    case 1: return "\nTranslate: 'This is my friend'";
                    case 2: return "\nTranslate: 'The Netherlands is a beautiful country'";
                    default: return "";
            }
            break;
        }
    }

    bool checkAnswer(const std::string& userAnswer, int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "goedemorgen");
                    case 1: return equalsIgnoreCase(userAnswer, "bedankt") || equalsIgnoreCase(userAnswer, "dank je");
                    case 2: return equalsIgnoreCase(userAnswer, "tot ziens") || equalsIgnoreCase(userAnswer, "dag");
                    default: return false;
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "water");
                    case 1: return equalsIgnoreCase(userAnswer, "vriend");
                    case 2: return equalsIgnoreCase(userAnswer, "liefde");
                    default: return false;
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "ik leer nederlands");
                    case 1: return equalsIgnoreCase(userAnswer, "dit is mijn vriend");
                    case 2: return equalsIgnoreCase(userAnswer, "nederland is een mooi land");
                    default: return false;
            }
            break;
        }
    }

    int getExerciseCount(Level level) const override {
        return 3;
    }
};

class Klingon : public Language {
public:
    void sayHello() const override {
        std::cout << "Hello: nuqneH!\n";
    }
    void characteristic() const override {
        std::cout << "Klingon is a constructed language with guttural sounds and a unique grammar.\n";
    }
    void preparatoryTask() const override {
        std::cout << "Learn basic phrases: nuqneH (hello), Qapla' (success), tlhIngan (Klingon).\n";
    }
    void keyboardInfo() const override {
        std::cout << "Special keyboard needed: No, uses standard Latin alphabet.\n";
    }

    std::string generateExercise(int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return "Translate 'Good morning' to Klingon:";
                    case 1: return "\nTranslate 'Thanks' to Klingon:";
                    case 2: return "\nTranslate 'Goodbye' to Klingon:";
                    default: return "";
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return "Write the Klingon word for 'water':";
                    case 1: return "\nWrite the Klingon word for 'friend':";
                    case 2: return "\nWrite the Klingon word for 'honor':";
                    default: return "";
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return "Translate: 'I am learning Klingon'";
                    case 1: return "\nTranslate: 'This is my friend'";
                    case 2: return "\nTranslate: 'Klingon is a strong language'";
                    default: return "";
            }
            break;
        }
    }

    bool checkAnswer(const std::string& userAnswer, int index, Level level) const override {
        switch(level){
            case Beginner:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "tujqu' po") || equalsIgnoreCase(userAnswer, "tujqu po");
                    case 1: return equalsIgnoreCase(userAnswer, "tlhIngan maH") || equalsIgnoreCase(userAnswer, "tlhingan mah");
                    case 2: return equalsIgnoreCase(userAnswer, "qay'be'") || equalsIgnoreCase(userAnswer, "qaybe");
                    default: return false;
            }
            break;
            case Intermediate:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "bIQ") || equalsIgnoreCase(userAnswer, "biq");
                    case 1: return equalsIgnoreCase(userAnswer, "jup") || equalsIgnoreCase(userAnswer, "jup");
                    case 2: return equalsIgnoreCase(userAnswer, "quv") || equalsIgnoreCase(userAnswer, "quv");
                    default: return false;
            }
            break;
            case Advanced:
                switch(index) {
                    case 0: return equalsIgnoreCase(userAnswer, "tlhIngan Hol vIghoj") || equalsIgnoreCase(userAnswer, "tlhingan hol vighoj");
                    case 1: return equalsIgnoreCase(userAnswer, "jupwI' 'oH") || equalsIgnoreCase(userAnswer, "jupwi oh");
                    case 2: return equalsIgnoreCase(userAnswer, "tlhIngan Hol 'aD") || equalsIgnoreCase(userAnswer, "tlhingan hol ad");
                    default: return false;
            }
            break;
        }
    }

    int getExerciseCount(Level level) const override {
        return 3;
    }
};
#ifndef TESTS
int main() {
    std::ofstream resultsFile("language_learning_results.txt", std::ios::app);
    if (!resultsFile.is_open()) {
        std::cout << "Error: Could not open results file.\n";
        return 1;
    }

    std::cout << "Choose a language:\n1. Georgian\n2. Turkish\n3. Chinese\n4. Dutch\n5. Klingon\n";
    int langChoice;
    std::cin >> langChoice;
    std::cin.ignore();

    std::string langName;
    switch(langChoice) {
        case 1: langName = "Georgian"; break;
        case 2: langName = "Turkish"; break;
        case 3: langName = "Chinese"; break;
        case 4: langName = "Dutch"; break;
        case 5: langName = "Klingon"; break;
        default: langName = "Unknown";
    }

    std::cout << "Choose level:\n1. Beginner\n2. Intermediate\n3. Advanced\n";
    int levelChoiceInt;
    std::cin >> levelChoiceInt;
    std::cin.ignore();

    Level level = static_cast<Level>(levelChoiceInt);
    std::string levelName;
    switch(level) {
        case Beginner: levelName = "Beginner"; break;
        case Intermediate: levelName = "Intermediate"; break;
        case Advanced: levelName = "Advanced"; break;
        default: levelName = "Unknown";
    }

    Language* lang = nullptr;
    switch(langChoice) {
        case 1: lang = new Georgian(); break;
        case 2: lang = new Turkish(); break;
        case 3: lang = new Chinese(); break;
        case 4: lang = new Dutch(); break;
        case 5: lang = new Klingon(); break;
        default:
            std::cout << "Invalid language choice.\n";
            resultsFile.close();
            return 1;
    }

    std::cout << "\n---< Language Introduction >---\n";
    lang->characteristic();
    lang->keyboardInfo();
    std::cout <<std::endl;
    lang->sayHello();
    lang->preparatoryTask();

    std::cout << "\n\n---< Exercises >---\n";
    int count = lang->getExerciseCount(level);
    std::vector<std::string> answers(count);
    int correctCount = 0;

    for (int i = 0; i < count; ++i) {
        std::string exercise = lang->generateExercise(i, level);
        std::cout << exercise << "\n";
        std::string answer;
        std::getline(std::cin, answer);
        answers[i] = answer;

        bool isCorrect = lang->checkAnswer(answer, i, level);
        if (isCorrect) {
            std::cout << "Correct!\n";
            correctCount++;
        } else {
            std::cout << "Incorrect.\n";
        }
    }

    resultsFile << langName << ", " << levelName << ", Score: " << correctCount << "/" << count;
    for (int i = 0; i < count; ++i) {
        resultsFile << ", Answer " << (i + 1) << ": " << answers[i];
    }
    resultsFile << "\n";

    delete lang;
    resultsFile.close();
    return 0;
}
#endif
