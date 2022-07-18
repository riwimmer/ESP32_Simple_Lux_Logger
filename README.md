<h2> Simple Lux Logger</h2>

  This project ideas came about when my daughter kept mentioning about her room is so much colder than mine, despite our home is located in the warm California climate. I was experimenting with ESP32 for some time and though why not do a simple datalog project.


<h3> Requirement </h3>

  •	spend as little time as possible to code a Lux meter and log the incoming light on the wall for 24 hours to compare

<h3> BOM  </h3>
  •	used the <a href="https://www.amazon.com/gp/product/B08D5ZD528/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1">ESP-WROOM-32 module</a><br>
  •	used the <a href="https://www.amazon.com/gp/product/B09KGYF83T/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1">HiLetgo VEML7700 module</a><br>
  •	and the <a href="https://www.amazon.com/gp/product/B082KBF7MM/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1">breadboard</a><br>
  
<h3> Design Hardware </h3>
  •	as the VEML7700 connects via I2C only 4 wires are really needed to hook up the sensor, that’s it. Schematic

<h3> Design Software </h3>
  To simplify the whole design and stick to my quick turn around for data logging solution, I split the design aspect into 3 work flows

  1.	Lux Senor Recording ( 1st program)
    - read the sensor from and I2C line, used the DFRobot_VEML7700 library
    - write or append the value to a file on the SPIFFS memory
    - wait 30 sec (do nothing) and repeat
  One more note I used the ESP32 Data Sketch Upload program within the Arduino IDE to upload the empty sensor.txt file

  2.	Download Sensor Data (2nd program)
    - after the recording reprogram with the FSBrowser example library
    - connect to the ESP32, which is in Access Point and download the file
  
  3.	Analyze Data 
    -overlay the lux readings from the two rooms in an excel

<h3> Result</h3>

<img src="https://github.com/riwimmer/ESP32_Simple_Lux_Logger/blob/master/Screen%20Shot%202022-07-16%20at%208.20.53%20AM.png">
My daughter was right her northeast facing room with similar window size had right at 6:30a a 300lux peak from there it went pretty steady down. On the other side my room facing southwest started at 6:30a slow, but had this fast ramp up of light and higher brightness all the way to the late afternoon. If you wonder about the sudden drops and jumps back up in the afternoon, that was my closing curtain and opening again. 
If I average the incoming light in the two rooms from sunrise to sunset, which is about 158lux vs 122lux not surprising that my room with 29.5% more light feels much warmer. 


<h3> Project Conclusion</h3>

It took me about 10 min to create the Lux Senor Recording code and a minute or so to update the FSBrowser library example, updating my credentials. Really impressive how simple it was to create that lux logger with the ESP32 and how fast I could complete the project. More to come, but I moved on to my next project. 

