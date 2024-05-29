#pragma once
#include <iostream>
#include <string>

class FSM;

class BaseState
{
public:
    BaseState(){};
    BaseState(std::string);
    virtual void init(FSM *fsm, void *user_data);
    virtual void enter(FSM *fsm, void *user_data);
    virtual void update(FSM *fsm, void *user_data);
    virtual void leave(FSM *fsm, void *user_data);
    bool initialized_;
    std::string get_name() { return name_; }

private:
    std::string name_;
};

struct UD
{
    char *data;
};