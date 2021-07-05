#ifndef UI_FRAMEWORK_H
    #define UI_FRAMEWORK_H
    typedef enum gamemode {
        single_player=1,
        multi_player
    }gamemode;
    void computer_turn (void);
    int player_turn (gamemode mode,char* user);
    void start(void);
    void UnitTestingFrameWork(void);
#endif // UI_FRAMEWORK_H
