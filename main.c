#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct Patient {
    char patientID[10];
    char fullName[50];
    int age;
    char dob[15];
    char gender[10];
    char bloodGroup[5];
    char contact[15];
    char email[50];
    char address[100];
    
    char medicalHistory[100];
    char currentSymptoms[100];
    char currentMedications[100];
    char doctorAssigned[50];
    char appointmentDate[15];
    
    char emergencyContactName[50];
    char emergencyContactNumber[15];

    char username[20];
    char password[20];
    
    struct Patient *next; 
} Patient;

Patient *head = NULL; 

void patientInterface();
void addNewPatient();
void patientMenu();
void viewPatientRecord();
void updatePatientRecord();
void changePatientPassword();
void adminLogin();
void adminInterface();
void generatePatientID(char *id);
void type(const char *text);
void viewAllPatients(); 
void searchPatientByID();
void deletePatientRecord();
void changeAdminPassword();
void loadPatientsFromFile();

int main()
{
    int choice;
    loadPatientsFromFile();
    while (1){                                 
    system("cls");                          
    printf("\n\n\t\t\t\t\t\tHOSPITAL MANAGEMENT PATIENT SCHEDULING SYSTEM\t\t\t\t\t\t\n\n\n");
    printf("\t\t\t\t\t\t\t Select Login Type \t\t\t\t\t\t\n");
    printf("=====================================================================================================================================\n\n");
    printf("1.\tPatient\n");
    printf("2.\tDoctor\n");
    printf("3.\tAdmin\n");
    printf("4.\tExit\n\n");
    printf("=====================================================================================================================================\n\n");
    type("Enter your choice(1-4):\t");    
    scanf("%d", &choice);
    getchar();
    switch (choice){
        case 1:
            system("cls");
            patientInterface();
            break;
        case 2:
            system("cls");
            break;
        case 3:
            system("cls");
            adminLogin();
            break;
        case 4:
            system("cls");
            type("Exiting the program.  \n");
            return 0;
        default:
            printf("\033[31mInvalid Choice. Please try again.\033[0m\n");      
        }
    printf("\nPress Enter to return to the dashboard...");                                          
    getchar();
    }
    return 0;
}

void patientInterface() {
    int choice;
    system("cls");
    printf("=====================================================================================================================================\n\n");
    printf("\t\t\t\t\t\t\t PATIENT PORTAL\n");
    printf("=====================================================================================================================================\n\n");
    printf("1. New Registration\n");
    printf("2. Already Registered (Login)\n");
    printf("3. Back to Main Menu\n\n");
    printf("=====================================================================================================================================\n");
    type("Enter your choice (1-3): ");
    scanf("%d", &choice);
    getchar();
    switch(choice) {
        case 1:
            system("cls");
            addNewPatient();
            break;
        case 2:
            system("cls");
            patientMenu();
            break;
        case 3:
            return;
        default:
            printf("\033[31mInvalid choice. Please try again.\033[0m\n");
    }
}

