#include "schedule.h"

//�ճ���
/*
���캯����
��������
string name���ճ�����
string description���ճ̵ľ�������
Time start_time���ճ̵Ŀ�ʼʱ��
Time end_time���ճ̵Ľ���ʱ��
int flag�������ж��û��Ƿ�ӹ������л�ȡ�ճ����ƣ�����ӹ������л�ȡflag=1�����ֱ����������flag=2
*/
Schedule::Schedule(std::string name, std::string description, MyTime start_time, MyTime end_time, int flag)
{

}

/*
��������
*/
Schedule::~Schedule(){

}

/*
��Json�е�������
*/
//Schedule::Schedule operator=(const Json& item)
//{

//}

/*
�����ճ̵�����
*/
std::string Schedule::return_name()
{

}

/*
�����ճ̵ľ�������
*/
std::string Schedule::return_description()
{

}

/*
�����ճ̵Ŀ�ʼ�ͽ���ʱ��
*/
MyTime Schedule::return_time()
{

}

/*
ɾ���ճ̣�
��������
Schedule* head�������ճ̵�ͷָ�뼴ͷָ��ָ�����һ���ǵ�һ���ճ�
�����衿
1�������ճ̵���һ���ճ̺���һ���ճ̽�������
2���ͷŸ��ճ̵��ڴ�
3�������Ƿ�ɾ���ɹ����ɹ�����true��ʧ�ܷ���false
*/
bool delete_schedule(Schedule* head)
{

}




/*Dao��ӿ�*/
ScheduleDao Schedule::toDaoItem()
{
    //��������תstring
    ScheduleDao daoitem;

}

Schedule::Schedule(ScheduleDao& daoitem)
{
    //stringת����

}

