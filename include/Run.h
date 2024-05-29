#pragma once
#include "BaseState.h"

class Run : public BaseState
{
public:
    Run(std::string name);
    void init(FSM *fsm, void *user_data) override;
    void enter(FSM *fsm, void *user_data) override;
    void update(FSM *fsm, void *user_data) override;
    void leave(FSM *fsm, void *user_data) override;
};