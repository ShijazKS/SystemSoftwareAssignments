import pandas as pd
import matplotlib.pyplot as plt

df=pd.read_csv('student.csv')

student_data = df[df['Roll number']== 'RN_15']

subjects = ['Physics', 'Chemistry', 'Maths', 'English']
total_marks = []

for sub in subjects:
    mid = student_data[f'mid test {sub} marks'].values[0]
    final = student_data[f'Final {sub} marks'].values[0]
    total_marks.append(mid+final)
# print(student_data.head())

plt.figure(figsize=(8,6))
plt.bar(subjects, total_marks, color=['blue','green','red','purple'])
plt.title("Total Marks Secured by Student RN_15")
plt.xlabel("Subjects")
plt.ylabel("Total Marks")
# plt.show()

weights = student_data[['weight_january','weight_april','weight_july','weight_october']].values[0]
time_periods = ['Trimester 1', 'Trimester 2', 'Trimester 3','Trimester 4']

plt.figure(figsize=(8, 6))
plt.plot(time_periods, weights, marker='o', color='orange')
plt.title("Weight Progress of Student RN_15 Over the Year")
plt.xlabel("Time Period")
plt.ylabel("Weight (kg)")
plt.show()