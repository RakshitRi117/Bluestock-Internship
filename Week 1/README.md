# Week 1: Core Data Analytics Foundations

Deliverables for Week 1 of the Bluestock Internship. Across five tasks, a sales dataset is taken through the full analytics workflow: spreadsheet dashboarding, SQL querying, Python analysis, data cleaning with exploratory data analysis (EDA), and a Power BI dashboard.

---

## Tasks at a Glance

| Task | Focus | Tools |
|------|-------|-------|
| [Task1](./Task1) | Sales dashboard in a spreadsheet | Excel |
| [Task2](./Task2) | Querying the sales data | SQL |
| [Task3](./Task3) | Data analysis and charts | Python |
| [Task4](./Task4) | Data cleaning and EDA | Python, Word |
| [Task5](./Task5) | Interactive sales dashboard | Power BI |

---

## Task Details

### Task1: Excel Sales Dashboard
| File | Description |
|------|-------------|
| `Sales_Dashboard.xlsx` | Sales dashboard built in Excel |

### Task2: SQL Analysis
| File | Description |
|------|-------------|
| `Sales_Data.csv` | Sales dataset used for the queries |
| `Task2_SQL_Queries.sql` | SQL queries for analysing the sales data |

### Task3: Python Analysis
| File | Description |
|------|-------------|
| `Sales_Data_Raw.csv` | Raw sales dataset |
| `Task3_Python_Analysis.py` | Python script for analysing the data |
| `Charts.png` | Charts generated from the analysis |

### Task4: Data Cleaning and EDA
| File | Description |
|------|-------------|
| `Sales_Data_Raw.csv` | Raw sales dataset (input) |
| `Cleaned_Sales_Data.csv` | Cleaned dataset (output) |
| `Task4_EDA.py` | Python script for cleaning and exploratory analysis |
| `Task4_EDA_Report.docx` | Report summarising the EDA findings |

### Task5: Power BI Dashboard
| File | Description |
|------|-------------|
| `Sales_Performance_Dashboard.pbix` | Power BI dashboard (open with Power BI Desktop) |
| `Dashboard_Screenshot.png` | Screenshot of the finished dashboard |

---

## How to Run

Run each script from inside its own task folder so it can find its data file.

```bash
cd "Week 1/Task3"
python Task3_Python_Analysis.py

cd "../Task4"
python Task4_EDA.py
```

**Requirements:** Python 3 and the libraries imported at the top of each script.

For the `.pbix` file, open it in **Power BI Desktop**. For the `.sql` file, run it in any SQL client against the loaded sales data.

---

## Workflow

```text
Raw Sales Data -> SQL Queries -> Python Analysis -> Cleaning + EDA -> Dashboards
```

---

## Author

Rakshit Chaudhary