void addNewPatient() {
    Patient *newPatient = (Patient*)malloc(sizeof(Patient));
    if (newPatient == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    system("cls");
    printf("=====================================================================================================================================\n\n");
    printf("\t\t\t\t\t\t\t ADD NEW PATIENT DETAILS\n");
    printf("=====================================================================================================================================\n\n");

    generatePatientID(newPatient->patientID);
    strcpy(newPatient->username, newPatient->patientID);

    printf("Generated Patient ID: %s\n", newPatient->patientID);

    printf("Set Password for Patient: ");
    fgets(newPatient->password, sizeof(newPatient->password), stdin);
    newPatient->password[strcspn(newPatient->password, "\n")] = '\0';

    printf("\n--- Basic Information ---\n");
    printf("Full Name: ");
    fgets(newPatient->fullName, sizeof(newPatient->fullName), stdin);
    newPatient->fullName[strcspn(newPatient->fullName, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &newPatient->age);
    getchar(); 

    printf("Date of Birth (DD/MM/YYYY): ");
    fgets(newPatient->dob, sizeof(newPatient->dob), stdin);
    newPatient->dob[strcspn(newPatient->dob, "\n")] = '\0';

    printf("Gender (Male/Female/Other): ");
    fgets(newPatient->gender, sizeof(newPatient->gender), stdin);
    newPatient->gender[strcspn(newPatient->gender, "\n")] = '\0';

    printf("Blood Group: ");
    fgets(newPatient->bloodGroup, sizeof(newPatient->bloodGroup), stdin);
    newPatient->bloodGroup[strcspn(newPatient->bloodGroup, "\n")] = '\0';

    printf("Contact Number: ");
    fgets(newPatient->contact, sizeof(newPatient->contact), stdin);
    newPatient->contact[strcspn(newPatient->contact, "\n")] = '\0';

    printf("Email Address: ");
    fgets(newPatient->email, sizeof(newPatient->email), stdin);
    newPatient->email[strcspn(newPatient->email, "\n")] = '\0';

    printf("Address (City, State, ZIP): ");
    fgets(newPatient->address, sizeof(newPatient->address), stdin);
    newPatient->address[strcspn(newPatient->address, "\n")] = '\0';

    printf("\n--- Medical Information ---\n");
    printf("Medical History / Pre-existing Conditions: ");
    fgets(newPatient->medicalHistory, sizeof(newPatient->medicalHistory), stdin);
    newPatient->medicalHistory[strcspn(newPatient->medicalHistory, "\n")] = '\0';

    printf("Current Symptoms / Reason for Visit: ");
    fgets(newPatient->currentSymptoms, sizeof(newPatient->currentSymptoms), stdin);
    newPatient->currentSymptoms[strcspn(newPatient->currentSymptoms, "\n")] = '\0';

    printf("Current Medications: ");
    fgets(newPatient->currentMedications, sizeof(newPatient->currentMedications), stdin);
    newPatient->currentMedications[strcspn(newPatient->currentMedications, "\n")] = '\0';

    printf("Doctor Assigned: ");
    fgets(newPatient->doctorAssigned, sizeof(newPatient->doctorAssigned), stdin);
    newPatient->doctorAssigned[strcspn(newPatient->doctorAssigned, "\n")] = '\0';

    printf("Appointment/Admission Date (DD/MM/YYYY): ");
    fgets(newPatient->appointmentDate, sizeof(newPatient->appointmentDate), stdin);
    newPatient->appointmentDate[strcspn(newPatient->appointmentDate, "\n")] = '\0';

    printf("\n--- Administrative Information ---\n");
    printf("Emergency Contact Name: ");
    fgets(newPatient->emergencyContactName, sizeof(newPatient->emergencyContactName), stdin);
    newPatient->emergencyContactName[strcspn(newPatient->emergencyContactName, "\n")] = '\0';

    printf("Emergency Contact Number: ");
    fgets(newPatient->emergencyContactNumber, sizeof(newPatient->emergencyContactNumber), stdin);
    newPatient->emergencyContactNumber[strcspn(newPatient->emergencyContactNumber, "\n")] = '\0';

    newPatient->next = NULL;
    if (head == NULL) {
        head = newPatient;
    } else {
        Patient *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newPatient;
    }

    FILE *fp = fopen("patients.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        free(newPatient);
        return;
    }

    fprintf(fp,
        "%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
        newPatient->patientID,
        newPatient->password,
        newPatient->fullName,
        newPatient->age,
        newPatient->dob,
        newPatient->gender,
        newPatient->bloodGroup,
        newPatient->contact,
        newPatient->email,
        newPatient->address,
        newPatient->medicalHistory,
        newPatient->currentSymptoms,
        newPatient->currentMedications,
        newPatient->doctorAssigned,
        newPatient->appointmentDate,
        newPatient->emergencyContactName,
        newPatient->emergencyContactNumber
    );

    fclose(fp);

    printf("\n\033[32mPatient Registered Successfully!\033[0m\n");
    printf("Your Patient ID: %s\n", newPatient->patientID);
    printf("Please remember your ID and Password for login.\n\n");
}
void patientMenu() {
    int choice;
    system("cls");
    printf("=====================================================================\n");
    printf("\t\t\t PATIENT PORTAL\n");
    printf("=====================================================================\n");
    printf("1. View Personal Record\n");
    printf("2. Update Personal Information\n");
    printf("3. Book Appointments\n");
    printf("4. View Appointments\n");
    printf("5. Change Password\n");
    printf("6. Logout\n");
    printf("=====================================================================\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);
    getchar();
    switch(choice) {
        case 1: viewPatientRecord(); break;
        case 2: updatePatientRecord(); break;
        case 5: changePatientPassword(); break;
        case 6: return;
        default: 
            printf("Invalid choice! Please try again.\n");
            patientMenu();
    }
}
void viewPatientRecord() {
    char patientID[20], password[20];
    printf("\nEnter Patient ID: ");
    scanf("%s", patientID);
    printf("Enter Password: ");
    scanf("%s", password);

    FILE *fp = fopen("patients.txt", "r");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    char line[1000];
    int found = 0;

    while (fgets(line, sizeof(line), fp)) {
        char id[20], pass[20], name[50], dob[15], gender[10], blood[5], contact[15], email[50], address[100];
        char medHistory[100], symptoms[100], medications[100], doctor[50], appointment[15], emergencyName[50], emergencyNumber[15];
        int age;

        int n = sscanf(line, "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]",
            id, pass, name, &age, dob, gender, blood, contact, email, address,
            medHistory, symptoms, medications, doctor, appointment, emergencyName, emergencyNumber);

        if (n == 17 && strcmp(id, patientID) == 0 && strcmp(pass, password) == 0) {
            found = 1;
            printf("\n===== PATIENT RECORD =====\n");
            printf("Patient ID     : %s\n", id);
            printf("Full Name      : %s\n", name);
            printf("Age            : %d\n", age);
            printf("DOB            : %s\n", dob);
            printf("Gender         : %s\n", gender);
            printf("Blood Group    : %s\n", blood);
            printf("Contact        : %s\n", contact);
            printf("Email          : %s\n", email);
            printf("Address        : %s\n", address);
            printf("Medical History: %s\n", medHistory);
            printf("Symptoms       : %s\n", symptoms);
            printf("Medications    : %s\n", medications);
            printf("Doctor Assigned: %s\n", doctor);
            printf("Appointment    : %s\n", appointment);
            printf("Emergency Name : %s\n", emergencyName);
            printf("Emergency No.  : %s\n", emergencyNumber);
            printf("============================\n");
            break;
        }
    }
    if (!found) {
        printf("\nInvalid Patient ID or Password!\n");
    }
    fclose(fp);
    printf("\nPress Enter to continue...");
    getchar();
}
void updatePatientRecord() {
    char searchID[20];
    int found = 0, choice;
    Patient p;
    FILE *fp, *temp;
    fp = fopen("patients.txt", "r");
    temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("Error opening file.\n");
        return;
    }
    printf("\nEnter Patient ID to update: ");
    scanf("%s", searchID);
    getchar();
    while (fscanf(fp,
        "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",
        p.patientID, p.password, p.fullName, &p.age, p.dob, p.gender,
        p.bloodGroup, p.contact, p.email, p.address, p.medicalHistory,
        p.currentSymptoms, p.currentMedications, p.doctorAssigned,
        p.appointmentDate, p.emergencyContactName, p.emergencyContactNumber) == 17)
    {
        if (strcmp(p.patientID, searchID) == 0) {
            found = 1;
            printf("\n================ CURRENT PATIENT DETAILS ================\n");
            printf("1. Full Name          : %s\n", p.fullName);
            printf("2. Age                : %d\n", p.age);
            printf("3. DOB                : %s\n", p.dob);
            printf("4. Gender             : %s\n", p.gender);
            printf("5. Blood Group        : %s\n", p.bloodGroup);
            printf("6. Contact            : %s\n", p.contact);
            printf("7. Email              : %s\n", p.email);
            printf("8. Address            : %s\n", p.address);
            printf("9. Medical History    : %s\n", p.medicalHistory);
            printf("10. Current Symptoms  : %s\n", p.currentSymptoms);
            printf("11. Current Medications: %s\n", p.currentMedications);
            printf("12. Doctor Assigned   : %s\n", p.doctorAssigned);
            printf("13. Appointment Date  : %s\n", p.appointmentDate);
            printf("14. Emergency Name    : %s\n", p.emergencyContactName);
            printf("15. Emergency Number  : %s\n", p.emergencyContactNumber);
            printf("=========================================================\n");

            printf("\nEnter the number of the field you want to update (1-15): ");
            scanf("%d", &choice);
            getchar();

            switch (choice) {
                case 1:
                    printf("Enter new Full Name: ");
                    fgets(p.fullName, sizeof(p.fullName), stdin);
                    p.fullName[strcspn(p.fullName, "\n")] = '\0';
                    break;
                case 2:
                    printf("Enter new Age: ");
                    scanf("%d", &p.age);
                    getchar();
                    break;
                case 3:
                    printf("Enter new DOB (DD/MM/YYYY): ");
                    fgets(p.dob, sizeof(p.dob), stdin);
                    p.dob[strcspn(p.dob, "\n")] = '\0';
                    break;
                case 4:
                    printf("Enter new Gender: ");
                    fgets(p.gender, sizeof(p.gender), stdin);
                    p.gender[strcspn(p.gender, "\n")] = '\0';
                    break;
                case 5:
                    printf("Enter new Blood Group: ");
                    fgets(p.bloodGroup, sizeof(p.bloodGroup), stdin);
                    p.bloodGroup[strcspn(p.bloodGroup, "\n")] = '\0';
                    break;
                case 6:
                    printf("Enter new Contact Number: ");
                    fgets(p.contact, sizeof(p.contact), stdin);
                    p.contact[strcspn(p.contact, "\n")] = '\0';
                    break;
                case 7:
                    printf("Enter new Email: ");
                    fgets(p.email, sizeof(p.email), stdin);
                    p.email[strcspn(p.email, "\n")] = '\0';
                    break;
                case 8:
                    printf("Enter new Address: ");
                    fgets(p.address, sizeof(p.address), stdin);
                    p.address[strcspn(p.address, "\n")] = '\0';
                    break;
                case 9:
                    printf("Enter new Medical History: ");
                    fgets(p.medicalHistory, sizeof(p.medicalHistory), stdin);
                    p.medicalHistory[strcspn(p.medicalHistory, "\n")] = '\0';
                    break;
                case 10:
                    printf("Enter new Current Symptoms: ");
                    fgets(p.currentSymptoms, sizeof(p.currentSymptoms), stdin);
                    p.currentSymptoms[strcspn(p.currentSymptoms, "\n")] = '\0';
                    break;
                case 11:
                    printf("Enter new Current Medications: ");
                    fgets(p.currentMedications, sizeof(p.currentMedications), stdin);
                    p.currentMedications[strcspn(p.currentMedications, "\n")] = '\0';
                    break;
                case 12:
                    printf("Enter new Doctor Assigned: ");
                    fgets(p.doctorAssigned, sizeof(p.doctorAssigned), stdin);
                    p.doctorAssigned[strcspn(p.doctorAssigned, "\n")] = '\0';
                    break;
                case 13:
                    printf("Enter new Appointment Date (DD/MM/YYYY): ");
                    fgets(p.appointmentDate, sizeof(p.appointmentDate), stdin);
                    p.appointmentDate[strcspn(p.appointmentDate, "\n")] = '\0';
                    break;
                case 14:
                    printf("Enter new Emergency Contact Name: ");
                    fgets(p.emergencyContactName, sizeof(p.emergencyContactName), stdin);
                    p.emergencyContactName[strcspn(p.emergencyContactName, "\n")] = '\0';
                    break;
                case 15:
                    printf("Enter new Emergency Contact Number: ");
                    fgets(p.emergencyContactNumber, sizeof(p.emergencyContactNumber), stdin);
                    p.emergencyContactNumber[strcspn(p.emergencyContactNumber, "\n")] = '\0';
                    break;
                default:
                    printf("\nInvalid choice! No updates made.\n");
            }
            printf("\n Record updated successfully!\n");
        }
        fprintf(temp,
            "%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
            p.patientID, p.password, p.fullName, p.age, p.dob, p.gender,
            p.bloodGroup, p.contact, p.email, p.address, p.medicalHistory,
            p.currentSymptoms, p.currentMedications, p.doctorAssigned,
            p.appointmentDate, p.emergencyContactName, p.emergencyContactNumber);
    }
    fclose(fp);
    fclose(temp);
    remove("patients.txt");
    rename("temp.txt", "patients.txt");
    if (!found)
        printf("\n No patient found with ID: %s\n", searchID);
}
void changePatientPassword() {
    char patientID[20], oldPass[20], newPass[20], confirmPass[20];
    int found = 0;
    Patient p;
    FILE *fp, *temp;

    fp = fopen("patients.txt", "r");
    temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter Patient ID: ");
    scanf("%s", patientID);
    printf("Enter Old Password: ");
    scanf("%s", oldPass);

    while (fscanf(fp,
        "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",
        p.patientID, p.password, p.fullName, &p.age, p.dob, p.gender,
        p.bloodGroup, p.contact, p.email, p.address, p.medicalHistory,
        p.currentSymptoms, p.currentMedications, p.doctorAssigned,
        p.appointmentDate, p.emergencyContactName, p.emergencyContactNumber) == 17)
    {
        if (strcmp(p.patientID, patientID) == 0 && strcmp(p.password, oldPass) == 0) {
            found = 1;

            printf("\nEnter New Password: ");
            scanf("%s", newPass);
            printf("Confirm New Password: ");
            scanf("%s", confirmPass);

            if (strcmp(newPass, confirmPass) == 0) {
                strcpy(p.password, newPass);
                printf("\nPassword changed successfully!\n");
            } else {
                printf("\nPasswords do not match! Try again.\n");
            }
        }

        fprintf(temp,
            "%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
            p.patientID, p.password, p.fullName, p.age, p.dob, p.gender,
            p.bloodGroup, p.contact, p.email, p.address, p.medicalHistory,
            p.currentSymptoms, p.currentMedications, p.doctorAssigned,
            p.appointmentDate, p.emergencyContactName, p.emergencyContactNumber);
    }

    fclose(fp);
    fclose(temp);

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (!found) {
        printf("\nInvalid Patient ID or Old Password!\n");
    }

    printf("\nPress Enter to continue...");
    getchar(); getchar();
}

void generatePatientID(char *id) {
    srand(time(NULL) + rand());
    int num = rand() % 9000 + 1000;
    sprintf(id, "PAT%d", num);
}
void type(const char *text) {
    while (*text) {
        printf("%c", *text++);
        fflush(stdout);
        Sleep(60); 
    }
}
void loadPatientsFromFile() {
    FILE *fp = fopen("patients.txt", "r");
    if (!fp) return;

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        Patient *newPatient = (Patient*)malloc(sizeof(Patient));
        if (!newPatient) { fclose(fp); return; }
        memset(newPatient, 0, sizeof(Patient));

        int fields = sscanf(line,
            "%9[^\t]\t%19[^\t]\t%49[^\t]\t%d\t%14[^\t]\t%9[^\t]\t%4[^\t]\t%14[^\t]\t%49[^\t]\t%99[^\t]\t%99[^\t]\t%99[^\t]\t%49[^\t]\t%14[^\t]\t%49[^\t]\t%14[^\n]",
            newPatient->patientID, newPatient->password, newPatient->fullName, &newPatient->age,
            newPatient->dob, newPatient->gender, newPatient->bloodGroup, newPatient->contact,
            newPatient->email, newPatient->address, newPatient->medicalHistory, newPatient->currentSymptoms,
            newPatient->currentMedications, newPatient->doctorAssigned, newPatient->appointmentDate,
            newPatient->emergencyContactName, newPatient->emergencyContactNumber);

        if (fields == 17) {
            newPatient->next = NULL;
            if (head == NULL) head = newPatient;
            else {
                Patient *temp = head;
                while (temp->next) temp = temp->next;
                temp->next = newPatient;
            }
        } else {
            free(newPatient);
        }
    }
    fclose(fp);
}

void adminLogin() {
    char adminPass[20] = "Admin@123"; 
    char inputPass[20];
    int attempts = 3; 

    while (attempts > 0) {
        system("cls");
        printf("=====================================================================\n");
        printf("\t\t\t ADMIN LOGIN\n");
        printf("=====================================================================\n");
        printf("Enter Admin Password: ");
        scanf("%s", inputPass);

        if (strcmp(inputPass, adminPass) == 0) {
            printf("\n\033[32mLogin Successful!\033[0m\n");
            printf("Press Enter to continue...");
            getchar(); getchar(); 
            adminInterface();
            return; 
        } else {
            attempts--;
            printf("\n\033[31mIncorrect Password! Attempts left: %d\033[0m\n", attempts);
            if (attempts > 0) {
                printf("Press Enter to try again...");
                getchar(); getchar();
            } else {
                printf("Returning to main menu...\n");
                Sleep(1500);
            }
        }
    }
}

void adminInterface() {
    int choice;
    system("cls");
    printf("=====================================================================\n");
    printf("\t\t\t ADMIN PORTAL\n");
    printf("=====================================================================\n");
    printf("1. View All Patient Records\n");
    printf("2. Search Patient by ID\n");
    printf("3. Update Patient Record\n");
    printf("4. Delete Patient Record\n");
    // printf("5. View All Doctor Records\n");
    // printf("6. Search Doctor by ID\n");
    // printf("7. Update Doctor Record\n");
    // printf("8. Delete Doctor Record\n");
    // printf("9. View Appointments\n");
    // printf("10. Change Admin Password\n");
    printf("5. Logout\n");
    printf("=====================================================================\n");
    printf("Enter your choice (1-11): ");
    scanf("%d", &choice);
    getchar();
    switch(choice) {
        case 1: viewAllPatients(); break;
        case 2: searchPatientByID(); break;
        case 3: updatePatientRecord(); break;
        case 4: deletePatientRecord(); break;
        case 10: changeAdminPassword(); break;
        case 5: return; 
        default:
            printf("Invalid choice! Please try again.\n");
            adminInterface();
    }
}
void viewAllPatients() {
    FILE *fp = fopen("patients.txt", "r");
    if (fp == NULL) {
        printf("\nNo patient records found.\n");
        return;
    }
    char line[500];
    int count = 0;
    system("cls");
    printf("=====================================================================\n");
    printf("\t\t\t ALL PATIENT RECORDS\n");
    printf("=====================================================================\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        char patientID[20], password[20], fullName[50], dob[15], gender[10], blood[5], contact[15], email[50], address[100];
        char medHistory[100], symptoms[100], medications[100], doctor[50], appointment[15], emergencyName[50], emergencyNumber[15];
        int age;

        int fields = sscanf(line, "%s\t%s\t%[^\t]\t%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]",
            patientID, password, fullName, &age, dob, gender, blood, contact, email, address,
            medHistory, symptoms, medications, doctor, appointment, emergencyName, emergencyNumber);

        if (fields == 17) {
            count++;
            printf("\nPatient #%d\n", count);
            printf("ID: %s | Name: %s | Age: %d | Gender: %s | Blood Group: %s\n", patientID, fullName, age, gender, blood);
            printf("Contact: %s | Email: %s | DOB: %s | Address: %s\n", contact, email, dob, address);
            printf("Medical History: %s | Symptoms: %s | Medications: %s\n", medHistory, symptoms, medications);
            printf("Doctor: %s | Appointment: %s\n", doctor, appointment);
            printf("Emergency Contact: %s (%s)\n", emergencyName, emergencyNumber);
            printf("---------------------------------------------------------------\n");
        }
    }
    fclose(fp);
    if (count == 0) {
        printf("No patient records found.\n");
    } else {
        printf("\nTotal Patients: %d\n", count);
    }
}
void searchPatientByID() {
    char searchID[20];
    int found = 0;
    Patient p;
    FILE *fp = fopen("patients.txt", "r");

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter Patient ID to search: ");
    scanf("%s", searchID);

    while (fscanf(fp,
        "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",
        p.patientID, p.password, p.fullName, &p.age, p.dob, p.gender,
        p.bloodGroup, p.contact, p.email, p.address, p.medicalHistory,
        p.currentSymptoms, p.currentMedications, p.doctorAssigned,
        p.appointmentDate, p.emergencyContactName, p.emergencyContactNumber) == 17)
    {
        if (strcmp(p.patientID, searchID) == 0) {
            found = 1;
            printf("\n===== PATIENT FOUND =====\n");
            printf("Patient ID     : %s\n", p.patientID);
            printf("Full Name      : %s\n", p.fullName);
            printf("Age            : %d\n", p.age);
            printf("DOB            : %s\n", p.dob);
            printf("Gender         : %s\n", p.gender);
            printf("Blood Group    : %s\n", p.bloodGroup);
            printf("Contact        : %s\n", p.contact);
            printf("Email          : %s\n", p.email);
            printf("Address        : %s\n", p.address);
            printf("Medical History: %s\n", p.medicalHistory);
            printf("Symptoms       : %s\n", p.currentSymptoms);
            printf("Medications    : %s\n", p.currentMedications);
            printf("Doctor Assigned: %s\n", p.doctorAssigned);
            printf("Appointment    : %s\n", p.appointmentDate);
            printf("Emergency Name : %s\n", p.emergencyContactName);
            printf("Emergency No.  : %s\n", p.emergencyContactNumber);
            printf("==========================\n");
            break;
        }
    }
    if (!found)
        printf("\nNo patient found with ID: %s\n", searchID);

    fclose(fp);
    printf("\nPress Enter to continue...");
    getchar(); getchar();
}
void deletePatientRecord() {
    char deleteID[20];
    int found = 0;
    Patient p;
    FILE *fp, *temp;

    fp = fopen("patients.txt", "r");
    temp = fopen("temp.txt", "w");

    if (!fp || !temp) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter Patient ID to delete: ");
    scanf("%s", deleteID);

    while (fscanf(fp,
        "%[^\t]\t%[^\t]\t%[^\t]\t%d\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\n]\n",
        p.patientID, p.password, p.fullName, &p.age, p.dob, p.gender,
        p.bloodGroup, p.contact, p.email, p.address, p.medicalHistory,
        p.currentSymptoms, p.currentMedications, p.doctorAssigned,
        p.appointmentDate, p.emergencyContactName, p.emergencyContactNumber) == 17)
    {
        if (strcmp(p.patientID, deleteID) == 0) {
            found = 1;
            printf("\nRecord deleted successfully for Patient ID: %s\n", deleteID);
            continue; 
        }

        fprintf(temp,
            "%s\t%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
            p.patientID, p.password, p.fullName, p.age, p.dob, p.gender,
            p.bloodGroup, p.contact, p.email, p.address, p.medicalHistory,
            p.currentSymptoms, p.currentMedications, p.doctorAssigned,
            p.appointmentDate, p.emergencyContactName, p.emergencyContactNumber);
    }

    fclose(fp);
    fclose(temp);

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (!found)
        printf("\nNo patient found with ID: %s\n", deleteID);

    printf("\nPress Enter to continue...");
    getchar(); getchar();
}
void changeAdminPassword() {
    char oldPass[20], newPass[20], confirmPass[20], savedPass[20];
    FILE *fp = fopen("admin.txt", "r");

    if (!fp) {
        fp = fopen("admin.txt", "w");
        fprintf(fp, "Admin@123");
        fclose(fp);
        strcpy(savedPass, "Admin@123");
    } else {
        fscanf(fp, "%s", savedPass);
        fclose(fp);
    }

    printf("\nEnter Old Admin Password: ");
    scanf("%s", oldPass);

    if (strcmp(oldPass, savedPass) != 0) {
        printf("\nIncorrect old password!\n");
        return;
    }

    printf("Enter New Password: ");
    scanf("%s", newPass);
    printf("Confirm New Password: ");
    scanf("%s", confirmPass);

    if (strcmp(newPass, confirmPass) != 0) {
        printf("\nPasswords do not match!\n");
        return;
    }

    fp = fopen("admin.txt", "w");
    fprintf(fp, "%s", newPass);
    fclose(fp);

    printf("\nAdmin password changed successfully!\n");
    printf("Press Enter to continue...");
    getchar(); getchar();
}           