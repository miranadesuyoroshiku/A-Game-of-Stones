#ifndef STONEGAMEH
#define STONEGAMEH

class StoneGame {
    private:
        int count = 0;
        int chance = 0;
        void UpdateStepCount(int count);
        void NotValidMove(int human_move);
        void ComputerMoveHard(int stones);
    
    public:
        void EasyMode(int stones);
        void HardMode(int stones);
        int GetStones();
        void ComputerMove();
        void HumanMove(int count);
        int WinLose(); // 0:not yet; 1:computer 2;human
};

#endif
