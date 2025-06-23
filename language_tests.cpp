
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

#define TESTS
#include "language_learning_platform.cpp"


struct LanguageTestCase {
    Language* language;
    std::string name;
    std::map<Level, std::vector<std::string>> testAnswers;
    std::map<Level, std::vector<std::set<std::string>>> correctAnswers;
};


std::string setToString(const std::set<std::string>& s) {
    std::string result = "{ ";
    for (auto it = s.begin(); it != s.end(); ++it) {
        result += "\"" + *it + "\"";
        if (std::next(it) != s.end()) result += ", ";
    }
    return result + " }";
}


void testLanguage(const LanguageTestCase& testCase) {
    std::cout << "=== Testing: " << testCase.name << " ===\n";


    for (const auto& levelPair : testCase.testAnswers) {
        Level level = levelPair.first;
        const std::vector<std::string>& testAnswers = levelPair.second;
        const std::vector<std::set<std::string>>& correctAnswers = testCase.correctAnswers.at(level);

        std::cout << "Level " << level << ":\n";

        for (size_t i = 0; i < testAnswers.size(); ++i) {

            int exerciseIndex = i % testCase.language->getExerciseCount(level);
            std::string question = testCase.language->generateExercise(exerciseIndex, level);
            std::cout << "Q" << exerciseIndex + 1 << ": " << question << "\n";

            const std::string& answer = testAnswers[i];
            const std::set<std::string>& expectedCorrect = correctAnswers[exerciseIndex];


            bool result = testCase.language->checkAnswer(answer, exerciseIndex, level);

            bool isCorrectAnswer = expectedCorrect.count(answer) > 0;


            bool testPassed = (result == isCorrectAnswer);

            std::cout << "Answer: \"" << answer << "\" -> "
                      << (testPassed ? "PASS" : "FAIL")
                      << " (Expected: " << (isCorrectAnswer ? "Correct" : "Incorrect")
                      << ", Correct Answers: " << setToString(expectedCorrect) << ")\n";

            std::cout << std::endl;
        }
    }
}

