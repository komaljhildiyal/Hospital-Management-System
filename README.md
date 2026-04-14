# Hospital-Management-System
A console-based Hospital Management System written in C, supporting three user roles — Patient, Doctor, and Admin — with persistent file-based storage.

📁 Project Structure
    ├── main.c            # Core entry point — Patient & Admin modules
    ├── doctor.c          # Doctor Information Module (linked list + file I/O)
    ├── docr.c            # Doctor portal — availability & appointment viewing
    ├── hospital.h        # Shared header (reserved for future use)
    ├── patients.txt      # Flat-file patient database (tab-separated)
    ├── admin.txt         # Admin credentials file
    ├── appointments.txt  # Stores Appointment records
    └── doctorData.txt    # Doctor records (auto-generated at runtime)

✨ Features

👤 Patient Module (main.c)
    New Registration — Collects full patient details and auto-generates a unique Patient ID (PATxxxx)
    Patient Login — Authenticate using Patient ID and password
    View Own Record — Patients can view their stored information after login
    Update Record — Edit personal, medical, and contact details
    Change Password — Patients can update their login password

🛠️ Admin Module (main.c)
    Secure Login — Password stored in admin.txt (default: Admin@123)
    View All Patients — Displays all records in a formatted table
    Search by Patient ID — Quickly look up a specific patient
    Update Patient Record — Modify any field for any patient
    Delete Patient Record — Remove a patient entry using temp-file swap

🩺 Doctor Information Module (doctor.c)
    Manages doctor records using a singly linked list
    Add, view, update, delete, and search doctors by ID
    Update weekly availability and visiting hours dynamically
    Save/load records to/from doctorData.txt
    Displays total registered doctor count

📅 Doctor Portal (docr.c)
    Set and store availability (day + time slot) to availability.txt
    View all doctor availability entries
    View appointments filtered by doctor name from appointments.txt
