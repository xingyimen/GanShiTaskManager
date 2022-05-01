#ifndef SCHEDULE_H
#define SCHEDULE_H

#include<string>
#include "mytime.h"
#include "daodata.h"

//�ճ̽��沿��
class Schedule
{
private:
    std::string name;			//�ճ�����
    std::string description;		//��������
	MyTime start_time;		//�ճ̵Ŀ�ʼʱ��
	MyTime end_time;			//�ճ̵Ľ���ʱ��
	Schedule* next;			//ָ����һ���ճ�
	Schedule* prev;			//ָ����һ���ճ�
public:
    Schedule(std::string name, std::string description, MyTime start_time, MyTime end_time, int flag);	//���캯��
	~Schedule();	//��������
	/*����Ϣ����QT��*/
    std::string return_name();					//�����ճ�����
    std::string return_description();			//��������
	MyTime return_time();						//������ʼʱ��ͽ���ʱ��

    /*ɾ���ճ̽ڵ�*/
	bool delete_schedule(Schedule* head);	//ɾ���ճ�

    /*Dao��ӿ�*/
   ScheduleDao toDaoItem();
   Schedule(ScheduleDao& item);
};


#endif
