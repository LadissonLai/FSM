#pragma once
#include "BaseState.h"

class Walk : public BaseState
{
public:
    Walk(std::string name);
    void init(FSM *fsm, void *user_data) override;
    void enter(FSM *fsm, void *user_data) override;
    void update(FSM *fsm, void *user_data) override;
    void leave(FSM *fsm, void *user_data) override;
};