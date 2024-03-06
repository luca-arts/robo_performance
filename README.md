# Robot music & performance

## Main Brain

A laptop or an raspberry pi could serve as the central master. 
This "brain" should read out a midi score and via e.g. python or pure data convert this to UDP messages towards the different robots. This way you can also incorporate a delay in each individual midi note transformation in order to synchronize the different datastreams.

## robots

1. Robot arm: Arduino Uno Wifi compatible braccio robot
2. Robot Dog

### Robot arm

#### installation:

1. follow this for getting first script running: [link](https://docs.arduino.cc/tutorials/uno-r4-wifi/r4-wifi-getting-started/)
2. next: [link](https://docs.arduino.cc/retired/getting-started-guides/Braccio/) for installing the Braccio Arduino library
3. Now you can check some example codes via:
    1. Arduino IDE
    2. Files
    3. Examples
    4. Braccio
    5. choose your example
    6. set the correct COM port & board (Arduino UNO R4 WIFI)
    7. Upload script
    8. in the folder "Robots/Braccio" you can find arduino code which also shows how to enable the wifi credentials on the board 
    

#### wifi

For the arduino wifi to have wifi access: 
1. copy the `arduino_secrets_template.h` to `arduino_secrets.h`
2. fill in the correct settings in the **arduino_secrets.h**, NOT IN THE TEMPLATE FILE! (so you're not sharing your precious wifi credentials with the public)

#### programming suggestion

I suggest to make a websocket between the braccio and a laptop/brain computer.

First you experiment with what movements of the braccio produce interesting sounds. These you note down.
Next step is to interprete "movement signals" coming from the laptop into these movements.

### Robot Dog

On the robot dog there's an ESP32 microcontroller and a Raspberry Pi 4B. 