# Polar-Cartesian-conversion

Youtube Video:
[Polar-Cartesian Conversion and Computer Graphics](https://www.youtube.com/watch?v=20dDkPfnKhQ)

For the SDL2 Tutorials: https://www.willusher.io/pages/sdl2/
For the SDL2 wiki page: https://wiki.libsdl.org


## How to build?
### Linux

- If you have installed the SDL2 library on your Linux Machine,
- You can build the main.cpp by this command : `g++ main.cpp -L/usr/local/lib -lSDL2`
- Run the created executable by `./a.out`
- You should see the opening window and a rotating line in the circle as follows:
![](https://github.com/ArduinoHocam/Polar-Cartesian-conversion/blob/main/example_SDL2_output.gif)


### Arduino & OLED Screen

- In order to test on the Arduino Nano & 0.96inch OLED Screen, use the following schematic
![](https://github.com/ArduinoHocam/Polar-Cartesian-conversion/blob/main/arduino-oled-display-connections.png)
- OLED output should be as follows:

![](https://github.com/ArduinoHocam/Polar-Cartesian-conversion/blob/main/oled_example_output.gif)
- You can try this project online [wokwi_online_arduino](https://wokwi.com/projects/347021289870852692)
