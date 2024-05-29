# Finite-State-Machine

使用c++实现简单的有限状态机，并根据键盘输入切换到不同状态，本项目定义了三个状态idle，walk，run，按键i, w, r分别切换到对应状态。

状态机和状态模式在代码上理解差别不大，但是用途上面来讲差别很大。状态模式主要用在相同功能在不同状态下有不同表现，状态机用于不同状态之间的切换。

本状态机状态的扩展遵循“扩展开放，修改关闭”的原则，状态的切换在状态内部自己控制，无需修改顶层的代码代码。

状态机结果展示：

```shell
init Idle
---enter Idle
update Idle
update Idle
---leave Idle # 按键r
init Run
---enter Run
update Run
---leave Run # 按键w
init Walk
---enter Walk
update Walk
update Walk
---leave Walk # 按键r
---enter Run
update Run
update Run
---leave Run # 按键w
---enter Walk
```

## BUILD

```shell
git clone https://github.com/LadissonLai/Finite-State-Machine.git


```



