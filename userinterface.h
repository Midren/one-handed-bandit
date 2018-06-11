#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "scorelabel.h"
#include "fieldwidget.h"
#include <QCoreApplication>
#include <QMessageBox>

class UserInterface : public QWidget
{
    Q_OBJECT
public:
    explicit UserInterface(QWidget *parent = nullptr);

signals:
    void itemsChanged(std::vector<std::vector<int> > new_items);
    void needShuffle();
public slots:
    void shuffle();
    void changeScore(std::vector<std::vector<int> > new_items);
    void requireMoney();
    void quit();
private:
    QPushButton *shuffleButton;
    QPushButton *quitButton;
    ScoreLabel *score;
};

#endif // USERINTERFACE_H
