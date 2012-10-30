#include "fileinformation.h"

FileInformation::FileInformation(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{

	setWindowTitle(tr("File Information"));

	fileNameLabel=new QLabel(tr("File Name"));
	fileNameLineEdit=new QLineEdit();
	fileButton=new QPushButton(tr("Open"));
	QHBoxLayout *layout1=new QHBoxLayout();
	layout1->addWidget(fileNameLabel);
	layout1->addWidget(fileNameLineEdit);
	layout1->addWidget(fileButton);

	fileSize=new QLabel(tr("File Size"));
	fileLineEditSize=new QLineEdit();
	QHBoxLayout *layout2=new QHBoxLayout();
	layout2->addWidget(fileSize);
	layout2->addWidget(fileLineEditSize);

	fileCreatLabel=new QLabel(tr("Creat Time"));
	fileCreatLineEdit=new QLineEdit();
	QHBoxLayout *layout3=new QHBoxLayout();
	layout3->addWidget(fileCreatLabel);
	layout3->addWidget(fileCreatLineEdit);

	fileLastModifyLabel=new QLabel(tr("Last Modify Time"));
	fileLastModifLineEdit=new QLineEdit();
	QHBoxLayout *layout4=new QHBoxLayout();
	layout4->addWidget(fileLastModifyLabel);
	layout4->addWidget(fileLastModifLineEdit);

	fileLastVisitedLabel=new QLabel(tr("Last Visited Time"));
	fileLastVisitedLineEdit=new QLineEdit();

	filePropertyLabel=new QLabel(tr("File Property"));
	checkIsDir=new QCheckBox(tr("Menu"));
	checkIsFile=new QCheckBox(tr("File"));
	checkBoxIsSymLink=new QCheckBox(tr("SymLink"));
	checkBoxIsReadable=new QCheckBox(tr("Readable"));
	checkBoxIsWritable=new QCheckBox(tr("Writeable"));
	checkBoxIsHidden=new QCheckBox(tr("Hodden"));
	checkBoxIsExecutable=new QCheckBox(tr("Executable"));
	QHBoxLayout *layout5=new QHBoxLayout();
	layout5->addWidget(filePropertyLabel);
	layout5->addWidget(checkIsDir);
	layout5->addWidget(checkIsFile);
	layout5->addWidget(checkBoxIsSymLink);
	layout5->addWidget(checkBoxIsReadable);
	layout5->addWidget(checkBoxIsWritable);
	layout5->addWidget(checkBoxIsExecutable);

	PushButtonGet=new QPushButton(tr("Get File Information"));

	// main layout
	QVBoxLayout *mainLayout=new QVBoxLayout();
	mainLayout->addLayout(layout1);
	mainLayout->addLayout(layout2);
	mainLayout->addLayout(layout3);
	mainLayout->addLayout(layout4);
	mainLayout->addLayout(layout5);
	mainLayout->addWidget(PushButtonGet);
	setLayout(mainLayout);

	connect(fileButton,SIGNAL(clicked()),this,SLOT(slotFile()));
	connect(PushButtonGet,SIGNAL(clicked()),this,SLOT(slotGet()));
}

FileInformation::~FileInformation()
{
	
}

/*
 * Get file information
 **/
void FileInformation::getFileInformation(QString fileName){
	QFileInfo info(fileName);

	qint64 size=info.size();
	QDateTime creatTime=info.created();
	QDateTime lastModifyTime=info.lastModified();
	QDateTime lastReadTime=info.lastRead();
	
	bool isDir=info.isDir();
	bool isFile=info.isFile();
	bool isSymLink = info.isSymLink();
	bool isHidden = info.isHidden();
	bool isReadable = info.isReadable();
	bool isWritable = info.isWritable();
	bool isExecutable =info.isExecutable();

	fileLineEditSize->setText(QString::number(size));
	fileCreatLineEdit->setText(creatTime.toString());
	fileLastModifLineEdit->setText(lastModifyTime.toString());
	fileLastVisitedLineEdit->setText(lastReadTime.toString());

	checkIsDir->setCheckable(isDir?Qt::Checked:Qt::Unchecked);
	checkIsFile->setCheckable(isFile?Qt::Checked:Qt::Unchecked);
	checkBoxIsSymLink->setCheckState (isSymLink?Qt::Checked:Qt::Unchecked);
	checkBoxIsHidden->setCheckState (isHidden?Qt::Checked:Qt::Unchecked);
	checkBoxIsReadable->setCheckState (isReadable?Qt::Checked:Qt::Unchecked);
	checkBoxIsWritable->setCheckState (isWritable?Qt::Checked:Qt::Unchecked);
	checkBoxIsExecutable->setCheckState (isExecutable?Qt::Checked:Qt::Unchecked);
}

/*
 *	Open file
 **/
void FileInformation::slotFile(){
	QString s=QFileDialog::getOpenFileName(this,tr("open file"),"/","files(*)");
	fileNameLineEdit->setText(s.toAscii());
}


void FileInformation::slotGet(){
	getFileInformation(fileNameLineEdit->text());
}
