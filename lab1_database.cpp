#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <iomanip>
struct Auto {
	int id;
	std::string brand;
	std::string model;
	int model_year;
	std::string serial_number;
	std::string type;
	std::string color;
	int owner_id;
	bool stolen = false;
	bool tech_inspection = false;
};

struct Owner {
	int id;
	std::string full_name;
	int age;
	std::string passport_id;
	std::string place_of_living;
};

void add_auto() {
	Auto auto_to_add;
	std::cout << "Enter id of car: ";
	std::cin >> auto_to_add.id;
	std::cout << "Enter brand of car: ";
	std::cin >> auto_to_add.brand;
	std::cout << "Enter model of car: ";
	std::cin >> auto_to_add.model;
	std::cout << "Enter model year of car: ";
	std::cin >> auto_to_add.model_year;
	std::cout << "Enter serial number of car: ";
	std::cin >> auto_to_add.serial_number;
	std::cout << "Enter color of car: ";
	std::cin >> auto_to_add.color;
	std::cout << "Enter type of car: ";
	std::cin >> auto_to_add.type;
	std::cout << "Enter owner id of ca r: ";
	std::cin >> auto_to_add.owner_id;
	std::cout << "Enter yes or y if car had tech inspection: ";
	std::string check;
	std::cin >> check;
	if (check == "y" || check == "yes" || check == "Y" || check == "Yes") {
		auto_to_add.tech_inspection = true;
	}
	else {
		auto_to_add.tech_inspection = false;

	}
	std::ofstream fout("Auto_Base.txt", std::ofstream::app);
	fout << auto_to_add.id << "  " << auto_to_add.brand << " " << auto_to_add.model << " " <<auto_to_add.model_year << " " <<auto_to_add.serial_number << " " << auto_to_add.color << " " << auto_to_add.type << " ";
	fout <<auto_to_add.owner_id << " " << auto_to_add.stolen << " " << auto_to_add.tech_inspection << std::endl;
	fout.close();
}
void add_owner() {
		Owner owner_to_add;
		std::cout << "Enter id of owner: ";
		std::cin >> owner_to_add.id;

		std::cout << "Enter name of owner: ";
		std::cin >> owner_to_add.;
		int id;
		std::string full_name;
		int age;
		std::string passport_id;
		std::string place_of_living;
		
		std::ofstream fout("Owner_Base.txt", std::ofstream::app);
		fout << auto_to_add.id << "  " << auto_to_add.brand << " " << auto_to_add.model << " " << auto_to_add.model_year << " " << auto_to_add.serial_number << " " << auto_to_add.color << " " << auto_to_add.type << " ";
		fout << auto_to_add.owner_id << " " << auto_to_add.stolen << " " << auto_to_add.tech_inspection << std::endl;
		fout.close();
	}
 }
