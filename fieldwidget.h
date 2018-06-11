#ifndef FIELDWIDGET_H
#define FIELDWIDGET_H

#include<QLabel>
#include<QGridLayout>
#include<QWidget>
#include<QPushButton>
#include<QPixmap>
#include<vector>
#include <random>

class FieldWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FieldWidget(QWidget *parent = nullptr);

signals:
    void itemsChanged(std::vector<std::vector<int> > new_items);
public slots:
    void shuffle();
private:
    std::random_device rd;
    std::mt19937 mt;
    std::vector<QPixmap> paintings;
    std::vector<std::vector<QLabel*> > items_picture;
};
#endif // FIELDWIDGET_H
