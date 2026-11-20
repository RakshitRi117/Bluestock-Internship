import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("Sales_Data_Raw.csv")

# checking for null values or duplicate
print(df.isnull().sum())
print(df.duplicated().sum())

# Calculate KPIs
print("Total Sales:", df["Sales_Amount"].sum())
print("Average Sales:", round(df["Sales_Amount"].mean(), 2))
print("Highest Sale:", df["Sales_Amount"].max())
print("Lowest Sale:", df["Sales_Amount"].min())

# Top Sales Rep and Top Category
print("\nTop Sales Rep:")
print(df.groupby("Sales_Rep")["Sales_Amount"].sum().sort_values(ascending=False).head(1))
print("\nTop Category:")
print(df.groupby("Product_Category")["Sales_Amount"].sum().sort_values(ascending=False).head(1))

# Revenue Analysis

revenue_by_Rep = (df.groupby("Sales_Rep")["Sales_Amount"].sum())
revenue_by_Cat = (df.groupby("Product_Category")["Sales_Amount"].sum())
fig, ax = plt.subplots(1, 2, figsize=(14, 6))
ax[0].bar(revenue_by_Rep.index, revenue_by_Rep.values, color="purple")
ax[0].set_title("Revenue by Sales Rep")
ax[0].set_xlabel("Sales Rep")
ax[0].set_ylabel("Revenue Generated")

ax[1].bar(revenue_by_Cat.index, revenue_by_Cat.values, color="red")
ax[1].set_title("Revenue by Category")
ax[1].set_xlabel("Category")
ax[1].set_ylabel("Revenue Generated")

plt.tight_layout()
plt.show()
