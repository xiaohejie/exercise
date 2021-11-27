#include<iostream>
#include <queue>
using namespace std;
/*
	有4个物品，其重量分别为(4,7,5,3)，价值分别为(40,42,25,12)，背包容量限制W=10。
*/
#define GOODS_NUM  4	//商品数量
#define CAPICITY  10	//背包容量

//创建商品的类
class Goods {
public:
	int id;			//商品编号
	int weight;		//商品重量
	int value;		//商品价值
	int aver_value;	//商品平均价值
};

//创建结点信息
struct Node {
	int depth;		//当前结点深度
	int weight;		//当前节点重量
	int value;		//当前节点价值
	int ub;			//估算当前节点的最大价值
	int flag;		//当前节点是左还是右
	Node* parent;	//当前节点的父节点

};

//设置全局变量
Goods goods[GOODS_NUM + 1];		//下标从1开始
const int capicity = CAPICITY;
int down;		//价值下界
int up;			//价值上界
Node* BestValue;	//最优结点

//1、初始化商品列表
void GoodsInit() {
	//cout << capicity << endl;
	int w[] = { 4,7,5,3 };
	int v[] = { 40,42,25,12 };
	for (int i = 0; i < GOODS_NUM; i++)
	{
		goods[i + 1].id = i + 1;
		goods[i + 1].weight = w[i];
		goods[i + 1].value = v[i];
		goods[i + 1].aver_value = v[i] / w[i];
	}

}

//2、获取当前节点的最大价值
int GetBestValue(Node* node) {
	int ub;
	int remainCapicity = capicity - node->weight;		//剩余容量
	if (node->depth < GOODS_NUM)	//当前节点不是叶节点
	{
		if (node->flag)//该物品放进去
		{
			ub = node->value + remainCapicity * goods[node->depth + 1].aver_value;
		}
		else      //不放进去
		{
			ub = node->value + remainCapicity * goods[node->depth + 1].aver_value;
		}
	}
	else    //是叶结点
	{
		ub = node->value;
		if (ub > down)
		{
			down = ub;
		}
		//获取最优结点
		BestValue = node;
	}
	//cout << "1" << endl;
	
	
	return ub;
}

//3、分支限界算法
class Compare {
public:
	bool operator()(Node* a, Node* b) {
		return a->ub < b->ub;
	}
};

void BranchBound() {
	down = goods[1].value;			//获取最小价值
	up = goods[1].aver_value * capicity;	//获取最大估算价值
	//初始化根节点
	Node* root = new Node();
	root->depth = 0;
	root->weight = 0;
	root->value = 0;
	root->ub = up;
	root->flag = -1;
	
	//cout << "2" << endl;
	BestValue = root;//用根节点初始化最大值节点指针，避免while循环中的判断出错
	priority_queue<Node*, vector<Node*>, Compare> pt;//最大优先队列
	pt.push(root);//根节点入队
	while (!pt.empty())
	{
		Node* currentNode, * leftNode, * rightNode;
		currentNode = pt.top();			//取出首元素
		pt.pop();			//出队

		//左节点，加入背包
		leftNode = new Node();
		leftNode->depth = currentNode->depth + 1;//获取结点深度
		//获取重量，判断是否可以继续
		leftNode->weight = currentNode->weight + goods[leftNode->depth].weight;
		if (leftNode->weight < capicity)
		{
			leftNode->value = currentNode->value + goods[leftNode->depth].value;
			leftNode->flag = 1;
			leftNode->parent = currentNode;
			leftNode->ub = GetBestValue(leftNode);//获取最大估计值
			if (leftNode->ub >= down)	//该值比下边界大
			{
				if (leftNode->depth == GOODS_NUM)//已找到最大价值
					break;
				pt.push(leftNode);
			}
			cout << "w = " <<leftNode->weight << "，小于背包容量，商品" << leftNode->depth << "加入背包" << endl;
		}
		else
		{
			//重量超出
			cout << "w = " << leftNode->weight << "，超出背包容量，商品" << leftNode->depth << "不加入背包" << endl;
		}

		//右节点，不加入背包
		rightNode = new Node();
		rightNode->depth = currentNode->depth + 1;
		rightNode->weight = currentNode->weight;
		//获取重量，判断是否可以继续
		if (rightNode->weight < capicity)
		{
			rightNode->value = currentNode->value;
			rightNode->flag = 0;
			rightNode->parent = currentNode;
			rightNode->ub = GetBestValue(rightNode);
			if (rightNode->ub >= down)
			{
				if (rightNode->depth == GOODS_NUM)
					break;
				pt.push(rightNode);
			}
		}
		else
		{
			//超出重量
			cout << "w = " << rightNode->weight << "，超出背包容量，商品" << rightNode->depth << "不加入背包" << endl;
		}
		if (BestValue->depth == GOODS_NUM)//已找到最大价值
			break;
	}
}

void printResult()
{
	int x[GOODS_NUM];	//物品存放状态：1为放入，0为不放入
	Node* p = BestValue;		//最优结点
	for (int i = GOODS_NUM - 1; i >= 0; i--)
	{
		x[i] = p->flag;
		p = p->parent;
	}
	cout << endl;
	cout << "放入背包的商品为（1:放入;0:不放入）：";
	for (int i = 0; i < GOODS_NUM; i++) {
			cout << x[i] << " ";
	}
	cout << endl;
	cout << "背包装入的最大价值为：" << BestValue->value << endl;
}


int main() {
	GoodsInit();
	BranchBound();
	printResult();

	system("pause");
	return 0;
}
