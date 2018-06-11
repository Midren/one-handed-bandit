#include<QApplication>
#include<QGridLayout>
#include<QWidget>
#include<QPushButton>
#include"fieldwidget.h"
#include"userinterface.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGridLayout *layout = new QGridLayout;
    FieldWidget *field = new FieldWidget;
    UserInterface *control = new UserInterface;

    QObject::connect(control, &UserInterface::needShuffle, field, &FieldWidget::shuffle);
    QObject::connect(field, &FieldWidget::itemsChanged, control, &UserInterface::changeScore);

    layout->addWidget(field, 0, 0);
    layout->addWidget(control, 0, 1);

    QWidget window;
    window.setLayout(layout);

    window.show();

    return app.exec();
}
