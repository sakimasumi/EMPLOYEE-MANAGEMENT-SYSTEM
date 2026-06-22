# Employee Management System

This project is a console-based Employee Information Management System developed using C++. The system stores employee information using Excel-compatible CSV flat files and allows users to manage records through an interactive command-line interface.

## Features

The application provides a centralized main menu that remains active inside an execution loop until requested to break. Key features map directly to complete CRUD (Create, Read, Update, Delete) capability:

* **Add New Employee Records (Create):** Dynamically inserts record fields into memory and appends them to persistent storage. Tracked fields include Employee ID, Name, Age, Phone Number, Start Working Year, Gender, Title, Department, and Salary.
* **View Employee Information (Read):** Parses rows sequentially and outputs all matching rows into a structured console interface.
* **Search Employee Information (Read):** Solves rapid lookup constraints by scanning the database for a user-inputted ID and printing the isolated entry if conditions match.
* **Update Employee Records (Update):** Prompts the user to define a targeted table index position to replace an old record row with newly submitted data fields.
* **Delete Employee Records (Delete):** Target-wipes an entire employee entry out of active sequences by supplying a specific entry index position.
* **Exit Program:** Terminates the primary console loop and safely exits the software runtime cleanly upon selecting option `6`.

## Tech Stack & Architecture

### Core Tech Stack
* **C++ Language:** Core logic and console runtime execution pipeline.
* **File Handling (`fstream`):** Leverages reading streams (`ifstream`) and appending streams (`ofstream`) to manipulate local flat files.
* **Excel-style Data Storage (`.csv`):** Preserves dynamic memory alterations inside a comma-separated persistent file format (`Info.csv`).

### Underlying Concepts and Data Structures
* **Double Linked List:** Used as the structural backplane in active memory to allow highly efficient record insertion, node navigation, and dynamic runtime table adjustments.
* **Loops:** Handles repetitive operational steps including system-wide entry iteration, text parsing, and maintaining active main menu states.
* **Functions:** Compartmentalizes individual operations into separate logic blocks to bolster source code maintainability and readability.
* **Enum Formatting:** Integrates custom enums to change command line text colors, upgrading console visualization and readability.
