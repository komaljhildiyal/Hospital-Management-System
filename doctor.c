#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct Doctor {
    int id;
    char name[50];
    char specialization[50];
    char phone[20];
    char email[50];
    int experience;
    char availableDays[100];
    char timing[50];
    struct Doctor *next;
};

struct Doctor *head = NULL;

void addDoctor() {
    struct Doctor *newDoc = (struct Doctor*)malloc(sizeof(struct Doctor));
    if (newDoc == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter Doctor ID: ");
    scanf("%d", &newDoc->id);
    printf("Enter Name: ");
    scanf("%s", newDoc->name);
    printf("Enter Specialization: ");
    scanf("%s", newDoc->specialization);
    printf("Enter Phone Number: ");
    scanf("%s", newDoc->phone);
    printf("Enter Email ID: ");
    scanf("%s", newDoc->email);
    printf("Enter Years of Experience: ");
    scanf("%d", &newDoc->experience);
    printf("Enter Available Days (e.g. Mon-Fri): ");
    scanf("%s", newDoc->availableDays);
    printf("Enter Visiting Hours (e.g. 10am-2pm): ");
    scanf("%s", newDoc->timing);

    newDoc->next = NULL;

    if (head == NULL)
        head = newDoc;
    else {
        struct Doctor *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newDoc;
    }

    printf("\nDoctor record added successfully.\n");
}

void viewDoctors() {
    struct Doctor *temp = head;
    if (temp == NULL) {
        printf("\nNo doctor records found.\n");
        return;
    }

    printf("\n================ DOCTOR DETAILS ================\n");
    while (temp != NULL) {
        printf("Doctor ID: %d\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("Specialization: %s\n", temp->specialization);
        printf("Phone: %s\n", temp->phone);
        printf("Email: %s\n", temp->email);
        printf("Experience: %d years\n", temp->experience);
        printf("Available Days: %s\n", temp->availableDays);
        printf("Timing: %s\n", temp->timing);
        printf("------------------------------------------------\n");
        temp = temp->next;
    }
}

void updateDoctor() {
    int id, found = 0;
    printf("\nEnter Doctor ID to Update: ");
    scanf("%d", &id);

    struct Doctor *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            found = 1;
            printf("\nExisting Details:\n");
            printf("Name: %s\nSpecialization: %s\nPhone: %s\nEmail: %s\nExperience: %d\n",
                   temp->name, temp->specialization, temp->phone, temp->email, temp->experience);

            printf("\nEnter New Name: ");
            scanf("%s", temp->name);
            printf("Enter New Specialization: ");
            scanf("%s", temp->specialization);
            printf("Enter New Phone: ");
            scanf("%s", temp->phone);
            printf("Enter New Email: ");
            scanf("%s", temp->email);
            printf("Enter New Experience: ");
            scanf("%d", &temp->experience);
            printf("Enter Available Days: ");
            scanf("%s", temp->availableDays);
            printf("Enter New Timing: ");
            scanf("%s", temp->timing);

            printf("\nDoctor details updated successfully.\n");
            break;
        }
        temp = temp->next;
    }

    if (!found)
        printf("\nDoctor ID not found.\n");
}

void deleteDoctor() {
    int id;
    printf("\nEnter Doctor ID to delete: ");
    scanf("%d", &id);

    struct Doctor *temp = head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nDoctor record not found.\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("\nDoctor record deleted successfully.\n");
}

void searchDoctor() {
    int id, found = 0;
    printf("\nEnter Doctor ID to search: ");
    scanf("%d", &id);

    struct Doctor *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            found = 1;
            printf("\nDoctor Found:\n");
            printf("Doctor ID: %d\n", temp->id);
            printf("Name: %s\n", temp->name);
            printf("Specialization: %s\n", temp->specialization);
            printf("Phone: %s\n", temp->phone);
            printf("Email: %s\n", temp->email);
            printf("Experience: %d years\n", temp->experience);
            printf("Available Days: %s\n", temp->availableDays);
            printf("Timing: %s\n", temp->timing);
            break;
        }
        temp = temp->next;
    }

    if (!found)
        printf("\nDoctor ID not found.\n");
}

int totalDoctors() {
    int count = 0;
    struct Doctor *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void saveToFile() {
    FILE *fp = fopen("doctorData.txt", "w");
    if (fp == NULL) {
        printf("Error opening file to save.\n");
        return;
    }
    struct Doctor *temp = head;
    while (temp != NULL) {
        fprintf(fp, "%d %s %s %s %s %d %s %s\n",
                temp->id, temp->name, temp->specialization,
                temp->phone, temp->email, temp->experience,
                temp->availableDays, temp->timing);
        temp = temp->next;
    }

    fclose(fp);
    printf("\nAll records saved to file successfully.\n");
}

void loadFromFile() {
    FILE *fp = fopen("doctorData.txt", "r");
    if (fp == NULL)
        return;

    struct Doctor *newDoc;
    while (1) {
        newDoc = (struct Doctor*)malloc(sizeof(struct Doctor));
        if (fscanf(fp, "%d %s %s %s %s %d %s %s",
                   &newDoc->id, newDoc->name, newDoc->specialization,
                   newDoc->phone, newDoc->email, &newDoc->experience,
                   newDoc->availableDays, newDoc->timing) != 8) {
            free(newDoc);
            break;
        }
        newDoc->next = head;
        head = newDoc;
    }
    fclose(fp);
}

// New function to update weekly timings dynamically
void updateWeeklyTiming() {
    int id, found = 0;
    printf("\nEnter Doctor ID to Update Weekly Timing: ");
    scanf("%d", &id);

    struct Doctor *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            found = 1;
            printf("\nCurrent Availability:\n");
            printf("Available Days: %s\n", temp->availableDays);
            printf("Current Timing: %s\n", temp->timing);

            printf("\nEnter Updated Available Days for this Week (e.g. Tue-Sat): ");
            scanf("%s", temp->availableDays);
            printf("Enter Updated Timings (e.g. 9am-1pm): ");
            scanf("%s", temp->timing);

            printf("\nDoctor weekly timings updated successfully.\n");
            break;
        }
        temp = temp->next;
    }

    if (!found)
        printf("\nDoctor ID not found.\n");
}

void menu() {
    int ch;
    loadFromFile();

    printf("\n==============================================");
    printf("\n          DOCTOR INFORMATION MODULE           ");
    printf("\n      (For Patient Scheduling System)         ");
    printf("\n==============================================");

    do {
        printf("\n\n1. Add Doctor");
        printf("\n2. View All Doctors");
        printf("\n3. Update Doctor Details");
        printf("\n4. Delete Doctor");
        printf("\n5. Search Doctor");
        printf("\n6. Show Total Doctors");
        printf("\n7. Update Weekly Timings");
        printf("\n8. Save & Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: addDoctor(); break;
            case 2: viewDoctors(); break;
            case 3: updateDoctor(); break;
            case 4: deleteDoctor(); break;
            case 5: searchDoctor(); break;
            case 6: printf("\nTotal Doctors Registered: %d\n", totalDoctors()); break;
            case 7: updateWeeklyTiming(); break;
            case 8: saveToFile(); printf("\nExiting Module...\n"); break;
            default: printf("\nInvalid choice. Try again.\n");
        }
    } while (ch != 8);
}