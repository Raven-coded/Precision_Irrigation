# Precision Irrigation

This Project utilizes the **`ESP8266 NODE MCU` microcontroller** and a **`YL-69` Soil Moisture sensor** to detect the current moisture percentage in the soil sample and notify the user on the same.



## Features :

- Displays the current soil moisture level as percentage. 
- Detects the moisture changes in real time.
- Notifies the user every 30 seconds of the current soil moisture level through an *e-mail*.
- Can be placed into an soil sample, as long as there is WIFI connection and power supply to the board.



## Components Used :

1. ESP8266 NODE MCU V3.
2. YL-69 Soil Moisture Sensor.
3. Jumper Cables.
4. Bread Board (optional).



## Libraries Used :

- **`ESP8266WiFi.h`** : This library gives raw access to WIFI functions independent of the protocol you are going to use.
- **`ESP8266HTTPClient.h`** : This library specifically knows how to communicate with a `http` web server and does all the formatting and parsing needed. If you are making http requests like **GET** or **POST** then it is normally best to use the `ESP8266HTTPClient` to keep the application code simpler.
- **`WiFiClient.h`**  : This creates a client that can connect to to a specified internet IP address and port as defined in `client. connect()`.



## Getting Started :

1. Firstly we will have to install the above mentioned libraries. This can be done by installing the esp8266 package in the boards manager.
2. Next create an IFTTT Account on the [site](https://ifttt.com/).
3. Setup the *aplet* to work on *webhooks* and send an email once triggered.
4. Copy the **Event Name** and **API Key** by heading into the documentation section [over here](https://ifttt.com/maker_webhooks).
5. Enter your WIFI details in the **`ssid`** and **`password`** variables and alos edit the url of the **`serverName`** variable.



## Hardware Connections :

| <u>**YL-69 Sensor Pin**</u> | <u>ESP8266 Sensor Pin</u> |
| :-------------------------: | :-----------------------: |
|             VCC             |           3.3V            |
|             A0              |            A0             |
|             GND             |            GND            |



## Working :

Alter the variables and upload the code to the **`ESP8266`**, while also ensuring all the connections are intact. Once the code has been uploaded, stick the *Moisture Sensor* into the soil sample and click the reset button**[`RST`]** on the board. Open the serial monitor by pressing `ctrl+shift+I`. If a proper connection is established, you will now receive a notification to your *e-mail* every 30 seconds. 