int Auto_Num() {
	int numLines = 0;
	std::ifstream in("Auto_Base.txt");
	std::string unused;
	while (std::getline(in, unused))
		++numLines;
	return numLines;
}
void modify_autobase() {
	Auto mercedes, modify;
	std::cout << "Enter id of auto to modify:";
	int id_a;
	std::cin >> id_a;
	std::ifstream fin("Auto_Base.txt");
	std::ofstream fout("temp.txt");
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number;
		fin >> mercedes.color >> mercedes.type >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.id == id_a) {
			int choice;
			std::cout << "Which key do you want to be changed:\n";
			std::cout << "1) ID\n";
			std::cout << "2) Brand\n";
			std::cout << "3) Model\n";
			std::cout << "4) Model Year\n";
			std::cout << "5) Serial Number\n";
			std::cout << "6) Color\n";
			std::cout << "7) Type\n";
			std::cout << "8) Owner ID\n";
			std::cout << "9) Stolen\n";
			std::cout << "10) Tech Inspection\n";
			std::cin >> choice;
			switch (choice) {
				case 1:
					
					std::cout << "Enter new id:";
					std::cin >> modify.id;
					mercedes.id = modify.id;
					break;
				case 2:
					std::cout << "Enter new brand:";
					std::cin >> modify.brand;
					mercedes.brand = modify.brand;
					break;
				case 3:
					std::cout << "Enter new model:";
					std::cin >> modify.model;
					mercedes.model = modify.model;
					break;
				case 4:
					std::cout << "Enter new model year:";
					std::cin >> modify.model_year;
					mercedes.model_year = modify.model_year;
					break;
				case 5:
					std::cout << "Enter new serial number year:";
					std::cin >> modify.serial_number;
					mercedes.serial_number = modify.serial_number;
					break;
				case 6:
					std::cout << "Enter new color:";
					std::cin >> modify.color;
					mercedes.color = modify.color;
					break;
				case 7:
					std::cout << "Enter new type:";
					std::cin >> modify.type;
					mercedes.type = modify.type;
					break;
				case 8:
					std::cout << "Enter new model year:";
					std::cin >> modify.owner_id;
					mercedes.owner_id = modify.owner_id;
					break;
				case 9:
					std::cout << "Enter whether car was stolen:";
					std::cin >> modify.stolen;
					mercedes.stolen = modify.stolen;
					break;
				case 10:
					std::cout << "Enter whether car had tech inspection:";
					std::cin >> modify.tech_inspection;
					mercedes.tech_inspection = modify.tech_inspection;
					break;
				default:
					std::cout << "You entered wrong number!\n";
					break;
			}

		}
		fout << mercedes.id << "  " << mercedes.brand << " " << mercedes.model << " " << mercedes.model_year << " " << mercedes.serial_number << " ";
		fout << mercedes.color << " " << mercedes.type << " " << mercedes.owner_id << " " << mercedes.stolen << " " << mercedes.tech_inspection << std::endl;
	}
	fin.close();
	fout.close();
	remove("Auto_Base.txt");
	rename("temp.txt", "Auto_Base.txt");
}

void show_Auto_Base() {
	int width = 18;
	char sep = ' ';
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
		std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
		std::cout << std::endl;
	}
	fin.close();
}
void search_by_id() {
	 int id;
	int width = 18;
	char sep = ' ';
	std::cout << "Enter id of car:";
	std::cin >> id;
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.id == id) {
			
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
			std::cout << std::endl;
		}
		else {
			continue;
		}
	}
	fin.close();
}
void search_by_brand() {
	std::string brand;
	int width = 18;
	char sep = ' ';
	std::cout << "Enter brand of car:";
	std::cin >> brand;
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.brand == brand) {
			
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
			std::cout << std::endl;
		}
		else {
			continue;
		}
	}
	fin.close();
}
void search_by_model() {
	std::string model;
	int width = 18;
	char sep = ' ';
	std::cout << "Enter model of car:";
	std::cin >> model;
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.model == model) {

			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
			std::cout << std::endl;
		}
		else {
			continue;
		}
	}
}

