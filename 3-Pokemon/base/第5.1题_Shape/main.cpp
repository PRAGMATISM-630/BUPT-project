#include<iostream>
#include"shape.h"

using namespace std;

int main()
{
	Shape* ptr = nullptr;
	double area = 0;

	cout << "�������������������ֱ�Ϊ���εĿ�͸�" << endl;
	int width, height;
	cin >> width >> height;
	Rectangle rect(width, height);
	ptr = &rect;
	area = ptr->Get_area();
	cout << "��Ϊ"<<width<<"����Ϊ"<<height<<"�ľ������Ϊ: " << area << endl << endl;

	cout << "������һ������������ʾԲ�İ뾶" << endl;
	int radius;
	cin >> radius;
	Circle cir(radius);
	ptr = &cir;
	area = ptr->Get_area();
	cout << "�뾶Ϊ"<<radius<<"��Բ�����Ϊ: " << area << endl << endl;

	cout<< "������һ������������ʾ�����εı߳�" << endl;
	cin >> width;
	Square squa(width);
	ptr = &squa;
	area = ptr->Get_area();
	cout << "�߳�Ϊ"<<width<<"�������ε����Ϊ: " << area << endl << endl;

	Rectangle rect2(squa);
	ptr = &rect2;
	area = ptr->Get_area();
	cout << "�Ծ��ε�������㷽��(��*�ߣ����߳�Ϊ"<<width<<"�������ε����Ϊ: " << area << endl << endl;

	//����������Ϊ���鿴���ڸ��ƹ��캯���ĵ��ã����������ڹ������ƹ�ʡ��
	Square squa2(squa);
	ptr = &squa;
	area = ptr->Get_area();
	cout << "�߳�Ϊ" << width << "�������ε����Ϊ: " << area << endl << endl;
}

/*
�ó�������������£�

���๹�캯��										->�ȵ��û��๹�캯��
�����๹�캯��									->�ٵ��������๹�캯��
��Ϊ4����Ϊ5�ľ������Ϊ: 20

���๹�캯��
Բ���๹�캯��
�뾶Ϊ2��Բ�����Ϊ: 12.56

���๹�캯��
�����๹�캯��
�������๹�캯��
�߳�Ϊ6�������ε����Ϊ: 36

���๹�캯��										->����ʹ������������ʼ���������
�����ิ�ƹ��캯��								->�����������ิ�ƹ��캯��
�Գ����ε�������㷽������*�ߣ����߳�Ϊ6�������ε����Ϊ: 36

���๹�캯��
�����ิ�ƹ��캯��
�������ิ�ƹ��캯��
�߳�Ϊ6�������ε����Ϊ: 36

����������������									->���������ĵ���˳���빹�캯�������ƹ��캯��ǡ���෴
��������������									->���ȹ���ĺ������������������
������������
��������������
������������
����������������
��������������
������������
Բ������������
������������
��������������
������������




*/
