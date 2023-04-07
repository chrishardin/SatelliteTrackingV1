# SatelliteTrackingV1

First attempt at making a satellite tracking program using C++. 
Used the sgp4sdp4 library.

## Goals and ideas:
- Research and gather information about satellite orbits and how they can be calculated. 
  - You can use resources such as NASA's website and satellite-tracking software that already exists as reference.

- Decide on a method for obtaining the data for satellite positions in real-time. 
  - This can be done through APIs provided by organizations such as NASA or by accessing satellite tracking databases.

- Choose a programming language and develop a basic outline of the program. 
  - Start by creating classes or functions to handle satellite data, orbit calculation, and display.

- mplement the functionality to retrieve and update satellite data in real-time.

- Develop the user interface to display the satellite orbits and information. 
  - You can use graphics libraries such as OpenGL or DirectX to display the data in a visually appealing manner.

- Test and debug the software to ensure that it is functioning correctly.

- Improve and refine the software by adding additional features and addressing any issues that arise during testing.



### Database Steps:

- [x] Read the TLE data file: You can use the standard C++ input/output library to read the TLE data file. 
You can loop through the file line by line and extract the relevant information for each satellite.

- [x] Parse the TLE data: You can use string parsing techniques in C++ to extract the relevant information 
from each line of TLE data, such as the satellite name, catalog number, and TLE elements.

- [ ] Store the data in a database: You can use a database management system such as MySQL, SQLite, or PostgreSQL to store the parsed TLE data. 
You can create a table in the database to store the TLE data for each satellite and then use SQL statements to insert the data into the database.

- [ ] Connect to the database from your C++ application: You can use a database access library such as ODBC, MySQL Connector/C++, 
or SQLite C++ to connect to the database from your C++ application. You can then use the database access library to execute SQL 
statements to retrieve the TLE data for a specific satellite as needed.


### Steps:
- [x] Obtain TLE data: You can obtain TLE data from various sources such as NASA's Space Track, Celestrak, and others. 
You can parse this data and store it in your C++ application.

- [x] Calculate Satellite Positions: You can use a satellite orbit prediction library such as SGP4 or 
SDP4 to calculate the position of a satellite in real-time. 
These libraries take TLE data as input and output the satellite's position.

- [ ] Display Satellite Positions: You can use a graphical library such as OpenGL or 
a GUI library such as Qt to display the satellite positions on a map.

- [ ] Update Satellite Positions: You can use a timer or a thread to continuously 
update the satellite positions in real-time.

- [ ] User Interaction: You can add user interaction features such as zooming, 
panning, and selecting satellites.
