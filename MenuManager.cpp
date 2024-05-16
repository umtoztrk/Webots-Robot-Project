#include <iostream>
#include "MenuManager.h"

void MenuManager::showMotionMenu() {
    int choice;
    do {
        cout << "Motion Menu\n"
            << "1. Move robot right\n"
            << "2. Move robot left\n"
            << "3. Turn Left\n"
            << "4. Turn Right\n"
            << "5. Forward\n"
            << "6. Backward\n"
            << "7. Back\n"
            << "Choose one: ";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            nao1->moveRight();
            cout << "It is moving..." << endl;
            Sleep(8000);
            system("cls");
            break;
        case 2:
            system("cls");
            nao1->moveLeft();
            cout << "It is moving..." << endl;
            Sleep(8000);
            system("cls");
            break;
        case 3:
            system("cls");
            nao1->turnLeft();
            cout << "It is moving..." << endl;
            Sleep(8000);
            system("cls");
            break;
        case 4:
            system("cls");
            nao1->turnRight();
            cout << "It is moving..." << endl;
            Sleep(8000);
            system("cls");
            break;
        case 5:
            system("cls");
            nao1->forward();
            cout << "It is moving..." << endl;
            Sleep(8000);
            system("cls");
            break;
        case 6:
            system("cls");
            nao1->backward();
            cout << "It is moving..." << endl;
            Sleep(8000);
            system("cls");
            break;
        case 7:
            system("cls");
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}

void MenuManager::showMainMenu() {
    int choice;
    int choice2;
    do {
        cout << "Main Menu\n"
            << "1. Connection\n"
            << "2. Motion\n"
            << "3. Sensor\n"
            << "4. Add Sensor\n"
            << "5. Position\n"
            << "6. File Operations\n"
            << "7. Open Access\n"
            << "8. Close Access\n"
            << "9. Add to Path\n"
            << "10. Clear Path\n"
            << "11. Quit\n"
            << "Choose one: ";
        cin >> choice;
        switch (choice) {
        case 1:
            if (!nao1->getStatus()) {
                system("cls");
                cout << "No Access." << endl;
                break;
            }
            else {
                system("cls");
                showConnectionMenu();
                break;
            }
        case 2:
            if (!nao1->getStatus()) {
                system("cls");
                cout << "No Access." << endl;
                break;
            }
            else {
                system("cls");
                showMotionMenu();
                break;
            }
        case 3:
            if (!nao1->getStatus()) {
                system("cls");
                cout << "No Access." << endl;
                break;
            }
            else {
                system("cls");
                showSensorMenu();
                break;
            }
        case 4:
            if (!nao1->getStatus()) {
                system("cls");
                cout << "No Access." << endl;
                break;
            }
            else {
                system("cls");
                cout << "Which sensor do you want add: \n"
                    << "1.Force \n"
                    << "2.Bumper \n"
                    << "3.Sonar \n";
                cin >> choice2;
                if (choice2 == 1) {
                    if (rif->checkList("Force")) {
                        cout << "Force Sensor already added.\n";
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                    else {
                        fs = new ForceSensor();
                        nao1->addSensor(fs);
                        cout << "Force Sensor has been added.\n";
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                }
                else if (choice2 == 2) {
                    if (rif->checkList("Bumper")) {
                        cout << "Bumper Sensor already added.\n";
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                    else {
                        bs = new BumperSensor();
                        nao1->addSensor(bs);
                        cout << "Bumper Sensor has been added.\n";
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                }
                else if (choice2 == 3) {
                    if (rif->checkList("Sonar")) {
                        cout << "Sonar Sensor already added.\n";
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                    else {
                        sr = new SonarSensor();
                        nao1->addSensor(sr);
                        cout << "Sonar Sensor has been added.\n";
                        Sleep(5000);
                        system("cls");
                        break;
                    }
                }
                break;
            }
        case 5:
            if (!nao1->getStatus()) {
                system("cls");
                cout << "No Access." << endl;
                break;
            }
            else {
                system("cls");
                nao1->print();
                break;
            }
        case 6:
            if (!nao1->getStatus()) {
                system("cls");
                cout << "No Access." << endl;
                break;
            }
            else {
                system("cls");
                fileOperation();
                break;
            }
        case 7:
            system("cls");
            if (nao1->getStatus()) {
                cout << "Access already opened." << endl;
                break;
            }
            cout << "Enter a code to Open Access\n";
            cin >> choice2;
            if (nao1->openAccess(choice2)) cout << "Access opened.\n";
            else cout << "Access can not opened.\n";
            break;
        case 8:
            system("cls");
            if (!nao1->getStatus()) {
                cout << "Access already closed." << endl;
                break;
            }
            cout << "Enter a code to Close Access\n";
            cin >> choice2;
            if (!nao1->closeAccess(choice2)) cout << "Access closed.\n";
            else cout << "Access can not closed.\n";
            break;
        case 9:
            if (!nao1->getStatus()) {
                system("cls");
                cout << "No Access." << endl;
                break;
            }
            else {
                system("cls");
                nao1->addToPath();
                Sleep(3000);
                break;
            }
        case 10:
            if (!nao1->getStatus()) {
                system("cls");
                cout << "No Access." << endl;
                break;
            }
            else {
                system("cls");
                nao1->clearPath();
                Sleep(3000);
                break;
            }
        case 11:
            exit(1);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 11);
}

void MenuManager::showConnectionMenu() {
    int choice;
    do {
        cout << "Connection Menu\n"
            << "1. Connect Robot\n"
            << "2. Disconnect Robot\n"
            << "3. Back\n"
            << "Choose one: ";
        cin >> choice;
        switch (choice) {
        case 1:
            nao1->connect();
            cout << "The robot has been connected." << endl;
            Sleep(4000);
            system("cls");
            break;
        case 2:
            nao1->disconnect();
            cout << "The robot has been disconnected." << endl;
            Sleep(4000);
            system("cls");
            break;
        case 3:
            system("cls");
            showMainMenu();
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}

void MenuManager::showSensorMenu() {
    int input;
    int choice;
    string input1;
    do {
        cout << "Connection Menu\n"
            << "1. Sonar Sensor Get Range\n"
            << "2. Sonar Sensor Get Max\n"
            << "3. Sonar Sensor Get Min\n"
            << "4. Bumper Sensor Get State\n"
            << "5. Bumper Sensor Check Touch\n"
            << "6. Force Sensor Get Force\n"
            << "7. Force Sensor Check Fall\n"
            << "8. Update Sensors\n"
            << "9. Print Sensor\n"
            << "10. Back\n"
            << "Choose one: ";
        cin >> choice;
        switch (choice) {
        case 1:
            if (rif->checkList("Sonar")) {
                system("cls");
                cout << "Enter the input :";
                cin >> input;
                cout << "Range of " << input << ". sonar sensor is :" << rif->checkSensor("Sonar")->getSensorValue() << endl;
                Sleep(4000);
                system("cls");
                break;
            }
            else {
                cout << "There is no Sonar Sensor" << endl;
                Sleep(4000);
                system("cls");
                break;
            }
        case 2:
            if (rif->checkList("Sonar")) {
                SensorInterface* sensor = rif->checkSensor("Sonar");
                SonarSensor* sonarSensor = dynamic_cast<SonarSensor*>(sensor);
                system("cls");
                cout << "Enter a input :" << endl;
                cin >> input;
                cout << "Max distance of sonar sensor is :" << sonarSensor->getMax(input) << endl;
                Sleep(4000);
                system("cls");
                break;
            }
            else {
                cout << "There is no Sonar Sensor" << endl;
                Sleep(4000);
                system("cls");
                break;
            }
        case 3:
            if (rif->checkList("Sonar")) {
                SensorInterface* sensor = rif->checkSensor("Sonar");
                SonarSensor* sonarSensor = dynamic_cast<SonarSensor*>(sensor);
                system("cls");
                cout << "Enter a input :" << endl;
                cin >> input;
                cout << "Min distance of sonar sensor is :" << sonarSensor->getMin(input) << endl;
                Sleep(4000);
                system("cls");
                break;
            }
            else {
                cout << "There is no Sonar Sensor" << endl;
                Sleep(4000);
                system("cls");
                break;
            }
        case 4:
            if (rif->checkList("Bumper")) {
                SensorInterface* sensor = rif->checkSensor("Bumper");
                BumperSensor* bumperSensor = dynamic_cast<BumperSensor*>(sensor);
                system("cls");
                cout << "Enter the index :";
                cin >> input;
                cout << "State of " << input << ". bumper sensor is :" << bumperSensor->getState(input - 1) << endl;
                Sleep(4000);
                system("cls");
                break;
            }
            else {
                cout << "There is no Bumper Sensor" << endl;
                Sleep(4000);
                system("cls");
                break;
            }
        case 5:
            if (rif->checkList("Bumper")) {
                SensorInterface* sensor = rif->checkSensor("Bumper");
                BumperSensor* bumperSensor = dynamic_cast<BumperSensor*>(sensor);
                system("cls");
                if (bumperSensor->checkTouch()) cout << "There is in touch" << endl;
                else cout << "There isn't any touch." << endl;
                Sleep(5000);
                system("cls");
                break;
            }
            else {
                cout << "There is no Bumper Sensor" << endl;
                Sleep(4000);
                system("cls");
                break;
            }
        case 6:
            if (rif->checkList("Force")) {
                SensorInterface* sensor = rif->checkSensor("Force");
                ForceSensor* forceSensor = dynamic_cast<ForceSensor*>(sensor);
                cout << "Force :" << forceSensor->getForce() << endl;
                Sleep(5000);
                system("cls");
                break;
            }
            else {
                cout << "There is no Force Sensor" << endl;
                Sleep(4000);
                system("cls");
                break;
            }
        case 7:
            if (rif->checkList("Force")) {
                SensorInterface* sensor = rif->checkSensor("Force");
                ForceSensor* forceSensor = dynamic_cast<ForceSensor*>(sensor);
                if (forceSensor->CheckFall()) {
                    cout << "Robot fell." << endl;
                }
                else {
                    cout << "Robot did not fell." << endl;
                }
                Sleep(5000);
                system("cls");
                break;
            }
            else {
                cout << "There is no Force Sensor" << endl;
                Sleep(4000);
                system("cls");
                break;
            }
        case 8:
            rif->updateSensors();
            cout << "Sensors have been updated.\n";
            Sleep(5000);
            system("cls");
            break;
        case 9:
            system("cls");
            cout << "Enter Sensor name: \n";
            cin >> input1;
            if (nao1->printSensor(input1)) {}
            else {
                cout << "Specified sensor not found." << endl;
                Sleep(3000);
                system("cls");
            }
            break;
        case 10:
            system("cls");
            showMainMenu();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);
}

void MenuManager::fileOperation() {
    int choice;
    string input;
    string result;
    do {
        cout << "Enter a file name: (3 for Back)" << endl;
        cin >> input;
        system("cls");
        if (input == "3") {
            system("cls");
            showMainMenu();
            break;
        }
        rc->setFileName(input);
        cout << "Main Menu\n"
            << "1. Write Position to Line\n"
            << "2. Read Position from Line\n"
            << "3. Record Path\n"
            << "4. Record Sensor\n"
            << "5. Back\n"
            << "Choose one: ";
        cin >> choice;
        switch (choice) {
        case 1:
            system("cls");
            double sonarLeft, sonarRight;
            api->getSonarRange(sonarLeft, sonarRight);
            result += "--------------------SENSOR VALUES-------------------------------------\n";
            result += "POSE         : (X) " + std::to_string(api->getX()) + " meters, "
                + "(Y) " + std::to_string(api->getY()) + " meters, "
                + "(Th) " + std::to_string(api->getTh()) + " degrees\n\n";
            result += "SONAR RANGES : (LEFT) " + std::to_string(sonarLeft)
                + " meters, (RIGHT) " + std::to_string(sonarRight) + " meters\n\n";
            result += "FOOT FORCE   : " + std::to_string(api->getFootForce()) + " kg.f\n";
            result += "----------------------------------------------------------------------\n";
            rc->writeLine(result);
            break;
        case 2:
            system("cls");
            cout << rc->readLine() << endl;
            break;
        case 3:
            system("cls");
            if (nao1->recordPathToFile(rc)) {
                cout << "Path recorded to file successfully." << endl;
            }
            else {
                cout << "Path is empty. Nothing to record." << endl;
            }
            Sleep(3000);
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "Enter Sensor name: \n";
            cin >> input;
            if (nao1->recordSensor(input, rc)) {
                cout << "Sensor recorded successfully." << endl;
            }
            else {
                cout << "Specified sensor not found." << endl;
            }
            Sleep(3000);
            system("cls");
            break;
        case 5:
            system("cls");
            showMainMenu();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
}

void MenuManager::checkPassword() {
    int choice = 0;
    int remainingAttempts = 3;
    int password;
    while (1) {
        if (remainingAttempts == 0) {
            cout << "Exiting the program..." << endl;
            Sleep(3000);
            exit(1);
        }
        cout << "Enter a password to access Main Menu: " << endl;
        cin >> password;
        bool accessGranted = ro->checkAccessCode(ro->decryptCode(password));
        if (accessGranted) {
            showMainMenu();
        }
        else {
            cout << "Wrong Password" << endl;
            remainingAttempts--;
            cout << remainingAttempts << " tries left" << endl;
        }
    }
}