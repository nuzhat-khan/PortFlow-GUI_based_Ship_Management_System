# PortFlow 🚢⚓

A **Port Operations and Shipment Management System** built using **C++, Qt Framework, and SQLite**. PortFlow is a desktop application that simulates the core operations of a modern seaport by providing role-based access for managing shipments, operators, and cargo information.

---

# Overview

PortFlow was developed as an academic project to demonstrate the implementation of **SQLite database operations** through a user-friendly desktop application **Qt**. The system is designed around four different user roles, each responsible for specific port activities.

The application focuses on performing the fundamental database operations:

* Insert
* Update
* Delete
* Search
* Display

using a structured **Qt GUI** connected to an **SQLite database**.

---

# Features

## 👨‍💼 Manager Module

The Manager has administrative control over the system.

* Assign Operator *(Insert)*
* Remove Operator *(Delete)*
* General Report *(Display)*
* Change Manager *(Update)*

---

## 👷 Operator Module

Operators manage shipment handling activities.

* Shipment Loading/Unloading *(Insert)*
* View Shipment Status *(Display)*
* Update Cargo Status *(Update)*
* Review Feedback *(Display)*
---

## 🚢 Shipping Company / Agent Module

Shipping companies interact with shipment records.

* Create Shipment *(Insert)*
* Track Shipment *(Display)*
* Submit Feedback *(Insert)*

---

## 👤 Guest Module

Guests can contribute ideas for improving the software.

* Submit Suggestions *(Insert)*

---

# Database Operations

PortFlow demonstrates all essential SQLite CRUD functionalities.

### ➜ Insert

Used for

* Assigning Operators
* Creating Shipments
* Shipment Loading/Unloading
* Feedback Submission
* Guest Suggestions

---

### ➜ Update

Used for

* Changing Manager Information
* Updating Cargo Status

---

### ➜ Delete

Used for

* Removing Operators

---

### ➜ Display

Used for

* Viewing Shipment Status
* Tracking Shipments
* Viewing General Reports

---

### ➜ Search

Supported while viewing shipment records and tracking shipment information.

---

# General Report

The **General Report** page displays information collected from four database tables.

* Shipment Information
* Cargo Information
* Shipping Company Feedback
* Guest Suggestions

This allows the manager to monitor all important system records from one place.

---

# Technologies Used

* **Programming Language:** C++
* **Framework:** Qt Framework (Qt Widgets)
* **Database:** SQLite
* **IDE:** Qt Creator
* **UI Design:** Figma
* **Database Driver:** Qt SQL Module

---

# Project Structure

```text
# Project Structure

```text
PortFlow/
│
├── PortFlow.pro
│
├── Headers/
│   ├── mainwindow.h
│   ├── manager_info.h
│   ├── operator_info.h
│   ├── shipping_company_info.h
│   └── guest_info.h
│
├── Sources/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── manager_info.cpp
│   ├── operator_info.cpp
│   ├── shipping_company_info.cpp
│   └── guest_info.cpp
│
├── Forms/
│   ├── mainwindow.ui
│   ├── manager_info.ui
│   ├── operator_info.ui
│   ├── shipping_company_info.ui
│   └── guest_info.ui
│
├── Resources/
│   └── Figma_Resources.qrc
│
└── README.md
```
```

---

# User Workflow

```text
Welcome Page
      │
      ▼
Select Role (Combo Box)
      │
      ▼
──────────────────────────
│ Manager               │
│ Operator              │
│ Shipping Company      │
│ Guest                 │
──────────────────────────
      │
      ▼
Role-specific Functions
      │
      ▼
SQLite Database
```

---

# Highlights

* Modern desktop interface built with Qt.
* Role-based navigation using a **Qt ComboBox**.
* SQLite integration for efficient data management.
* Separate modules for Manager, Operator, Shipping Company, and Guest.
* Organized implementation of Insert, Update, Delete, Search, and Display operations.
* Simple, user-friendly interface designed in **Figma**.

---

# Future Improvements

* User authentication and login system.
* Real-time shipment tracking.
* Cargo arrival and departure notifications.
* Export reports to PDF or Excel.
* Barcode/QR code support for shipments.
* Multi-user access with permissions.
* Dashboard with analytics and charts.

---

## Author

# GitHub Repo Links:-
Inteha Chowdhury: https://github.com/intehachowdhury0420 <br>
Naziat Khan: https://github.com/NaziatKhan54 <br>
Nuzhat Khan: https://github.com/nuzhat-khan <br>

---

## Academic Purpose

PortFlow was developed as an academic project to demonstrate the practical implementation of **C++**, **Qt**, and **SQLite** in a desktop application for port operations and shipment management. The project showcases role-based system design and the use of core database operations in a real-world inspired scenario.
