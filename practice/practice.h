#include <iostream>
#include <string>
 
class BaseAccount
{
protected:
	std::string user_name;
	std::string exp_date;
	int money;
	int Account_type;
public:
	virtual void make_account (std::string, int);
	int withdraw (int);
	void deposit (int);
	void give_account (std::string);
	void show_account(void);
	void check_account (void);
	int get_money (void);
	std::string get_name (void);
	
	virtual void expiration_date(void);
};

class AdvancedAccount : public BaseAccount
{
public:
	virtual void expiration_date(void);
	virtual void make_account(std::string, int);
	void upgrade_account (std::string, int);
};