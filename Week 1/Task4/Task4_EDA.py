import pandas as pd

df = pd.read_csv("Sales_Data_Raw.csv")

# Missing Values & Duplicates


print("Missing Values:")
print(df.isnull().sum())

print("\nDuplicate Records:")
print(df.duplicated().sum())

# Basic Statistics


print("\nSales Amount Statistics:")
print(df["Sales_Amount"].describe().round(2))


# Data Validation


print("\nMinimum Sales Amount:",
      df["Sales_Amount"].min())

print("Minimum Quantity Sold:",
      df["Quantity_Sold"].min())

print("Minimum Discount:",
      df["Discount"].min())

# Outlier Detection (IQR Method)

Q1 = df["Sales_Amount"].quantile(0.25)
Q2 = df["Sales_Amount"].quantile(0.50)
Q3 = df["Sales_Amount"].quantile(0.75)

IQR = Q3 - Q1

LOWER_BOUND = Q1 - (1.5 * IQR)
UPPER_BOUND = Q3 + (1.5 * IQR)

print("\nQuartiles")
print("Q1:", round(Q1, 2))
print("Q2 (Median):", round(Q2, 2))
print("Q3:", round(Q3, 2))

print("\nOutlier Bounds")
print("Lower Bound:", round(LOWER_BOUND, 2))
print("Upper Bound:", round(UPPER_BOUND, 2))

print("\nActual Data Range")
print("Minimum Sale:", df["Sales_Amount"].min())
print("Maximum Sale:", df["Sales_Amount"].max())

# Correlation Analysis

print("\nCorrelation: Quantity Sold vs Sales Amount")
print(df[["Quantity_Sold", "Sales_Amount"]].corr())

print("\nTop Quantity Transactions")
print(df[["Quantity_Sold","Sales_Amount","Unit_Price"]].sort_values("Quantity_Sold",ascending=False).head(10))

print("\nCorrelation: Unit Price vs Sales Amount")
print(df[["Unit_Price",
          "Sales_Amount"]].corr())

# Trend Analysis

print("\nRevenue by Sales Representative")
print(
    df.groupby("Sales_Rep")
      ["Sales_Amount"]
      .sum()
      .sort_values(ascending=False)
)

print("\nRevenue by Product Category")
print(df.groupby("Product_Category")["Sales_Amount"].sum().sort_values(ascending=False))

print("\nRevenue by Sales Channel")
print(df.groupby("Sales_Channel")["Sales_Amount"].sum().sort_values(ascending=False))

print("\nRevenue by Payment Method")
print(df.groupby("Payment_Method")["Sales_Amount"].sum().sort_values(ascending=False))