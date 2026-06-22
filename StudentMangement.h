#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <cstdio>

#include "StudentRecords.h"

// Global Variables
std::vector<std::string> Students = {"Wyatt Curtis", "Amir Kevin", "Logan Kivam", "Dylan Leben"};
std::vector<int> ID = { 8641, 9103, 1834, 4813 };



class StudentMangement {
public:
	void run() {
		int input = 0;
		do {
			startup();
			input = GetInput();
		} while (input != 7);
	}

	void startup() {
		std::cout << "---------- Student Mangement System ----------" << std::endl;
		std::cout << "*  1. View All Student Records" << std::endl;
		std::cout << "*  2. Search Student Record by Id" << std::endl;
		std::cout << "*  3. Search Student Record by Name" << std::endl;
		std::cout << "*  4. Delete Student Record" << std::endl;
		std::cout << "*  5. Update Student Record" << std::endl;
		std::cout << "*  6. Display Statistics" << std::endl;
		std::cout << "*  7. Exit" << std::endl;
		std::cout << "----------------------------------------------" << std::endl;
	}

	int GetInput() {

		int input = 0;
		std::cin >> input;

		if (input == 1) {
			ViewAllStudentRecords();
		}
		else if (input == 2) {
			SearchStudentById();
		}
		else if (input == 3) {
			SearchStudentByName();
		}
		else if (input == 4) {
			DeleteAStudentFile();
		}
		else if (input == 5) {
			InsertStudentRecord();
		}
		else if (input == 6) {
			DisplayStatistics(); 
		}
		else if (input == 7) {
			
		}
		return input;
	} 

	void InsertStudentRecord() {
		std::cout << "Are you sure you would you like to update" << std::endl;
		for (const auto& thing : Students) {
			std::cout << thing << std::endl;
		}
		std::cout << "----------------------------------------------" << std::endl;
		std::string name;
		std::cin.ignore();
		getline(std::cin, name);

		if (name == "Wyatt Curtis" || name == "wyatt curtis") {
			StudentFiles::WyattCurtis();
		}
		else if(name == "Amir Kevin" || name == "amir kevin") {
			StudentFiles::AmirKevin();
		}
		else if(name == "Logan Kivam" || name == "logan kivam") {
			 StudentFiles::LoganKivam();
		}
		else if (name == "Dylan Leben" || name == "dylan leben") {
			StudentFiles::DylanLeben();
		}
		else {
			std::cout << "Student does not exist" << std::endl;
		}
	}

	void SearchStudentById() {
		std::cout << "Which ID would you like to search: " << std::endl;
		for (const auto& thing : ID) {
			std::cout << thing << std::endl;
		}
		std::cout << "----------------------------------------------" << std::endl;
		int input; std::cin >> input;
		std::cout << "" << std::endl;

		if (input == 8641) {
			StudentFiles::OpenAndEditFile("WyattCurtis.txt", "Wyatt Curtis", 'n');
		}
		else if (input == 9103) {
			StudentFiles::OpenAndEditFile("AmirKevin.txt", "Amir Kevin", 'n');
		}
		else if (input == 1834) {
			StudentFiles::OpenAndEditFile("LoganKivam.txt", "Logan Kivam", 'n');
		}
		else if (input == 4813) {
			StudentFiles::OpenAndEditFile("DylanLeben.txt", "Dylan Leben", 'n');
		}
	}

	void DisplayStatistics() {
		std::cout << "Wyatt Curtis has a F" << std::endl;
		std::cout << "Amir Kevin has a Super F" << std::endl;
		std::cout << "Logan Kivam has a B" << std::endl;
		std::cout << "Dylan Leben has a public execution on north sentinal island in 2028" << std::endl;
	}

	void SearchStudentByName() {
		std::cout << "Which Student would you like to search: " << std::endl;
		for (const auto& thing : Students) {
			std::cout << thing << std::endl;
		}
		std::cout << "----------------------------------------------" << std::endl;
		std::string inputName;
		std::cin.ignore();
		getline(std::cin, inputName);
		std::cout << "" << std::endl;

		if (inputName == "Wyatt Curtis" || inputName == "wyatt curtis") {
			StudentFiles::OpenAndEditFile("WyattCurtis.txt", "Wyatt Curtis", 'n');
		}
		else if (inputName == "Amir Kevin" || inputName == "amir kevin") {
			StudentFiles::OpenAndEditFile("AmirKevin.txt", "Amir Kevin", 'n');
		}
		else if (inputName == "Logan Kivam" || inputName == "logan kivam") {
			StudentFiles::OpenAndEditFile("LoganKivam.txt", "Logan Kivam", 'n');
		}
		else if (inputName == "Dylan Leben" || inputName == "dylan leben") {
			StudentFiles::OpenAndEditFile("DylanLeben.txt", "Dylan Leben", 'n');
		}
		else {
			std::cout << "Student does not exist" << std::endl;
		}
	}

	void DeleteAStudentFile() {
		std::cout << "Would you like to delete a student record y or n" << std::endl;
		char yn; std::cin >> yn;
		
		if (yn == 'y' || yn == 'Y') {
			std::cout << "Which Record would you like to remove: " << std::endl;
			for(const auto& thing : Students) {
				std::cout << thing << std::endl;
			}
			std::cin.ignore();
			
			std::string name;
			getline(std::cin, name);

			if(name == "Wyatt Curtis" || name == "wyatt curtis") {
				StudentFiles::DeleteStudentRecord("WyattCurtis.txt", "Wyatt Curtis");
			}
			else if (name == "Amir Kevin" || name == "amir kevin") {
				StudentFiles::DeleteStudentRecord("AmirKevin.txt", "Amir Kevin");
			}
			else if (name == "Logan Kivam" || name == "logan kivam") {
				StudentFiles::DeleteStudentRecord("LoganKivam.txt", "Logan Kivam");
			}
			else if (name == "Dylan Leben" || name == "dylan leben") {
				StudentFiles::DeleteStudentRecord("DylanLeben.txt", "Dylan Leben");
			}
			else {
				std::cout << "Student Record does not exist" << std::endl;
			}
		}
	}

	void ViewAllStudentRecords() {
		std::cout << "Wyatt Curtis:" << std::endl;
		StudentFiles::OpenAndEditFile("WyattCurtis.txt", "Wyatt Curtis", 'n');
		std::cout << "" << std::endl;
		std::cout << "Amir Kevin:" << std::endl;
		StudentFiles::OpenAndEditFile("AmirKevin.txt", "Amir Kevin", 'n');
		std::cout << "" << std::endl;
		std::cout << "Logan Kivam:" << std::endl;
		StudentFiles::OpenAndEditFile("LoganKivam.txt", "Logan Kivam", 'n');
		std::cout << "" << std::endl;
		std::cout << "Dylan Leben:" << std::endl;
		StudentFiles::OpenAndEditFile("DylanLeben.txt", "Dylan Leben", 'n');
	}
};