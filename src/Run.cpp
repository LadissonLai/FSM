#include "Run.h"
#include "Idle.h"
#include "FSM.h"
#include "keyboard_input.h"
#include <thread>
#include "Walk.h"

Run::Run(std::string name) : BaseState::BaseState(name)
{
}

void Run::init(FSM *fsm, void *user_data)
{
    BaseState::init(fsm, user_data);
}

void Run::enter(FSM *fsm, void *user_data)
{
    BaseState::enter(fsm, user_data);
}

void Run::update(FSM *fsm, void *user_data)
{
    BaseState::update(fsm, user_data);
    if (input_char.load() == 'r')
    {
        input_char.store(0);
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
        fsm->change_state<Walk>(nullptr);
        return;
    }
}

void Run::leave(FSM *fsm, void *user_data)
{
    BaseState::leave(fsm, user_data);
}