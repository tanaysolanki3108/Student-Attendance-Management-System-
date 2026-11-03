Student Attendance Management System (SAMS)
​A console-based student attendance and records management application written in C. This program allows educators and administrators to manage student records, register subjects, log session-by-session attendance, and generate formatted attendance reports.

​Features

​Student Management:
​Add new student records (Name, Branch, Semester, ID, Mobile Number).
​View all stored student profiles.
​Search for individual students by Student ID.
​Attendance Management:
​Register course subjects (up to 10 subjects).
​Record attendance (P for Present, A for Absent) for enrolled students across specific subjects.
​Reports & Analytics:
​Generate comprehensive student attendance reports.
​Displays subject-wise breakdown (Total sessions, Attended sessions, Percentage).
​Automatically calculates overall attendance percentage.
​Persistent Storage:
​Saves all data to binary files (student.dat, subject.dat, attendance.dat) so records persist between sessions.


​File Structure
├── SAMSF.c            # Main application source code
├── README.md          # Project documentation
├── .gitignore         # Ignores compiled binaries and data files
├── student.dat        # Binary database for student records (generated at runtime)
├── subject.dat        # Binary database for enrolled subjects (generated at runtime)
└── attendance.dat     # Binary database for attendance logs (generated at runtime)