void search_by_model_year() {
	int model_year;
	int width = 18;
	char sep = ' ';
	std::cout << "Enter model year of car:";
	std::cin >> model_year;
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.model_year == model_year) {

			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
			std::cout << std::endl;
		}
		else {
			continue;
		}
	}
}
void search_by_serial_number() {
	std::string serial_number;
	int width = 18;
	char sep = ' ';
	std::cout << "Enter serial number of car:";
	std::cin >> serial_number;
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.serial_number == serial_number) {

			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
			std::cout << std::endl;
		}
		else {
			continue;
		}
	}
}
void search_by_color() {
	std::string color;
	int width = 18;
	char sep = ' ';
	std::cout << "Enter color of car:";
	std::cin >> color;
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.color == color) {

			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
			std::cout << std::endl;
		}
		else {
			continue;
		}
	}
}
void search_by_type() {
	std::string type;
	int width = 18;
	char sep = ' ';
	std::cout << "Enter type of car:";
	std::cin >> type;
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.type == type) {

			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
			std::cout << std::endl;
		}
		else {
			continue;
		}
	}
}
void search_by_owner() {
	int owner;
	int width = 18;
	char sep = ' ';
	std::cout << "Enter owner of car:";
	std::cin >> owner;
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.owner_id  == owner) {

			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
			std::cout << std::endl;
		}
		else {
			continue;
		}
	}
}
void stolen_filter() {
	bool stolen;
	int width = 18;
	char sep = ' ';
	std::cout << "Stolen car filter(0/1):";
	std::cin >> stolen;
	Auto mercedes;
	std::ifstream fin("Auto_Base.txt");
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Brand";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Model Year";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Serial Number";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Color";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Type";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Owner ID";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Stolen";
	std::cout << std::left << std::setw(width) << std::setfill(sep) << "Tech Inspection";
	std::cout << std::endl;
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number >> mercedes.color >> mercedes.type;
		fin >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.stolen == stolen) {

			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.brand;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.model_year;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.serial_number;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.color;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.type;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.owner_id;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.stolen;
			std::cout << std::left << std::setw(width) << std::setfill(sep) << mercedes.tech_inspection;
			std::cout << std::endl;
		}
		else {
			continue;
		}
	}
}
void delete_Auto_from_Base() {
	Auto mercedes;
	std::cout << "Enter id of auto to delete:";
	int id_a;
	std::cin >> id_a;
	std::ifstream fin("Auto_Base.txt");
	std::ofstream fout("temp.txt");
	for (int i = 0; i < Auto_Num(); i++) {
		fin >> mercedes.id >> mercedes.brand >> mercedes.model >> mercedes.model_year >> mercedes.serial_number;
		fin >> mercedes.color >> mercedes.type >> mercedes.owner_id >> mercedes.stolen >> mercedes.tech_inspection;
		if (mercedes.id == id_a) {
			continue;
		}
		fout << mercedes.id << "  " << mercedes.brand << " " << mercedes.model << " " << mercedes.model_year << " " << mercedes.serial_number << " ";
		fout << mercedes.color <<" "<<mercedes.type << " " << mercedes.owner_id << " " << mercedes.stolen << " " << mercedes.tech_inspection << std::endl;
	}
	fin.close();
	fout.close();
	remove("Auto_Base.txt");
	rename("temp.txt", "Auto_Base.txt");
}
void menu() {
	std::cout << "1. Show database content.\n";
	std::cout << "2. Search element by id.\n";
	std::cout << "3. Search element by key.\n";
	std::cout << "4. Add new element.\n";
	std::cout << "5. Delete element by id.\n";
	std::cout << "6. Modify element by id.\n";
	std::cout << "7. Exit.\n";

}
void search_by_key() {
	int key;
	std::cout << "Enter a key to search(1-10):" << std::endl;
	std::cout << "1) ID\n";
	std::cout << "2) Brand\n";
	std::cout << "3) Model\n";
	std::cout << "4) Model Year\n";
	std::cout << "5) Serial Number\n";
	std::cout << "6) Color\n";
	std::cout << "7) Type\n";
	std::cout << "8) Owner ID\n";
	std::cout << "9) Stolen\n";
	std::cout << "10) Tech Inspection\n";
	std::cin >> key;
	switch (key) {
		case 1:
			search_by_id();
			break;
		case 2:
			search_by_brand();
			break;
		case 3:
			search_by_model();
			break;
		case 4:
			search_by_model_year();
			break;
		case 5:
			search_by_serial_number();
			break;
		case 6:
			search_by_color();
			break;
		case 7:
			search_by_type();
			break;
		case 8 :
			search_by_owner();
			break;
		case 9:
			stolen_filter();
			break;
		case 10:
			std::cout << "GG\n";
			break;
		default:
			break;
	}
}
int main() {
	while (true) {
		int choose;
		menu();
		std::cin >> choose;
		switch (choose) {
			case 1:
				show_Auto_Base();
				break;
			case 2:
				search_by_id();
				break;
			case 3:
				search_by_key();
				break;
			case 4:
				add_auto();
				break;
			case 5:
				delete_Auto_from_Base();
				break;
			case 6:
				modify_autobase();
				break;
			case 7:
				return 0; 
				break;
			default:
				break;


		}
	}
	
}