int main() {
    Georgian georgian;
    Turkish turkish;
    Chinese chinese;
    Dutch dutch;
    Klingon klingon;

    std::vector<LanguageTestCase> testCases = {
        {
            &georgian, "Georgian",
            {
                { Beginner, {
                    "dila mshvidobisa", "madloba", "nakhvamdis", // Correct
                    "hello", "thank you", "goodbye"              // Incorrect
                }},
                { Intermediate, {
                    "tsqali", "megobari", "siqvaruli",           // Correct
                    "water", "friend", "love"                    // Incorrect
                }},
                { Advanced, {
                    "me vstskhov karthuls", "es aris chemi megobari", "sakartvelo lamazi kveqana", // Correct
                    "I learn Georgian", "This is friend", "Georgia is nice"                        // Incorrect
                }}
            },
            {
                { Beginner, {
                    {"დილა მშვიდობისა", "dila mshvidobisa"}, // Q1
                    {"მადლობა", "madloba"},                  // Q2
                    {"ნახვამდის", "nakhvamdis"}              // Q3
                }},
                { Intermediate, {
                    {"წყალი", "tsqali"},                     // Q1
                    {"მეგობარი", "megobari"},                // Q2
                    {"სიყვარული", "siqvaruli"}               // Q3
                }},
                { Advanced, {
                    {"მე ვსწავლობ ქართულს", "me vstskhov karthuls"},           // Q1
                    {"ეს არის ჩემი მეგობარი", "es aris chemi megobari"},       // Q2
                    {"საქართველო ლამაზი ქვეყანაა", "sakartvelo lamazi kveqana"} // Q3
                }}
            }
        },
        {
            &turkish, "Turkish",
            {
                { Beginner, {
                    "gunaydin", "tesekkur ederim", "hosca kal", // Correct
                    "merhaba", "thanks", "bye"                  // Incorrect
                }},
                { Intermediate, {
                    "gidiyorum", "arkadas", "su",               // Correct
                    "go", "friend", "water"                     // Incorrect
                }},
                { Advanced, {
                    "Turkce ogreniyorum", "Bu benim arkadasim", "Turkiye guzel bir ulke", // Correct
                    "I learn Turkish", "This is my friend", "Turkey is nice"              // Incorrect
                }}
            },
            {
                { Beginner, {
                    {"günaydın", "gunaydin"},                   // Q1
                    {"teşekkür ederim", "tesekkur ederim"},     // Q2
                    {"hoşça kal", "hosca kal"}                  // Q3
                }},
                { Intermediate, {
                    {"gidiyorum"},                              // Q1
                    {"arkadaş", "arkadas"},                     // Q2
                    {"su"}                                      // Q3
                }},
                { Advanced, {
                    {"Türkçe öğreniyorum", "Turkce ogreniyorum"},           // Q1
                    {"Bu benim arkadaşım", "Bu benim arkadasim"},           // Q2
                    {"Türkiye güzel bir ülke", "Turkiye guzel bir ulke"}    // Q3
                }}
            }
        },
        {
            &chinese, "Chinese",
            {
                { Beginner, {
                    "zaoshang hao", "xie xie", "zai jian",      // Correct
                    "ni hao", "thanks", "goodbye"               // Incorrect
                }},
                { Intermediate, {
                    "shui", "pengyou", "ai",                    // Correct
                    "water", "friend", "love"                   // Incorrect
                }},
                { Advanced, {
                    "wo zhengzai xue zhongwen", "zhe shi wo de pengyou", "zhongguo shi yi ge meili de guojia", // Correct
                    "I learn Chinese", "This is my friend", "China is nice"                                    // Incorrect
                }}
            },
            {
                { Beginner, {
                    {"早上好", "zaoshang hao"},                 // Q1
                    {"谢谢", "xie xie"},                        // Q2
                    {"再见", "zai jian"}                        // Q3
                }},
                { Intermediate, {
                    {"水", "shui"},                             // Q1
                    {"朋友", "pengyou"},                        // Q2
                    {"爱", "ai"}                                // Q3
                }},
                { Advanced, {
                    {"我正在学中文", "wo zhengzai xue zhongwen"},           // Q1
                    {"这是我的朋友", "zhe shi wo de pengyou"},              // Q2
                    {"中国是一个美丽的国家", "zhongguo shi yi ge meili de guojia"} // Q3
                }}
            }
        },
        {
            &dutch, "Dutch",
            {
                { Beginner, {
                    "goedemorgen", "bedankt", "tot ziens",      // Correct
                    "hallo", "thanks", "bye"                    // Incorrect
                }},
                { Intermediate, {
                    "water", "vriend", "liefde",                // Correct
                    "aqua", "friend", "love"                    // Incorrect
                }},
                { Advanced, {
                    "ik leer nederlands", "dit is mijn vriend", "nederland is een mooi land", // Correct
                    "I learn Dutch", "This is my friend", "Holland is nice"                   // Incorrect
                }}
            },
            {
                { Beginner, {
                    {"goedemorgen"},                            // Q1
                    {"bedankt", "dank je"},                     // Q2
                    {"tot ziens", "dag"}                        // Q3
                }},
                { Intermediate, {
                    {"water"},                                  // Q1
                    {"vriend"},                                 // Q2
                    {"liefde"}                                  // Q3
                }},
                { Advanced, {
                    {"ik leer nederlands"},                     // Q1
                    {"dit is mijn vriend"},                     // Q2
                    {"nederland is een mooi land"}              // Q3
                }}
            }
        },
        {
            &klingon, "Klingon",
            {
                { Beginner, {
                    "tujqu' po", "tlhIngan maH", "qay'be'",     // Correct
                    "nuqneH", "thanks", "goodbye"               // Incorrect
                }},
                { Intermediate, {
                    "bIQ", "jup", "quv",                        // Correct
                    "water", "friend", "honor"                  // Incorrect
                }},
                { Advanced, {
                    "tlhIngan Hol vIghoj", "jupwI' 'oH", "tlhIngan Hol 'aD", // Correct
                    "I learn Klingon", "This is my friend", "Klingon is strong" // Incorrect
                }}
            },
            {
                { Beginner, {
                    {"tujqu' po", "tujqu po"},                  // Q1
                    {"tlhIngan maH", "tlhingan mah"},           // Q2
                    {"qay'be'", "qaybe"}                        // Q3
                }},
                { Intermediate, {
                    {"bIQ", "biq"},                             // Q1
                    {"jup"},                                    // Q2
                    {"quv"}                                     // Q3
                }},
                { Advanced, {
                    {"tlhIngan Hol vIghoj", "tlhingan hol vighoj"}, // Q1
                    {"jupwI' 'oH", "jupwi oh"},                    // Q2
                    {"tlhIngan Hol 'aD", "tlhingan hol ad"}        // Q3
                }}
            }
        }
    };

    for (const auto& testCase : testCases) {
        testLanguage(testCase);
    }

    return 0;
}
