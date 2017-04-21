#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <string>
#include <QTimer>

class MyWindow : public QWidget{

    Q_OBJECT

public:
    MyWindow();

public slots:
    void updateKey();
    void compare();
    void stopMessage();

private:
    std::string Key;

    QVBoxLayout *mainLay;
    QLabel *txtUserKey;
    QLineEdit *edituserKey;
    QPushButton *compareKeys;
    QLabel *txtKey;
    QLineEdit *editKey;
    QPushButton *updateKeyButton;

    QLabel *message;
    QTimer *timer;
};

#endif // MYWINDOW_H
