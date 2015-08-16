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
			std::cout << "잔액이 부족합니다. 다시입력해주세요" <<temp1<< "," <<money <<std::endl;
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
	std::cout<<"계좌주는 "<< user_name << std::endl;
	std::cout<<"잔액은 "<< money << std::endl;
	if (Account_type== 0)
		std::cout<<"계좌종류는 보통통장입니다."<< std::endl;
	else 
		std::cout<<"계좌종류는 고급통장입니다."<< std::endl;
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
	std::cout << "자네는 VIP 고객이 아니기 때문에 대출을 이용하실 수 없습니다." << std::endl;
}
void AdvancedAccount::expiration_date(void)
{	
	std::cout<<"대출 기한을 정하십시오 (Ex 10일)"<< std::endl;
	std::string date;
	std::cin >> date;
	exp_date = date;
	std::cout<<"금액을 입력하시오"<< std::endl;
	int temp ;
	std::cin >> temp;
	money += temp;
}
 
int main(void)
{
	std::cout << "농협에 어서오세요! 어떤 은행 계좌를 만들고 싶으신가요?" << std::endl;
	std::cout << "1) 기본 통장\n2)고급 통장" << std::endl;
	int temp2;
	std::cin >> temp2; // choose account type
	std::cout << "입력받았습니다." << std::endl;
	std::string temp3; //initialize user name
	int temp4; //initialize money
 
	BaseAccount *Acc;
	BaseAccount Ba_acc;
	AdvancedAccount Ad_acc;

	if (temp2 == 1) {
		std::cout << "1) 기본 통장을 선택하셨습니다.\n계좌주 이름을 입력해주세요." << std::endl;
		std::cin >> temp3;
		std::cout << "처음 잔액을 입력해주세요." << std::endl;
		std::cin >> temp4;
		
		Acc = &Ba_acc;
		Acc->make_account(temp3, temp4);
	}
	else if (temp2 ==2) {
		std::cout << "1) 고급 통장을 선택하셨습니다.\n계좌주 이름을 입력해주세요." << std::endl;
		std::cin >> temp3;
		std::cout << "처음 잔액을 입력해주세요." << std::endl;
		std::cin >> temp4;
		
		Acc = &Ad_acc;
		Acc->make_account(temp3, temp4);
	}
	while (1) {std::cout << "실행할 작업을 선택해주세요 \n 1)출금 \n 2)입금 \n 3)계좌 양도 \n 4)계좌 확인 \n 5)계좌 업그레이드 \n 6)대출 \n 7)종료 " << std::endl;
	int temp5;
	std::cin >> temp5;

	if (temp5 == 1) {
		int temp6;
		std::cout << "얼마를 출금하시겠습니까?" << std::endl;
		std::cin >> temp6;
		if (Acc->withdraw (temp6) == 1)
			Acc->deposit (temp6);
		}
	
	else if (temp5 ==2) {
		int temp6;
		std::cout << "얼마를 입금하시겠습니까?" << std::endl;
		std::cin >> temp6;
		Acc->deposit(temp6);
		}
	else if (temp5 ==3) {
		std::string temp6;
		std::cout << "누구한테 양도하시겠습니까?" << std::endl;
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