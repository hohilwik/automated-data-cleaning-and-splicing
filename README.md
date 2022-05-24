# About

This is for automation for data cleaning and splicing of data streams coming from a multi-sensor array. I use `init.c` to set up the directory structure, `ls_init.c` to set up `ls.txt` that is used to get information about the files. Then `data_pre_proc.c` goes through all the files placed inside data_raw, cleans it and places it in data_cleaned, then it creates subdirectories inside `data_spliced` for each file in `data_cleaned`, and outputs the spliced data to files named `sensor1.txt`, `sensor2.txt`, etc.


# How to use

- Run startup.sh with "`./start.sh`", this will compile the required files and create their executables
- Run `./init` to initialize the directory structure
- Place your raw data inside `data_raw`
- Run `./ls_init`, this is required for the functions further used and will cause a segmentation fault if not used(because the functions will not know which files to look for)
- Run `./proc` and the data will get cleaned, spliced, and placed in appropriate directories
- Sensor count is automatically detected and taken care of for each file
- Use the MATLAB script `graphing.m` to get graphs of your data, this script will give you file-wise plots, with different subplots for each sensor, and can easily be modified to do other things, as seen in `graphing_conditional.m`
- After processing, place `data_raw`, `data_cleaned`, `data_spliced`, `graphs` and `ls.txt` into some folder of your choice(for eg, `processed_data_01`), and you can process more data by following the previous steps again
- NOTE: the format that this works for is comma-separated data with timestamps at the start, for example
```
2022-05-23 01:38:56.362883,133.0,20.0,77.0,105.0,35.0
2022-05-23 01:38:56.379001,133.0,24.0,77.0,102.0,42.0
2022-05-23 01:38:56.403324,133.0,24.0,77.0,102.0,42.0
2022-05-23 01:38:56.425821,133.0,24.0,77.0,102.0,42.0
2022-05-23 01:38:56.443677,134.0,29.0,77.0,101.0,43.0
2022-05-23 01:38:56.459578,134.0,29.0,77.0,101.0,43.0
2022-05-23 01:38:56.474837,134.0,29.0,77.0,101.0,43.0
2022-05-23 01:38:56.488113,136.0,29.0,77.0,99.0,50.0
```
- To make it work with your data format, have your string format be:
```
<string1><space><string2>,<val>,<val>
```
where string1 and string2 don't contain any spaces, and the values also do not have any spaces between them. Keep in mind that the last value does not have a comma after it, though that can be easily changed if you know C.

# Sample output of processing

```
Processing [baddeadlift2.txt]
Sensor count-> 5
Cleaning Data...
Splicing Data...
Processing [baddeadlift3.txt]
Sensor count-> 5
Cleaning Data...
Splicing Data...
```

