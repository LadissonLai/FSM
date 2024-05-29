#include "Idle.h"
#include "Walk.h"
#include "Run.h"
#include "keyboard_input.h"
#include "FSM.h"
#include <chrono>
#include <thread>

void fsm_thread()
{
    FSM fsm;
    fsm.set_init_state<Idle>(nullptr);
    while (true)
    {
        fsm.update(nullptr);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main()
{
    std::thread keyboard_t(inputHandler);
    std::thread fsm_t(fsm_thread);
    keyboard_t.join();
    fsm_t.join();
    return 0;
}