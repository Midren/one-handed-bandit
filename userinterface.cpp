#include "userinterface.h"

UserInterface::UserInterface(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout;
    QLabel* scoreNameLabel = new QLabel(tr("Your score: "));
    shuffleButton = new QPushButton(tr("&Shuffle"));
    quitButton = new QPushButton(tr("&Quit"));
    score = new ScoreLabel;

    layout->addWidget(scoreNameLabel, 0, 0);
    layout->addWidget(score, 0, 1);
    layout->addWidget(shuffleButton, 1, 0);
    layout->addWidget(quitButton, 1, 1);

    QObject::connect(shuffleButton, &QPushButton::clicked, score, &ScoreLabel::makeStep);
    QObject::connect(score, &ScoreLabel::outOfMoney, this, &UserInterface::requireMoney);
    QObject::connect(shuffleButton, &QPushButton::clicked, this, &UserInterface::shuffle);
    QObject::connect(this, &UserInterface::itemsChanged, score, &ScoreLabel::changeScore);
    QObject::connect(quitButton, &QPushButton::clicked, this, &UserInterface::quit);

    setLayout(layout);
}

void UserInterface::shuffle()
{
    emit UserInterface::needShuffle();
}
void UserInterface::changeScore(std::vector<std::vector<int> > new_items)
{
    emit itemsChanged(new_items);
}

void UserInterface::requireMoney()
{
    disconnect(shuffleButton, &QPushButton::clicked, 0, 0);
    QObject::connect(shuffleButton, &QPushButton::clicked, score, &ScoreLabel::makeStep);
    QMessageBox moneyMsg;
    moneyMsg.setWindowTitle(tr("Run out of money"));
    moneyMsg.setText(tr("<p align='center'>Trial period ended, so you need to donate some money to bank card 8800553535</p>"));
    moneyMsg.setStandardButtons(QMessageBox::Ok);
    moneyMsg.exec();
}

void UserInterface::quit()
{
    if(QMessageBox::question(this,
                             "Exit",
                             "Do you really want to quit?",
                             QMessageBox::Yes | QMessageBox::Cancel,
                             QMessageBox::Cancel) == QMessageBox::Yes)
        qApp->quit();
}
