#include"quadrant.h"


/*
���캯����
Ĭ���������ƣ�δ������������������
Ҫ�ڹ���ʱ�������ֹʱ�䣬��ֹʱ��������ж������Ҽ���8�����ٸ񣬲���ٸ�ͽ���ȡ��ʱ����϶����죨���7�죩
��������
int rol�����������޵ĺ�����
int col�����������޵�������
Time now����ǰ����ʱ��
*/


Quadrant::Quadrant(int rol, int col, MyTime now)
{

}

/*
���캯����
Ҫ�ڹ���ʱ�������ֹʱ�䣬��ֹʱ��������ж������Ҽ���8�����ٸ񣬲���ٸ�ͽ���ȡ��ʱ����϶����죨���7�죩
��������
int rol�����������޵ĺ�����
int col�����������޵�������
string description������ľ�������
Time now����ǰ����ʱ��
*/
Quadrant::Quadrant(int rol, int col, std::string name, std::string description, MyTime now)
{

}

/*
��������
*/
Quadrant::~Quadrant()
{}

/*
��Json�е�������
*/
//Quadrant::Quadrant operator=(const Json& item)
//{

//}

/*
�����ճ�����
*/
std::string return_name()
{

}

/*
���ؾ�������
*/
std::string return_description()
{

}

/*
����ʱ�䣺
ÿ�ν���������ҳ��ʱ������һ�����������
��������
Time new����ǰ����������ʱ��
�����衿
1��������Ľ�ֹʱ���ȥ���������ʱ�䣨���ڽ����ж�Ҫ����ʱ�䣬������24СʱΪ���ޣ�Ҫ�������ʱ�䣩
��1������������С��1��
�����û�����������ֹʱ�䲻��һ��
��2����������������1��
������Ϣ
��3������������Ϊ����
˵�������Ѿ�����򳬹���ֹʱ�䣬�����û������Ѿ����������ҷ���true��˵��������Ҫ����ɾ������
2���������û�н���������col�������꣬���ҷ���false
*/
bool update(MyTime new_time)
{

}

/*Dao��ӿ�*/
QuadrantDao Quadrant::toDaoItem()
{
    //��������תstring
    QuadrantDao daoitem;

}

Quadrant::Quadrant(QuadrantDao& daoitem)
{
    //stringת����

}


