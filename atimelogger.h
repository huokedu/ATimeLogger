#ifndef ATIMELOGGER_H
#define ATIMELOGGER_H

#include <QtGui/QMainWindow>
#include "ui_atimelogger.h"

//Qt
#include <QTimer>
#include <QElapsedTimer>
#include <phonon>

class Phonon::MediaObject;
class Phonon::AudioOutput;

class ATimeLogger : public QMainWindow
{
	Q_OBJECT

public:
	ATimeLogger(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ATimeLogger();

public slots:
	//��ʼ���
	void StartProgramSlot();
	//��ͣ���
	void PauseProgramSlot();
	//�������
	void StopProgramSlot();
	//��� ����ʱ��
	void UpdateProgramTimeSlot();
	//����
	void RingProgramTomatoSlot();

private:
	Ui::ATimeLoggerClass ui;

	//��̼�ʱ��
	QTimer m_ProgramTimer;
	//���Ѽ�ʱ��
	QTimer m_ProgramTomatoTimer;
	//��̽���ʱ��
	QElapsedTimer m_ProgramElapsedTimer;
	//��̽�������
	qint64 m_ProgramSecs;

	//����������
	Phonon::MediaObject *m_PlayObject;
	Phonon::AudioOutput *m_PlayOutput;
};

#endif // ATIMELOGGER_H
