import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv('student.csv')

mean_age = df['Age'].mean()
std_age = df['Age'].std()

df['Z_score'] = (df['Age'] - mean_age) / std_age

outliers = df[(df['Z_score'] > 3) | (df['Z_score'] < -3)]
print("Outliers based on Z-score for Age:")
print(outliers[['Roll number', 'Age', 'Z_score']])

df_no_outliers = df[(df['Z_score'] <= 3) & (df['Z_score'] >= -3)]

age_group_1 = df_no_outliers[df_no_outliers['Age'] <= 18]
age_group_2 = df_no_outliers[(df_no_outliers['Age'] > 18) & (df_no_outliers['Age'] <= 21)]
age_group_3 = df_no_outliers[df_no_outliers['Age'] > 21]

group_counts = [len(age_group_1), len(age_group_2), len(age_group_3)]
labels = ['Age ≤ 18', '18 < Age ≤ 21', 'Age > 21']

plt.figure(figsize=(8, 6))
plt.pie(group_counts, labels=labels, autopct='%1.1f%%', startangle=90, colors=['lightblue', 'lightgreen', 'salmon'])
plt.title('Percentage of Students Enrolled by Age Group')
plt.show()