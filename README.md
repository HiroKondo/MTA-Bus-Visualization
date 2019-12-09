# Line Visualization
I visualized the movement of the buses running in NYC in the morning on February 12, 2019. 
The bus records are gathered from the MTA website. Each line shows a movement of a bus between one record and another. 
The line color was decided base on the travel distance between the records: red and orange color indicates long-distance travel, and blue means a short distance trip. 
This simple, beautiful visualization gives us a way to understand the pattern of bus trips in NYC.

This project is longlisted for [Information is Beautiful Awards 2019](https://www.informationisbeautifulawards.com/showcase/3872-new-york-bus-trips-on-february-12-2019)

<p align="center">
<img src="https://github.com/HiroKondo/MTA-Bus-Visualization/blob/master/openFrameworks/bin/data/image/Line_Visualization_20190909_Final_revised.png" height="500px">
</p>


## How to use

### Download openFrameworks
Please download the version 0.10.1 of openFrameworks.

### Get the data from the MTA website
I used the data from [MTA website](http://bustime.mta.info/wiki/Developers/Index).
Please get a key from the website and download the XML files of the bus data.

### Data Wrangling
Put all of the XML files in the folder, "python/data/" and then run all of the codes in "the MTA_Bus_Trip_Line_Viz_Preparation.ipynb".

### Copy data to openFrameworks
Put the output csv file to the folder {your oF project-name/bin/data/}. 

### Run the openFrameworks folder.
If you are not familiar with openFrameworks. Please check [openFrameworks website](https://openframeworks.cc).


## License
The source code in this folder is distributed under GPLv3 or later.
