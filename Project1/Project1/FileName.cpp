#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>

struct User {
	std::string usernames = "";
	std::string email = "";
	std::string password = "";
};

class Database {
	std::vector<User> DB;
	std::string filename;
public:
	Database() : filename("users.txt") {
		std::cout << "Database has been initialized\n";
		this->load();
	}

	void add_user(std::string name, std::string mail, std::string _pass) {
		User user;
		user.usernames = name;
		user.email = mail;
		user.password = _pass;
		DB.push_back(user);
		std::cout << "User " << user.usernames << " has been added\n";
	}

	User get_user_by_name(std::string name) {
		for (int i = 0; i < DB.size(); i++) {
			if (DB[i].usernames == name) {
				return DB[1];
			}
		}
		User user;
		return user;
	}

	User get_user_by_email(std::string mail) {
		for (int i = 0; i < DB.size(); i++) {
			if (DB[i].email == mail) {
				return DB[1];
			}
		}
		User user;
		return user;
	}

	void print_user_data(User user) {
		std::cout << "Name\t\t" << user.usernames << '\n'
			<< "E-mail\t\t" << user.email << '\n'
			<< "Password\t" << user.password << "\n\n";
	}

	void print_all_users() {
		std::string be = "==================================================\n\n";
		for (User user : DB) {
			std::cout << be;
			print_user_data(user);
			std::cout << be;
		}
	}

	void save() {
		std::ofstream file(this->filename);
		if (file.is_open()) {
			for (int i = 0; i < DB.size(); i++) {
				file << DB[i].usernames << std::endl;
				file << DB[i].email << std::endl;
				file << DB[i].password << std::endl;
			}
			file.close();
			std::cout << "Users have been saved\n";
		}
	}

private:
	void load() {
		std::ifstream file(this->filename);
		if (file.is_open()) {
			User user;
			std::string line;
			int line_count = 0;
			while (std::getline(file, line)) {
				if (line_count % 3 == 0) {
					user.usernames = line;
				}
				else if (line_count % 3 == 1) {
					user.email = line;
				}
				else if (line_count % 3 == 2) {
					user.password = line;
					this->DB.push_back(user);
				}
				line_count++;
			}
			file.close();
			std::cout << "Data loaded!\n";
		}
	}
};

class Actions {
public:
	static void Add(Database& db) {
		std::string email, name, password;
		std::cout << "Enter e-mail: "; std::cin >> email;

		if (db.get_user_by_email(email).email == email) {
			std::cout << "User with that email already exists!\n";
			return;
		}
		std::cout << "Enter name: "; std::cin >> name;
		std::cout << "Enter password: "; std::cin >> password;
		db.add_user(name, email, password);
	}

	static void list_all(Database& db) {
		db.print_all_users();
	}

	static void Print(Database& db) {
		std::string mail;
		std::cout << "Enter user's email:"; std::cin >> mail;
		db.print_user_data(db.get_user_by_email(mail));
	}

	static void Quit(Database& db) {
		db.save();
		exit(0);
	}
};

Database* base = nullptr;

BOOL WINAPI ConsoleHandler(DWORD chandler) {
	if (chandler == CTRL_CLOSE_EVENT) {
		base->save();
	}
	return TRUE;
}

int main() {
	setlocale(0, "ru");

	Database db;
	base = &db;

	int choice;

	SetConsoleCtrlHandler(ConsoleHandler, TRUE);

	while (true) {
		std::cout << "\t\t\t===== MENU =====\n";
		std::cout << "\t\t1. Add new user\n";
		std::cout << "\t\t2. List all user\n";
		std::cout << "\t\t3. Show user's data\n";
		std::cout << "\t\t4. Quit\n";
		std::cout << "Choose option: ";

		while (!(std::cin >> choice)) {
			std::cout << "ERROR\n";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "Choose option: ";
		}

		std::cout << "\n\n";
		switch (choice) {
		case 1:
			Actions::Add(db);
			break;
		case 2:
			Actions::list_all(db);
			break;
		case 3:
			Actions::Print(db);
			break;
		case 4:
			Actions::Quit(db);
			break;
		}
	}
	return 0;
}