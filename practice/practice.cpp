#include "practice.h"
 
void BaseAccount::make_account(std::string n, int m)
{
	user_name = n;
	money = m;
	Account_type = 0;
}
int BaseAccount::withdraw(int m)
{
	int temp1 = money - m;
	if (Account_type == 0) {
		if (temp1 < 0) {
			std::cout << "�ܾ��� �����մϴ�. �ٽ��Է����ּ���" <<temp1<< "," <<money <<std::endl;
			return 2;
		}
		else {
			money -= m;
			return 1;
		}
	}
	else {
		money -= m;
		return 1;
	}
}
 
void BaseAccount::deposit(int m)
{
	money += m;
}
 
void BaseAccount::give_account(std::string new_user)
{
	std::string  n = new_user;
	user_name = n;
}
void BaseAccount::check_account(void) {
	std::cout<<"�����ִ� "<< user_name << std::endl;
	std::cout<<"�ܾ��� "<< money << std::endl;
	if (Account_type== 0)
		std::cout<<"���������� ���������Դϴ�."<< std::endl;
	else 
		std::cout<<"���������� ��������Դϴ�."<< std::endl;
}
void AdvancedAccount::upgrade_account( std::string n, int m) {
	if (Account_type == 1)
		std::cout << "Already You Have Advanced Account!! AssHole" << std::endl;
	else if (Account_type ==0) {
		Account_type = 1;
		std::string temp1 = n;
		int temp2 = m;
		user_name= temp1;
		money = temp2;
	}
}
int BaseAccount::get_money (void) {
	return money;
}
std::string BaseAccount::get_name (void) {
	return user_name;
}
void AdvancedAccount::make_account(std::string n, int m) 
{
	user_name = n;
	money = m;
	Account_type = 1;
}
void BaseAccount::expiration_date (void) {
	std::cout << "�ڳ״� VIP ���� �ƴϱ� ������ ������ �̿��Ͻ� �� �����ϴ�." << std::endl;
}
void AdvancedAccount::expiration_date(void)
{	
	std::cout<<"���� ������ ���Ͻʽÿ� (Ex 10��)"<< std::endl;
	std::string date;
	std::cin >> date;
	exp_date = date;
	std::cout<<"�ݾ��� �Է��Ͻÿ�"<< std::endl;
	int temp ;
	std::cin >> temp;
	money += temp;
}
 
int main(void)
{
	std::cout << "������ �������! � ���� ���¸� ����� �����Ű���?" << std::endl;
	std::cout << "1) �⺻ ����\n2)��� ����" << std::endl;
	int temp2;
	std::cin >> temp2; // choose account type
	std::cout << "�Է¹޾ҽ��ϴ�." << std::endl;
	std::string temp3; //initialize user name
	int temp4; //initialize money
 
	BaseAccount *Acc;
	BaseAccount Ba_acc;
	AdvancedAccount Ad_acc;

	if (temp2 == 1) {
		std::cout << "1) �⺻ ������ �����ϼ̽��ϴ�.\n������ �̸��� �Է����ּ���." << std::endl;
		std::cin >> temp3;
		std::cout << "ó�� �ܾ��� �Է����ּ���." << std::endl;
		std::cin >> temp4;
		
		Acc = &Ba_acc;
		Acc->make_account(temp3, temp4);
	}
	else if (temp2 ==2) {
		std::cout << "1) ��� ������ �����ϼ̽��ϴ�.\n������ �̸��� �Է����ּ���." << std::endl;
		std::cin >> temp3;
		std::cout << "ó�� �ܾ��� �Է����ּ���." << std::endl;
		std::cin >> temp4;
		
		Acc = &Ad_acc;
		Acc->make_account(temp3, temp4);
	}
	while (1) {std::cout << "������ �۾��� �������ּ��� \n 1)��� \n 2)�Ա� \n 3)���� �絵 \n 4)���� Ȯ�� \n 5)���� ���׷��̵� \n 6)���� \n 7)���� " << std::endl;
	int temp5;
	std::cin >> temp5;

	if (temp5 == 1) {
		int temp6;
		std::cout << "�󸶸� ����Ͻðڽ��ϱ�?" << std::endl;
		std::cin >> temp6;
		if (Acc->withdraw (temp6) == 1)
			Acc->deposit (temp6);
		}
	
	else if (temp5 ==2) {
		int temp6;
		std::cout << "�󸶸� �Ա��Ͻðڽ��ϱ�?" << std::endl;
		std::cin >> temp6;
		Acc->deposit(temp6);
		}
	else if (temp5 ==3) {
		std::string temp6;
		std::cout << "�������� �絵�Ͻðڽ��ϱ�?" << std::endl;
		std::cin >> temp6;
		Acc->give_account(temp6);
		}
	else if (temp5 ==4) {
		Acc->check_account();
		}
	else if (temp5 ==5) {
		int temp1 = Acc->get_money();
		std::string temp2 = Acc->get_name();
		AdvancedAccount temp3;
		temp3.upgrade_account(temp2, temp1);
		Acc = &temp3;
		}
	else if (temp5 ==6) {
		Acc->expiration_date();
	}
	else if (temp5 ==7)
		break;
	else 
		continue;
	}
}