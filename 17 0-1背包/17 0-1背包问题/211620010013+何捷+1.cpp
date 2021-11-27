#include<iostream>
#include <queue>
using namespace std;
/*
	��4����Ʒ���������ֱ�Ϊ(4,7,5,3)����ֵ�ֱ�Ϊ(40,42,25,12)��������������W=10��
*/
#define GOODS_NUM  4	//��Ʒ����
#define CAPICITY  10	//��������

//������Ʒ����
class Goods {
public:
	int id;			//��Ʒ���
	int weight;		//��Ʒ����
	int value;		//��Ʒ��ֵ
	int aver_value;	//��Ʒƽ����ֵ
};

//���������Ϣ
struct Node {
	int depth;		//��ǰ������
	int weight;		//��ǰ�ڵ�����
	int value;		//��ǰ�ڵ��ֵ
	int ub;			//���㵱ǰ�ڵ������ֵ
	int flag;		//��ǰ�ڵ���������
	Node* parent;	//��ǰ�ڵ�ĸ��ڵ�

};

//����ȫ�ֱ���
Goods goods[GOODS_NUM + 1];		//�±��1��ʼ
const int capicity = CAPICITY;
int down;		//��ֵ�½�
int up;			//��ֵ�Ͻ�
Node* BestValue;	//���Ž��

//1����ʼ����Ʒ�б�
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

//2����ȡ��ǰ�ڵ������ֵ
int GetBestValue(Node* node) {
	int ub;
	int remainCapicity = capicity - node->weight;		//ʣ������
	if (node->depth < GOODS_NUM)	//��ǰ�ڵ㲻��Ҷ�ڵ�
	{
		if (node->flag)//����Ʒ�Ž�ȥ
		{
			ub = node->value + remainCapicity * goods[node->depth + 1].aver_value;
		}
		else      //���Ž�ȥ
		{
			ub = node->value + remainCapicity * goods[node->depth + 1].aver_value;
		}
	}
	else    //��Ҷ���
	{
		ub = node->value;
		if (ub > down)
		{
			down = ub;
		}
		//��ȡ���Ž��
		BestValue = node;
	}
	//cout << "1" << endl;
	
	
	return ub;
}

//3����֧�޽��㷨
class Compare {
public:
	bool operator()(Node* a, Node* b) {
		return a->ub < b->ub;
	}
};

void BranchBound() {
	down = goods[1].value;			//��ȡ��С��ֵ
	up = goods[1].aver_value * capicity;	//��ȡ�������ֵ
	//��ʼ�����ڵ�
	Node* root = new Node();
	root->depth = 0;
	root->weight = 0;
	root->value = 0;
	root->ub = up;
	root->flag = -1;
	
	//cout << "2" << endl;
	BestValue = root;//�ø��ڵ��ʼ�����ֵ�ڵ�ָ�룬����whileѭ���е��жϳ���
	priority_queue<Node*, vector<Node*>, Compare> pt;//������ȶ���
	pt.push(root);//���ڵ����
	while (!pt.empty())
	{
		Node* currentNode, * leftNode, * rightNode;
		currentNode = pt.top();			//ȡ����Ԫ��
		pt.pop();			//����

		//��ڵ㣬���뱳��
		leftNode = new Node();
		leftNode->depth = currentNode->depth + 1;//��ȡ������
		//��ȡ�������ж��Ƿ���Լ���
		leftNode->weight = currentNode->weight + goods[leftNode->depth].weight;
		if (leftNode->weight < capicity)
		{
			leftNode->value = currentNode->value + goods[leftNode->depth].value;
			leftNode->flag = 1;
			leftNode->parent = currentNode;
			leftNode->ub = GetBestValue(leftNode);//��ȡ������ֵ
			if (leftNode->ub >= down)	//��ֵ���±߽��
			{
				if (leftNode->depth == GOODS_NUM)//���ҵ�����ֵ
					break;
				pt.push(leftNode);
			}
			cout << "w = " <<leftNode->weight << "��С�ڱ�����������Ʒ" << leftNode->depth << "���뱳��" << endl;
		}
		else
		{
			//��������
			cout << "w = " << leftNode->weight << "������������������Ʒ" << leftNode->depth << "�����뱳��" << endl;
		}

		//�ҽڵ㣬�����뱳��
		rightNode = new Node();
		rightNode->depth = currentNode->depth + 1;
		rightNode->weight = currentNode->weight;
		//��ȡ�������ж��Ƿ���Լ���
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
			//��������
			cout << "w = " << rightNode->weight << "������������������Ʒ" << rightNode->depth << "�����뱳��" << endl;
		}
		if (BestValue->depth == GOODS_NUM)//���ҵ�����ֵ
			break;
	}
}

void printResult()
{
	int x[GOODS_NUM];	//��Ʒ���״̬��1Ϊ���룬0Ϊ������
	Node* p = BestValue;		//���Ž��
	for (int i = GOODS_NUM - 1; i >= 0; i--)
	{
		x[i] = p->flag;
		p = p->parent;
	}
	cout << endl;
	cout << "���뱳������ƷΪ��1:����;0:�����룩��";
	for (int i = 0; i < GOODS_NUM; i++) {
			cout << x[i] << " ";
	}
	cout << endl;
	cout << "����װ�������ֵΪ��" << BestValue->value << endl;
}


int main() {
	GoodsInit();
	BranchBound();
	printResult();

	system("pause");
	return 0;
}
