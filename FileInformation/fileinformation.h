/********************************************************************
	created:	2012/04/10
	created:	10:4:2012   17:10
	filename: 	F:\C++\FileInformation\FileInformation\fileinformation.h
	file path:	F:\C++\FileInformation\FileInformation
	file base:	fileinformation
	file ext:	h
	author:		Rollen Holt
	
	purpose:	The head File of this project
*********************************************************************/
#ifndef FILEINFORMATION_H
#define FILEINFORMATION_H

#include <QtGui>   //in order to convenient, don't recommend.
class FileInformation : public QDialog
{
	Q_OBJECT

public:
	FileInformation(QWidget *parent = 0, Qt::WFlags flags = 0);
	~FileInformation();

private:


	QLabel *fileNameLabel;
	QLineEdit *fileNameLineEdit;
	QPushButton *fileButton;

	QLabel *fileSize;
	QLineEdit *fileLineEditSize;

	QLabel *fileCreatLabel;
	QLineEdit *fileCreatLineEdit;

	QLabel *fileLastModifyLabel;
	QLineEdit *fileLastModifLineEdit;

	QLabel *fileLastVisitedLabel;
	QLineEdit *fileLastVisitedLineEdit;

	QLabel *filePropertyLabel;
	QCheckBox *checkIsDir;
	QCheckBox *checkIsFile;
	QCheckBox* checkBoxIsSymLink;
	QCheckBox* checkBoxIsHidden;
	QCheckBox* checkBoxIsReadable;	
	QCheckBox* checkBoxIsWritable;	
	QCheckBox* checkBoxIsExecutable;

	QPushButton* PushButtonGet;

	void getFileInformation(QString fileName);

	private slots:
		void slotFile();
		void slotGet();
};

#endif // FILEINFORMATION_H
