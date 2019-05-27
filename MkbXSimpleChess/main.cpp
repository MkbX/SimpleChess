#include <QGuiApplication>
#include "rootwindow.h"



int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);
    
   RootWindow w;
   w.show();

    return a.exec();
}
