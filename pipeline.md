# Initialization

- run "./ls_init" to generate/refresh ls.txt file with list of files

# Steps for processing

- process each file in ls.txt in a loop
- count number of commas for sensor_count
//find_sensor_count

- for each line, remove everything before first comma, store location
- remove commas, print string from first comma to end, in "data_cleaned"
//data_clean

- use the value of sensor_count
- create array of size N, create directory for file(after removing extension from name)
- open N files from s1 to sN
- read data from file in data_cleaned, and stream data from each sensor into separate file
//data_splicing


- MATLAB script to recursively and automatically go through each folder and create graphs with N sub-graphs
//TODO


# Comments

- once the data processing and graphing is automated, can collect much more data without increasing the time taken to pre-process it, and can spend more time actually analyzing the graphs

- can then compare all the available graphs for each exercise, and find the obvious differences
