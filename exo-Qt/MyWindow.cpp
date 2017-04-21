#include "MyWindow.h"

MyWindow::MyWindow()
{
    Key = "lol";
    mainLay = new QVBoxLayout;

    mainLay->setMargin(50);

    txtUserKey = new QLabel(tr("entrer la clef de sécurité :"));
    edituserKey = new QLineEdit;
    compareKeys = new QPushButton(tr("comparer"));

    txtKey = new QLabel(tr("entrer la nouvelle clef de sécuritée :"));
    editKey = new QLineEdit;
    updateKeyButton = new QPushButton(tr("valider"));

    timer = new QTimer;
    timer->setSingleShot(true);

    message = new QLabel();

    mainLay->addWidget(txtUserKey);
    mainLay->addWidget(edituserKey);
    mainLay->addWidget(compareKeys);
    mainLay->addWidget(txtKey);
    mainLay->addWidget(editKey);
    mainLay->addWidget(updateKeyButton);
    mainLay->addWidget(message);
    message->hide();


    QObject::connect(updateKeyButton, SIGNAL(clicked(bool)), this, SLOT(updateKey()));
    QObject::connect(compareKeys, SIGNAL(clicked(bool)), this, SLOT(compare()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(stopMessage()));

    setLayout(mainLay);
}

void MyWindow::updateKey(){
    Key = (editKey->text()).toStdString();
    message->setText(tr("Clef modifiée !"));
    message->show();
    timer->stop();
    timer->start();
}

void MyWindow::compare(){
    if ((edituserKey->text()).toStdString() == Key){
        message->setText(tr("les clefs sont identiques !"));
        message->show();
        timer->stop();
        timer->start(3000);
    }else{
        message->setText(tr("les clefs sont différentes !"));
        message->show();
        timer->stop();
        timer->start(3000);
    }
}

void MyWindow::stopMessage(){
    message->hide();
}
