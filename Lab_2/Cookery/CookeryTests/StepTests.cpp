#include <gtest/gtest.h>
#include <memory>
#include <sstream>
#include <iostream>
#include <string>
#include "D:\Projects\Cookery\Cookery\Step.h"
#include "D:\Projects\Cookery\Cookery\RecipeSteps.h"
#include "D:\Projects\Cookery\Cookery\ConsolePrinterStep.h"

using namespace std;


TEST(StepTest, ConstructorSetsValues) {
    Step step("Chop vegetables", 10);
    EXPECT_EQ(step.getAction(), "Chop vegetables");
    EXPECT_EQ(step.getTime(), 10);
}

TEST(StepTest, ActionCanBeEmpty) {
    Step step("", 5);
    EXPECT_EQ(step.getAction(), "");
    EXPECT_EQ(step.getTime(), 5);
}

TEST(StepTest, TimeCanBeZero) {
    Step step("Wait", 0);
    EXPECT_EQ(step.getTime(), 0);
}

TEST(StepTest, StepWithLongAction) {
    string longAction(1000, 'x');
    Step step(longAction, 5);
    EXPECT_EQ(step.getAction().size(), 1000);
    EXPECT_EQ(step.getTime(), 5);
}

TEST(StepTest, StepWithSpecialCharacters) {
    Step step("Chop & fry @ 180°C", 8);
    ConsolePrinterStep printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    printer.print(step);

    cout.rdbuf(oldCout);
    string output = buffer.str();

    EXPECT_NE(output.find("Chop & fry @ 180°C"), string::npos);
}


TEST(RecipeStepsTest, AddStepIncreasesStepsSize) {
    RecipeSteps recipe;
    recipe.addStep(make_unique<Step>("Boil water", 5));

    EXPECT_EQ(recipe.getSteps().size(), 1);
    EXPECT_EQ(recipe.getSteps()[0]->getAction(), "Boil water");
}

TEST(RecipeStepsTest, TotalTimeIsCorrect) {
    RecipeSteps recipe;
    recipe.addStep(make_unique<Step>("Boil water", 5));
    recipe.addStep(make_unique<Step>("Chop vegetables", 10));

    EXPECT_EQ(recipe.getTotalTime(), 15);
}

TEST(RecipeStepsTest, TotalTimeWithNoStepsIsZero) {
    RecipeSteps recipe;
    EXPECT_EQ(recipe.getTotalTime(), 0);
}

TEST(RecipeStepsTest, StepsVectorIsConstCorrectly) {
    RecipeSteps recipe;
    recipe.addStep(make_unique<Step>("Mix ingredients", 7));

    const auto& steps = recipe.getSteps();
    EXPECT_EQ(steps.size(), 1);
    EXPECT_EQ(steps[0]->getAction(), "Mix ingredients");
}

TEST(RecipeStepsTest, AddMultipleStepsAndCheckTotalTime) {
    RecipeSteps recipe;
    recipe.addStep(make_unique<Step>("Step1", 1));
    recipe.addStep(make_unique<Step>("Step2", 2));
    recipe.addStep(make_unique<Step>("Step3", 3));

    EXPECT_EQ(recipe.getTotalTime(), 6);
}

TEST(RecipeStepsTest, StepsWithZeroTimeAreCounted) {
    RecipeSteps recipe;
    recipe.addStep(make_unique<Step>("Step1", 0));
    recipe.addStep(make_unique<Step>("Step2", 0));

    EXPECT_EQ(recipe.getTotalTime(), 0);
}

TEST(RecipeStepsTest, TotalTimeWithManySteps) {
    RecipeSteps recipe;
    int sum = 0;
    for (int i = 1; i <= 10; ++i) {
        recipe.addStep(make_unique<Step>("Step" + to_string(i), i));
        sum += i;
    }
    EXPECT_EQ(recipe.getTotalTime(), sum);
}


TEST(ConsolePrinterStepTest, PrintSingleStepOutputsCorrectText) {
    Step step("Bake cake", 30);
    ConsolePrinterStep printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    printer.print(step);

    cout.rdbuf(oldCout);
    string output = buffer.str();

    EXPECT_NE(output.find("Step:"), string::npos);
    EXPECT_NE(output.find("Action: Bake cake"), string::npos);
    EXPECT_NE(output.find("Time: 30 min"), string::npos);
}

TEST(ConsolePrinterStepTest, PrintRecipeOutputsAllStepsAndTotalTime) {
    RecipeSteps recipe;
    recipe.addStep(make_unique<Step>("Boil water", 5));
    recipe.addStep(make_unique<Step>("Add pasta", 10));

    ConsolePrinterStep printer;
    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    printer.print(recipe);

    cout.rdbuf(oldCout);
    string output = buffer.str();

    EXPECT_NE(output.find("All steps:"), string::npos);
    EXPECT_NE(output.find("Action: Boil water"), string::npos);
    EXPECT_NE(output.find("Action: Add pasta"), string::npos);
    EXPECT_NE(output.find("Total time: 15 min"), string::npos);
}

TEST(ConsolePrinterStepTest, PrintEmptyRecipeShowsTotalTimeZero) {
    RecipeSteps recipe;
    ConsolePrinterStep printer;

    stringstream buffer;
    streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

    printer.print(recipe);

    cout.rdbuf(oldCout);
    string output = buffer.str();
    EXPECT_NE(output.find("Total time: 0 min"), string::npos);
}
