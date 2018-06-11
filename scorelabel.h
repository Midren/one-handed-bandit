#ifndef SCORELABEL_H
#define SCORELABEL_H

#include <QWidget>
#include <vector>
#include <QLabel>
#include <QVBoxLayout>

class ScoreLabel : public QWidget
{
    Q_OBJECT
public:
    explicit ScoreLabel(QWidget *parent = nullptr);

signals:
    void outOfMoney();
public slots:
    void changeScore(std::vector<std::vector<int> > new_items);
    void makeStep();
private:
    QLabel *score;
};

#endif // SCORELABEL_H
