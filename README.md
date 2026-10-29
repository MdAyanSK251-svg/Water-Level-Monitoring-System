# Water Level Monitoring System

## Project Description
This Arduino-based project monitors the water level using a water level sensor. It displays the water level percentage on a 16x2 I2C LCD and provides an alert when the water level reaches 95% or above.

## Components Required
- Arduino Uno
- Water Level Sensor
- 16x2 I2C LCD
- Green LED
- Red LED
- Buzzer
- Connecting wires

## Pin Connections

| Component | Arduino Pin |
|---|---|
| Water Sensor | A0 |
| Green LED | 5 |
| Red LED | 6 |
| Buzzer | 8 |
| I2C LCD SDA | SDA |
| I2C LCD SCL | SCL |

## Working
1. The sensor measures the water level.
2. Arduino converts the sensor reading into a percentage.
3. The LCD displays the water level.
4. The green LED indicates normal conditions.
5. The red LED and buzzer activate when the water level reaches 95% or above.

## Libraries Required
- Wire.h
- LiquidCrystal_I2C.h

## Applications
- Water tanks
- Water overflow warning systems
- Water storage monitoring

## Author
Ayan Shaikh
