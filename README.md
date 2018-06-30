# XIOT task
* Write c or arduino function to control one input and output (IO Pins) the input pin is a switch as interrupt once it pressed it should lighting the led connected to output pin, if the switch pressed must send “pressed” to the serial monitor only one time also send the LED states ”ON” or “OFF”.
* Your program can send continuous serial data comes from temperature sensor with 3 second rate at the same time.

# Instructions for setting the app
You can directly use the uploaded proteus project for simulation and the XIOT.elf file as the microcontroller program or design your own simulation project following these instructions:
* Use an ATmega16 microcontroller with 1MHZ frequency.
* Connect PD3 to your switch as we're using external interrupt 1.
* Connect your LED to PA7, if you want to use another port then you should edit it in Interrupt 1 ISR and in main.
* Connect serial monitor receiver to PD1 which is UART transmitter.
* Connect AREF and AVCC pins to 5V power to adjust analog to digital converter reference voltage.
* Connect temperature sensor pin2 to PA0 (ADC0) and pin3 to PA1 (ADC1) or you can use different ADC but give it as a parameter for the ADC_tempAsString function called in main.
* ![alt text](https://preview.ibb.co/mOj27J/Proteus.png)

# Assumptions made
* Using ATmega16 microcontroller.
* Using LM35 temperature sensor.
* Using external interrupt 1.
* Using LED at PA7.

# Issues
* There was some offset in temperature readings caused by the inaccuracy of the sensor.
* The function ADC_readChannel can be used with any sensor, but the ADC_tempAsString depends on the sensor (should be LM35 only) and depends on the way you connect it, should use the connection in datasheet (the way I connected it in proteus project attached).
* If you want to use another external interrupt you should do some minor edits in the code.



