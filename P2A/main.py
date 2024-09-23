import pandas as pd
import re

def most_populated(df,base):
    return df[['Country', base]].sort_values(by=base, ascending=False).head(3)

def less_populated(df,base):
     return df[['Country', base]].sort_values(by=base, ascending=True).head(3)

def rate_of_population(df,year1,year2):
    column1 = f'{year1} Population'
    column2 = f'{year2} Population'

    if column1 in df.columns and column2 in df.columns:
        df['Growth_Rate'] = ((df[column2] - df[column1]) / df[column1]) * 100
        return df[['Country', 'Growth_Rate']]

def continent_population_2022(df):
    continent_pop = df.groupby('Continent')['2022 Population'].sum().sort_values()
    return continent_pop

def calc_stats(df):
    for column in ['math score', 'reading score', 'writing score']:
        max_value = student_df[column].max()
        student_df[column].fillna(max_value, inplace=True)
    
    mean_std = df[['math score', 'reading score', 'writing score']].agg(['mean', 'std'])
    return mean_std

def create_student_dict(df):
    student_dict = {}
    for i, row in df.iterrows():
        group_letter = row['group'].split()[-1]  # Extract 'B' from 'group B'
        student_id = f"S{i+1}_{group_letter}"
        student_dict[student_id] = [row['math score'], row['reading score'], row['writing score']]
    return student_dict

def extract_codes(file_path):
    with open(file_path, 'r') as f:
        content = f.read()
    codes = re.findall(r'\d+', content)
    return list(map(int,codes))

def words_with_numbers(file_path):
    with open(file_path, 'r') as f:
        content = f.read()
    words = re.findall(r'\b\w+\d\b', content)
    return words


# MAIN
population_df = pd.read_csv('world_population.csv')
student_df = pd.read_csv('Student_marks.csv')

# print(most_populated(df,'2022 Population'))
# print(least_populated(df,'2022 Population'))
# print(rate_of_population(population_df,2000,2022))
# print(continent_population_2022(population_df))


# print(calc_stats(student_df))
#
# student_dict = create_student_dict(student_df)
# student_id = input()
# print(student_dict.get(student_id, "Student ID not found"))


print(extract_codes('doc.txt'))
# print(words_with_numbers('doc.txt'))
