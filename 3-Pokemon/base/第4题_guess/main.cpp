#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int price = rand() % 1000 + 1;		//真实价格

	int guess;							//猜的价格
	int left = 1,right = 1000;			//上下界

	cout << "欢迎来到猜价格游戏！" << endl;
	cout << "请猜一个1~1000之间的整数" << endl;
	while (true)
	{
		if (cin >> guess && guess<=right && guess>=left)
			if (guess == price)
			{
				cout << "恭喜你猜对了，价格为" << price << "元！\n" << endl;
				break;
			}
			else if (guess < price)
			{
				left = guess+1;
				cout << "低了，请输入一个更大的数（" << left << "~" << right << "之间)" << endl;
			}
			else
			{
				right = guess-1;
				cout << "高了，请输入一个更小的数（" << left << "~" << right << "之间)" << endl;
			}
		else
		{
			cout << "输入不合法，请输入一个"<<left<<"~"<<right<<"之间的整数！" << endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
			continue;
		}
	}

}