#include "FSM.h"

void FSM::update(void *user_data)
{
    if (curState_)
    {
        curState_->update(this, user_data);
    }
}

FSM::~FSM()
{
    for (auto iter = states_map_.begin(); iter != states_map_.end(); iter++)
    {
        delete iter->second;
    }
    states_map_.clear();
}
