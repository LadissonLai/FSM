#pragma once
#include "BaseState.h"
#include <iostream>
#include <map>
#include <string>
#include <cstdlib> //exit函数
#include "fsm_utils.h"

class FSM
{
private:
    BaseState *curState_;
    std::map<std::string, BaseState *> states_map_; // 使用字典维护这些新创建的状态，避免频繁的new和delete对象。

public:
    FSM() : curState_(nullptr) {}
    ~FSM();

    template <typename T>
    void change_state(void *user_data)
    {
        if (curState_)
        {
            curState_->leave(this, user_data);
        }
        std::string new_state_name = get_type_name<T>();
        std::map<std::string, BaseState *>::iterator iter = states_map_.find(new_state_name);
        BaseState *new_state;
        if (iter != states_map_.end()) // found
        {
            new_state = iter->second;
        }
        else // not found
        {
            new_state = new T(new_state_name);
            states_map_[new_state->get_name()] = new_state;
        }
        if (!new_state->initialized_)
        {
            new_state->init(this, user_data);
        }
        new_state->enter(this, user_data);
        this->curState_ = new_state;
    }

    template <typename T>
    void set_init_state(void *user_data)
    {
        std::string init_state_name = get_type_name<T>();
        std::map<std::string, BaseState *>::iterator iter = states_map_.find(init_state_name);
        if (iter != states_map_.end()) // found
        {
            this->curState_ = iter->second;
            if (!this->curState_->initialized_)
            {
                this->curState_->init(this, user_data);
            }
            this->curState_->enter(this, user_data);
        }
        else // not found
        {
            BaseState *new_state = new T(init_state_name);
            states_map_[new_state->get_name()] = new_state;
            this->curState_ = new_state;
            new_state->init(this, user_data);
            new_state->enter(this, user_data);
        }
    }

    void update(void *user_data);
};