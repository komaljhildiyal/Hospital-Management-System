#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct {
    char patientName[50];
    char doctorName[50];
    char date[20];
    char time[20];
} ap;
typedef struct {
    char doctorName[50];
    char availableDay[20];
    char startTime[10];
    char endTime[10];
} av;
void addava();
void viewava();
void viewap();
void docmenu();
int main() {
    docmenu();
    return 0;
}
void docmenu() {
    int choice;
    do {
        printf("\n....Doctor menu....\n");
        printf("1. Set Availability\n");
        printf("2. View Availability\n");
        printf("3. View Appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: addava(); 
            break;
            case 2: viewava(); 
            break;
            case 3: viewap(); 
            break;
            case 4: printf("Logging out..");
            break;
            default: printf("Invalid choice");
        }
    } while(choice != 4);
}

void addava() {
    av a;
    FILE *fp = fopen("availability.txt", "a");
    if (!fp) {
        printf("Error opening file!");
        return;
    }

    printf("\nEnter Doctor Name: ");
    fgets(a.doctorName, sizeof(a.doctorName), stdin);
    a.doctorName[strcspn(a.doctorName, "\n")] = '\0';

    printf("Enter Available Day: ");
    fgets(a.availableDay, sizeof(a.availableDay), stdin);
    a.availableDay[strcspn(a.availableDay, "\n")] = '\0';

    printf("Enter Start Time (HH:MM): ");
    fgets(a.startTime, sizeof(a.startTime), stdin);
    a.startTime[strcspn(a.startTime, "\n")] = '\0';

    printf("Enter End Time (HH:MM): ");
    fgets(a.endTime, sizeof(a.endTime), stdin);
    a.endTime[strcspn(a.endTime, "\n")] = '\0';

    fprintf(fp, "%s | %s | %s - %s\n", a.doctorName, a.availableDay, a.startTime, a.endTime);
    fclose(fp);

    printf("\nAvailability added successfully!\n");
}

void viewava() {
    FILE *fp = fopen("availability.txt", "r");
    if (!fp) {
        printf("No availability data found.\n");
        return;
    }

    char line[200];
    printf("\n....Doctor Availability....\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

void viewap() {
    FILE *fp = fopen("appointments.txt", "r");
    if (!fp) {
        printf("No appointment data found.\n");
        return;
    }

    char docName[50], line[200];
    printf("\nEnter your Doctor Name to view appointments: ");
    fgets(docName, sizeof(docName), stdin);
    docName[strcspn(docName, "\n")] = '\0';

    int found = 0;
    printf("\n....Appointments for Dr. %s....\n", docName);
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, docName)) {
            printf("%s", line);
            found = 1;
        }
    }

    if (!found)
        printf("No appointments found for Dr. %s\n", docName);

    fclose(fp);
}