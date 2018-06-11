#include "fieldwidget.h"

FieldWidget::FieldWidget(QWidget *parent) : QWidget(parent)
{
    mt = std::mt19937(rd());
    std::uniform_int_distribution<int> dist(0, 5);
    QGridLayout *layout = new QGridLayout;

    paintings = std::vector<QPixmap>(6, QPixmap());
    paintings[0].load(":/icons/bar");
    paintings[1].load(":/icons/bell");
    paintings[2].load(":/icons/cherry");
    paintings[3].load(":/icons/diamond");
    paintings[4].load(":/icons/seven");
    paintings[5].load(":/icons/watermelon");

    items_picture = std::vector<std::vector<QLabel*> >(3, std::vector<QLabel*>(3));
    std::vector<std::vector<int> > items_num(3, std::vector<int>(3));

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            items_picture[i][j] = new QLabel();
            items_num[i][j] = dist(mt);
            items_picture[i][j]->setPixmap(paintings[items_num[i][j]].scaled(192, 192));
            layout->addWidget(items_picture[i][j], i, j);
        }
    }
    setLayout(layout);
}
void FieldWidget::shuffle()
{
    std::uniform_int_distribution<int> dist(0, 5);
    std::vector<std::vector<int> > items_num(3, std::vector<int>(3));
     for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            items_num[i][j] = dist(mt);
            items_picture[i][j]->setPixmap(paintings[items_num[i][j]].scaled(192, 192));
        }
    }
    emit itemsChanged(items_num);
}
