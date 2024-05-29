// 实现非阻塞读键盘
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <thread>

// 原子操作
#include <atomic>

extern std::atomic<char> input_char;

int kbhit(void);

void inputHandler();