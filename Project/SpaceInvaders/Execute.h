#include <vector>

class Execute{
public:
    Execute();
    ~Execute();
    void executeThis();
    int writeHighScore(string);

    char input1;
    int input2;
    char input3;
    string input4;
    int MaxHighScore;

private:
    int Scores[500];
};
