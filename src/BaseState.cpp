#include "BaseState.h"

BaseState::BaseState(std::string name) : name_(name) {}

void BaseState::init(FSM *fsm, void *user_data)
{
    this->initialized_ = true;
    std::cout << "init " << this->name_ << std::endl;
}

void BaseState::enter(FSM *fsm, void *user_data)
{
    std::cout << "---enter " << this->name_ << std::endl;
}

void BaseState::update(FSM *fsm, void *user_data)
{
    std::cout << "update " << this->name_ << std::endl;
}

void BaseState::leave(FSM *fsm, void *user_data)
{
    std::cout << "---leave " << this->name_ << std::endl;
}