#include "TotalHead.h"

void textFile1_1_0()
{
	cout << "|正当你拿起盒子中的物品时，你听见了一阵脚步声。" << endl;
	postpone();
	cout << "|抬起头，你看见一个披着茅草的人向你冲来。" << endl;
	postpone();
	cout << "|你分明看见他的手上拿着武器。" << endl;
	postpone();
	cout << "|大事不妙，但你很快做好了战斗的准备。你拔出了枪。" << endl;
	postpone();
	printEndl();
}

void textFile1_1_1()
{
	cout << "|你的冒险从一片无边无际的草原开始了。" << endl;
	postpone();
	cout << "|为了寻找那块核心，你来到了这里。" << endl;
	postpone();
	cout << "|草原的清风拂过你的脸颊，你感到无比地舒适。\n" << endl;
	postpone();
	cout << "|继续向前走，你发现这里居然有人的痕迹。" << endl;
	postpone();
	cout << "|尚未熄灭的火堆，远处的烟尘，怎么看也不像自然产生的。" << endl;
	postpone();
	cout << "|你蹲下身，用树枝在火堆中翻找着。" << endl;
	postpone();
	cout << "|你知道这样的行为毫无意义，但习惯总让你这样做。\n" << endl;
	postpone();
	cout << "|火堆中是一无所获。这在你料想当中。" << endl;
	postpone();
	cout << "|倒是在火堆旁，你发现了一个小盒子。" << endl;
	postpone();
	cout << "|出于好奇，你打开了它。没想到真发现了一些东西。" << endl;
	postpone();
	printEndl(3);
}

void textFile1_1_2()
{
		cout << "|击败了刚才的敌人，你仍然心有余悸。" << endl;
		postpone();
		cout << "|果然，这里不是你该来的地方。" << endl;
		postpone();
		cout << "|敌人的身上有些许紫色的结晶，这是核心物质侵染的痕迹。" << endl;
		postpone();
		cout << "|这里很危险，但至少证明你来对地方了。这里的核心物质浓度很高。" << endl;
		postpone();
		cout << "|敌人的颈部挂着一颗水晶。运气好的话，没准这就是一颗核心。" << endl;
		postpone();
		cout << "|你将那颗水晶取下，握在手里感受着。一种温暖的感觉贯穿全身。" << endl;
		postpone();
		cout << "|你将核心放在背包中，准备继续前往草原深处。" << endl;
		postpone();
		cout << "|可是茫茫的草原没有方向，该向哪里走呢？" << endl;
		postpone();
		cout << "|远处有两座山，一座比另一座更高，看样子是个不错的地标。" << endl;
		postpone();
		print_();
		cout << "\n|选择路线：\n◆1：较高的山峰\n◆2：较矮的山峰\n";

		int whereToGo = 0;
		FLAG:
		countInChoice(whereToGo);

		if (whereToGo < 1 || whereToGo > 2) {
			cout << "|根本没有这条路线。你必须做出选择：";
			goto FLAG;
		}
		print_();
		cout << endl;

		if (whereToGo == 1) {
			cout << "|这座高山给你带来一丝安全感，不如走这里吧。" << endl;
			postpone();
			cout << "\n|行走在半人多高的草地中，翻过一个又一个山丘，你真切地感受到人的渺小。" << endl;
			postpone();
			cout << "|核心……这个世界本源的力量……" << endl;
			postpone();
			cout << "|其中蕴藏着人类至今无法探明的奥妙。" << endl;
			postpone();
			cout << "|而你要找到的那颗核心，一定就藏在不远处。" << endl;
			postpone();
			print_();
			cout << endl;
		}
		else if (whereToGo == 2) {
			cout << "|山高路险，走较矮的那边好了。" << endl;
			postpone();
			cout << "\n|行走在半人多高的草地中，翻过一个又一个山丘，你真切地感受到人的渺小。" << endl;
			postpone();
			cout << "|核心……这个世界本源的力量……" << endl;
			postpone();
			cout << "|其中蕴藏着人类至今无法探明的奥妙。" << endl;
			postpone();
			cout << "|而你要找到的那颗核心，一定就藏在不远处。" << endl;
			postpone();
			print_();
			cout << endl;
		}

}

void textFile1_1_3()
{
	cout << "|这片区域应该安全了。" << endl;
	postpone();
	cout << "|你四处搜寻，但空气中弥漫的核心尘埃仍然不够。" << endl;
	postpone();
	cout << "|核心肯定不在这里。" << endl;
	postpone();
	cout << "|你决定前往下一个地方了。" << endl;
	postpone();
	cout << "|就在这时， 你听到远处有呼喊的声音传来。" << endl;
	postpone();
	cout << "|你谨慎地走了过去，却发现了一个……" << endl;
	postpone();
	cout << "|商人？" << endl;
	postpone();
	cout << "|不管怎么说，先看看他卖什么东西吧。" << endl;
	postpone();
}