import numpy as np
import matplotlib.pyplot as plt 
import csv
from datetime import datetime
import os.path

path = './experience/results.csv'
check_file = os.path.isfile(path)

print(check_file)

# Init the date time
now = datetime.now()
timestamp = datetime.timestamp(now)

if not check_file:
    # Write the initial file
    with open('./experience/results.csv', 'w') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Date', 'Nbr billes','Col_1', 'Col_2', 'Col_3', 'Col_4', 'Col_5', 'Col_6', 'Col_7', 'Col_8', 'Col_9', 'Col_10', 'Col_11', 'Col_12',  'To keep'])
# Only append new values
if check_file:
    with open(path, 'a') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow([ timestamp, 'Nbr billes','Col_1', 'Col_2', 'Col_3', 'Col_4', 'Col_5', 'Col_6', 'Col_7', 'Col_8', 'Col_9', 'Col_10', 'Col_11', 'Col_12',  'To keep'])


# # creating the dataset
# data = {'C':20, 'C++':15, 'Java':30, 
#         'Python':35}
# courses = list(data.keys())
# values = list(data.values())
  
# fig = plt.figure(figsize = (10, 5))
 
# # creating the bar plot
# plt.bar(courses, values, color ='maroon', 
#         width = 0.4)
 
# plt.xlabel("Courses offered")
# plt.ylabel("No. of students enrolled")
# plt.title("Students enrolled in different courses")
# plt.show()