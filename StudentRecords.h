#pragma once

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <filesystem>

class StudentFiles {
public:
    static void OpenAndEditFile(std::string FileName, std::string NameOfStudent, char yn) {
        std::string FileLine;
        std::vector<std::string> FileLines;

        std::ifstream InFile(FileName);
        if (InFile.is_open()) {
            while (getline(InFile, FileLine)) {
                FileLines.push_back(FileLine);
                std::cout << FileLine << std::endl;
            }
            InFile.close();

            if (yn == 'y' || yn == 'Y') {
                std::cout << "Opening File Writer..." << std::endl;

                if (FileLines.empty()) {
                    FileLines.push_back("This student has no records recorded");
                }
                if(!FileLines.empty()) {
                    FileLines[0] = "This is the start of the " + NameOfStudent + " Record: ";
                }

                std::string newRecord;
                std::cout << "\nEnter the new record: ";
                std::cin.ignore();
                getline(std::cin, newRecord);

                FileLines.push_back(newRecord);
                std::string FileLine;
                std::ofstream OutFile(FileName);
                if (OutFile.is_open()) {
                    for (const auto& FileLine : FileLines) {
                        OutFile << FileLine << std::endl;
                    }
                    std::cout << "Saving..." << std::endl;
                    std::cout << "Closing file" << std::endl;
                    OutFile.close();
                }
                else {
                    InFile.close();
                }
            }
        }  
    }
    static void DeleteStudentRecord(std::string FileName, std::string NameOfStudent) {
        if (std::remove(FileName.c_str()) == 0) {
            std::cout << NameOfStudent << " Record deleted" << std::endl;
        }
        else {
            std::cout << "File could not be successfully deleted" << std::endl;
        }
    }

        static void WyattCurtis() {
            int CurtisId = 8641;
            std::string FileName1 = "WyattCurtis.txt";
            std::string NameOfStudent1 = "Wyatt Curtis";
            OpenAndEditFile(FileName1, NameOfStudent1, 'y');
        }

        static void AmirKevin() {
            int KevinId = 9103;
            std::string FileName2 = "AmirKevin.txt";
            std::string NameOfStudent2 = "Amir Kevin";
            OpenAndEditFile(FileName2, NameOfStudent2, 'y');
        }

        static void LoganKivam() {
            int KivamId = 1834;
            std::string FileName3 = "LoganKivam.txt";
            std::string NameOfStudent3 = "Logan Kivam";
            OpenAndEditFile(FileName3, NameOfStudent3, 'y');
        }

        static void DylanLeben() {
            int LebenId = 4813;
            std::string FileName4 = "DylanLeben.txt";
            std::string NameOfStudent4 = "Dylan Leben";
            OpenAndEditFile(FileName4, NameOfStudent4, 'y');
        }
};
