#ifndef QUADRANT_H
#define QUADRANT_H

#include<iostream>
#include<string>
#include "mytime.h"
#include "daodata.h"
class Quadrant
{
private:
	int rol;				//���������޵ĺ�����
	int col;				//���������޵�������
    std::string name;			//��������
    std::string description;		//��������
	MyTime now;				//ʱ��
	MyTime end_time;			//��ֹʱ��
public:
	Quadrant(int rol, int col, MyTime now);		//���캯����Ĭ���������ƣ�δ�����������������ԣ�
    Quadrant(int rol, int col, std::string name, std::string description, MyTime now);		//���캯��
	~Quadrant();	//��������
    //Quadrant operator=(const Json& item);   //��Json�е�������
	/*����Ϣ����QT��*/
    std::string return_name();		//�����ճ�����
    std::string return_description();//���ؾ�������
	/*����ʱ��*/
    bool update(MyTime new_time);	//����ʱ��

    /*Dao��ӿ�*/
   QuadrantDao toDaoItem();
   Quadrant(QuadrantDao& item);



};

#endif
