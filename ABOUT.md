# What I wanted to accomplish
I thought about this task as a mini project, XIOT company is in the industry of home automation so I thought about this mini project as a house I'm trying to control. stating on a monitor whether a lamp is on or off, stating if a switch is pressed, reading the temperature of my room whenever I want maybe to turn on air conditioner before getting into my smart home.

# Thinking process
* Switch must be used with external interrupt.
* Serial data communication using UART to contact with serial monitor.
* Must use ADC to convert analog sensor to digital values I can work with.
* Must use a timer with interrupt to count 3 seconds for the ADC readings.

# What I learned in the process
* Using github windows application and md files.
* Combining 4 drivers in one project (external interrupt,ADC,timer,UART).
* LM35 sensor had different connections, I had an issue in reading -ve temperature until I used LM35 datasheet and found out there's a different connection using diodes to get the -ve readings.

# Experience
* Very good with C language.
* intermediate with Eclipse IDE.
* Good with proteus.
