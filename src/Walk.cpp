#include "FSM.h"
#include "Walk.h"
#include "Run.h"
#include <thread>
#include "keyboard_input.h"
#include "Idle.h"

Walk::Walk(std::string name) : BaseState::BaseState(name)
{
}

void Walk::init(FSM *fsm, void *user_data)
{
    BaseState::init(fsm, user_data);
}

void Walk::enter(FSM *fsm, void *user_data)
{
    BaseState::enter(fsm, user_data);
}

void Walk::update(FSM *fsm, void *user_data)
{
    BaseState::update(fsm, user_data);
    if (input_char.load() == 'r')
    {
        input_char.store(0);
        fsm->change_state<Run>(nullptr);
        return;
    }
    else if (input_char.load() == 'i')
    {
        input_char.store(0);
        fsm->change_state<Idle>(nullptr);
        return;
    }
    else if (input_char.load() == 'w')
    {
        input_char.store(0);
        return;
    }
}

void Walk::leave(FSM *fsm, void *user_data)
{
    BaseState::leave(fsm, user_data);
}
