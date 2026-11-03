# Student Attendance Management System (SAMS)

A console-based student attendance and records management application written in C. This program allows educators and administrators to manage student records, register subjects, log session-by-session attendance, and generate formatted attendance reports.

---

## Features

- **Student Management**:
  - Add new student records (Name, Branch, Semester, ID, Mobile Number).
  - View all stored student profiles.
  - Search for individual students by Student ID.
- **Attendance Management**:
  - Register course subjects (up to 10 subjects).
  - Record attendance (`P` for Present, `A` for Absent) for enrolled students across specific subjects.
- **Reports & Analytics**:
  - Generate comprehensive student attendance reports.
  - Displays subject-wise breakdown (Total sessions, Attended sessions, Percentage).
  - Automatically calculates overall attendance percentage.
- **Persistent Storage**:
  - Saves all data to binary files (`student.dat`, `subject.dat`, `attendance.dat`) so records persist between sessions.

---

## File Structure

```text
├── SAMSF.c            # Main application source code
├── README.md          # Project documentation
├── .gitignore         # Ignores compiled binaries and data files
├── student.dat        # Binary database for student records (generated at runtime)
├── subject.dat        # Binary database for enrolled subjects (generated at runtime)
└── attendance.dat     # Binary database for attendance logs (generated at runtime)
```

---

## Getting Started

### Prerequisites

You need a C compiler installed on your system:
- **GCC / MinGW** (Windows, Linux, macOS)
- Alternatively, you can run this in an IDE like **Code::Blocks**, **Dev-C++**, or **VS Code**.

### Compilation & Execution

1. **Clone the repository:**
   ```bash
   git clone https://github.com/<your-username>/<your-repo-name>.git
   cd <your-repo-name>
   ```

2. **Compile the program:**
   Using GCC:
   ```bash
   gcc SAMSF.c -o SAMS
   ```

3. **Run the program:**
   - On Windows:
     ```bash
     SAMS.exe
     ```
   - On Linux/macOS:
     ```bash
     ./SAMS
     ```
   *(Note: The screen clearing command currently uses Windows `cls`. On Unix systems, change `system("cls")` to `system("clear")` if needed).*

---

## How to Use

1. **Add Students**: Select `1. Student Management` $\rightarrow$ `1. Add Student` and fill in the details. Hit Enter on an empty line when finished.
2. **Add Subjects**: Select `2. Attendance Management` $\rightarrow$ `1. Add subjects` to register the courses being taught.
3. **Log Attendance**: Choose `2. Attendance Management` $\rightarrow$ `2. Record attendance`, select the subject, and mark `P` or `A` for each student.
4. **Generate Report**: Navigate to `3. Reports` $\rightarrow$ `1. View Student Attendance Report` and enter the student's ID.

---

## Author

 [tanaysolanki3108](https://github.com/<tanaysolanki3108>)