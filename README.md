# Music Store Management System

## Project Overview
The Music Store Management System is a console-based application developed in C++. It helps manage music albums, artists, customers, and sales. The application uses file handling to store data and load it when the program restarts.

## Features
- Add and display albums
- Search albums by ID
- Add and display artists
- Add and display customers
- Process album sales
- Update album stock after a sale
- Calculate the total sale amount
- Save and load albums, artists, customers, and sales using text files
- Object-oriented design using classes and inheritance

## Technologies Used
- C++
- Standard Template Library (STL)
- File handling
- Visual Studio Code
- GCC / G++

## Project Structure
- `main.cpp` — Main menu and program entry point
- `Record.h`, `Record.cpp` — Abstract base class
- `Album.h`, `Album.cpp` — Album management
- `Artist.h`, `Artist.cpp` — Artist management
- `Customer.h`, `Customer.cpp` — Customer management
- `Sale.h`, `Sale.cpp` — Sales records
- `FileManager.h`, `FileManager.cpp` — Data storage and retrieval
- `MusicStore.h`, `MusicStore.cpp` — Main application logic
- `albums.txt`, `artists.txt`, `customers.txt`, `sales.txt` — Persistent data files

## How to Compile
Open a terminal in the project directory and run:

```bash
g++ main.cpp Record.cpp Album.cpp Artist.cpp Customer.cpp Sale.cpp FileManager.cpp MusicStore.cpp -o main.exe
```

## How to Run

On Windows PowerShell:

```powershell
.\main.exe
```

## Data Persistence
The application saves records to text files and loads them on startup, allowing data to remain available after the program closes.

## Author
Student project submission.
