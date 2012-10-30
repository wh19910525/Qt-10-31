#include "fileinformation.h"
#include <QtGui/QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
	FileInformation *w=new FileInformation();
	w->show();
	return a.exec();
}
