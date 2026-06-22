# Employee Management System

[cite_start]This project is a console-based Employee Information Management System developed using C++[cite: 109]. [cite_start]The system stores employee information using Excel-compatible CSV flat files and allows users to manage records through an interactive command-line interface[cite: 102, 112].

## Features

[cite_start]The application provides a centralized main menu that remains active inside an execution loop until requested to break[cite: 43, 44]. [cite_start]Key features map directly to complete CRUD (Create, Read, Update, Delete) capability[cite: 51]:

* [cite_start]**Add New Employee Records (Create):** Dynamically inserts record fields into memory and appends them to persistent storage[cite: 26, 27]. [cite_start]Tracked fields include Employee ID, Name, Age, Phone Number, Start Working Year, Gender, Title, Department, and Salary[cite: 25].
* [cite_start]**View Employee Information (Read):** Parses rows sequentially and outputs all matching rows into a structured console interface[cite: 29].
* [cite_start]**Search Employee Information (Read):** Solves rapid lookup constraints by scanning the database for a user-inputted ID and printing the isolated entry if conditions match[cite: 36, 38].
* [cite_start]**Update Employee Records (Update):** Prompts the user to define a targeted table index position to replace an old record row with newly submitted data fields[cite: 34, 35].
* [cite_start]**Delete Employee Records (Delete):** Target-wipes an entire employee entry out of active sequences by supplying a specific entry index position[cite: 40, 42].
* [cite_start]**Exit Program:** Terminates the primary console loop and safely exits the software runtime cleanly upon selecting option `6`[cite: 43, 44].

## Tech Stack & Architecture

### Core Tech Stack
* [cite_start]**C++ Language:** Core logic and console runtime execution pipeline[cite: 17].
* [cite_start]**File Handling (`fstream`):** Leverages reading streams (`ifstream`) and appending streams (`ofstream`) to manipulate local flat files[cite: 18, 135].
* [cite_start]**Excel-style Data Storage (`.csv`):** Preserves dynamic memory alterations inside a comma-separated persistent file format (`Info.csv`)[cite: 23].

### Underlying Concepts and Data Structures
* [cite_start]**Double Linked List:** Used as the structural backplane in active memory to allow highly efficient record insertion, node navigation, and dynamic runtime table adjustments[cite: 22].
* [cite_start]**Loops:** Handles repetitive operational steps including system-wide entry iteration, text parsing, and maintaining active main menu states[cite: 20].
* [cite_start]**Functions:** Compartmentalizes individual operations into separate logic blocks to bolster source code maintainability and readability[cite: 21].
* [cite_start]**Enum Formatting:** Integrates custom enums to change command line text colors, upgrading console visualization and readability[cite: 21].
