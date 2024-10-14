import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Step 1: Load the student dataset
df_student = pd.read_csv('student.csv')

# Step 2: Plot the KDE for the 'Age' column
plt.figure(figsize=(8, 6))
sns.kdeplot(df_student['Age'], shade=True, color='blue')
plt.title('KDE Plot of Age Distribution')
plt.xlabel('Age')
plt.ylabel('Density')
plt.show()
