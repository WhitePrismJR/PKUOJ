#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

struct node
{
	char data;
	std::shared_ptr<node> left;
	std::shared_ptr<node> right;
};

std::shared_ptr<node> reBuildTree(std::shared_ptr<node> head, std::string preOrder, std::string midOrder)
{
	head->data = preOrder[0];
	int index = midOrder.find(head->data);
	int leftNum = index;
	int rightNum = midOrder.size() - 1 - leftNum;
	if (index != 0)
	{
		std::string subLeftPreOrder = preOrder.substr(1, leftNum);
		std::string subLeftMidOrder = midOrder.substr(0, leftNum);
		//node *left = new node;
		auto left = std::make_shared<node>();
		head->left = reBuildTree(left, subLeftPreOrder, subLeftMidOrder);
	}
	if (index == 0)
	{
		head->left = NULL;
	}
	if (rightNum != 0)
	{
		std::string subRightPreOrder = preOrder.substr(index + 1, rightNum);
		std::string subRightMidOrder = midOrder.substr(index + 1, rightNum);
		auto right = std::make_shared<node>();
		//node *right = new node;
		head->right = reBuildTree(right, subRightPreOrder, subRightMidOrder);
	}
	if (rightNum == 0)
	{
		head->right = NULL;
	}
	return head;
}

void PostOrderRecord(std::string &postOrder, std::shared_ptr<node> head)
{
	if (head->left)
	{
		PostOrderRecord(postOrder, head->left);
	}
	if (head->right)
	{
		PostOrderRecord(postOrder, head->right);
	}
	postOrder = postOrder + head->data;
}

int main()
{

	std::vector<std::string> result;
	std::string preOrder, midOrder;
	while (cin >> preOrder >> midOrder)
	{
		//用指针传地址，不用对象，免得每次调用函数都要拷贝对象
		//node *head = new node;
		std::shared_ptr<node> head = std::make_shared<node>();
		//std::cout << preOrder << midOrder << std::endl;
		reBuildTree(head, preOrder, midOrder);
		std::string postOrder = "";
		PostOrderRecord(postOrder, head);
		result.push_back(postOrder);
		preOrder.clear();
		midOrder.clear();
		postOrder.clear();
		//delete head;
	}
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << std::endl;
	}
	return 0;
}