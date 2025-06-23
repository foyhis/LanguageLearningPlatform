#pragma once
#include <string>

enum Level {
    Beginner = 1,
    Intermediate,
    Advanced
};

class Language {
public:
    virtual ~Language() {}

    virtual void sayHello() const = 0;
    virtual void characteristic() const = 0;
    virtual void preparatoryTask() const = 0;
    virtual std::string generateExercise(int index, Level level) const = 0;
    virtual bool checkAnswer(const std::string& userAnswer, int index, Level level) const = 0;
    virtual int getExerciseCount(Level level) const = 0;
    virtual void keyboardInfo() const = 0;
};
