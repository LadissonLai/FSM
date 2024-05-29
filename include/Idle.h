#pragma once
#include "BaseState.h"

class Idle : public BaseState
{
public:
    Idle(std::string name);
    void init(FSM *fsm, void *user_data) override;
    void enter(FSM *fsm, void *user_data) override;
    void update(FSM *fsm, void *user_data) override;
    void leave(FSM *fsm, void *user_data) override;
};