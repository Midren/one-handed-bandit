#include "scorelabel.h"

ScoreLabel::ScoreLabel(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    score = new QLabel;
    score->setNum(1000);
    layout->addWidget(score);
    setLayout(layout);
}
void ScoreLabel::changeScore(std::vector<std::vector<int> > new_items)
{
    int vert = 3, hor = 3;
    for(int i = 0; i < 3; i++)
        for(int j =1; j < 3; j++)
            if(new_items[i][j-1] != new_items[i][j]) {
                --vert;
                break;
            }
    for(int i = 0; i < 3; i++)
        for(int j =1; j < 3; j++)
            if(new_items[j-1][i] != new_items[j][i]) {
                --hor;
                break;
            }
    int diagonal = 0;
    if(new_items[0][0] == new_items[1][1] && new_items[1][1] == new_items[2][2])
        diagonal += 1;
    if(new_items[0][2] == new_items[1][1] && new_items[1][1] == new_items[2][0])
        diagonal += 1;
    score->setNum(score->text().toInt() + (vert+hor) * 100 + diagonal*200);
}

void ScoreLabel::makeStep()
{
    int sc = score->text().toInt();
    if(sc - 50 < 0)
        emit outOfMoney();
    else
        score->setNum(sc-50);
}
