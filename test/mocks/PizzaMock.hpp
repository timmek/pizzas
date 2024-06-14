#include "Pizza.hpp"
#include "gmock/gmock.h"

struct PizzaDummy : public Pizza
{
    PizzaDummy() : Pizza(){
        name_ = "dummy";
        price_ = 0.0;
        bakingTime_ = (minutes)0;
    }
    std::string getName() const override { return "dummy"; }
    double getPrice() const override { return 0.0; }
    minutes getBakingTime() const override { return minutes(0); }
};

struct PizzaStub : public Pizza
{
    PizzaStub(std::string name) : Pizza(){
        name_ = name;
        price_ = 0.0;
        bakingTime_ = (minutes)0;
    }
    std::string getName() const override { return Pizza::getName(); }
    double getPrice() const override
    {
        if (getName() == "stub")
            return 0.0;
        else 
            return 10.0;
    }
    minutes getBakingTime() const override { return minutes(1); }
};

struct PizzaMock : public Pizza
{
    MOCK_METHOD(std::string, getName, (), (const, override));
    MOCK_METHOD(double, getPrice, (), (const, override));
    MOCK_METHOD(minutes, getBakingTime, (), (const, override));
};

