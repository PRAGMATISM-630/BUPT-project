#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int price = rand() % 1000 + 1;		//��ʵ�۸�

	int guess;							//�µļ۸�
	int left = 1,right = 1000;			//���½�

	cout << "��ӭ�����¼۸���Ϸ��" << endl;
	cout << "���һ��1~1000֮�������" << endl;
	while (true)
	{
		if (cin >> guess && guess<=right && guess>=left)
			if (guess == price)
			{
				cout << "��ϲ��¶��ˣ��۸�Ϊ" << price << "Ԫ��\n" << endl;
				break;
			}
			else if (guess < price)
			{
				left = guess+1;
				cout << "���ˣ�������һ�����������" << left << "~" << right << "֮��)" << endl;
			}
			else
			{
				right = guess-1;
				cout << "���ˣ�������һ����С������" << left << "~" << right << "֮��)" << endl;
			}
		else
		{
			cout << "���벻�Ϸ���������һ��"<<left<<"~"<<right<<"֮���������" << endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
	}

}