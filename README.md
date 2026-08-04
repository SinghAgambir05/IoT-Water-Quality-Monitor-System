# 💧 IoT-Based Smart Water Quality Monitoring System

A real-time IoT-based water quality monitoring system using an ESP32, TDS sensor, SH1106 OLED display, I2C LCD, Firebase Realtime Database, and a responsive web dashboard.

The system continuously measures the Total Dissolved Solids (TDS) of water, displays the readings locally, uploads the data to Firebase, and visualizes the readings on a live web dashboard.

---

## Features

- Real-time TDS Monitoring
- ESP32 Microcontroller
- SH1106 1.3" OLED Display
- 16x2 I2C LCD Status Display
- Firebase Realtime Database Integration
- Responsive Web Dashboard
- Live Updating TDS Graph
- Water Quality Classification
  - Safe
  - Caution
  - Danger
- Portable Battery Powered Design

---

## Hardware Used

- ESP32 Development Board
- Analog TDS Sensor
- 1.3" SH1106 OLED Display (I2C)
- 16x2 LCD Display (I2C)
- Breadboard
- Jumper Wires
- 4 × 9V Batteries
- Battery Holders

---

## Software Used

- Arduino IDE
- Firebase Realtime Database
- HTML
- CSS
- JavaScript
- Chart.js
- Netlify (Dashboard Hosting)

---

## Project Architecture

```

TDS Sensor
↓

ESP32

↓

OLED Display
↓

LCD Display

↓

Firebase Realtime Database

↓

Web Dashboard

↓

Mobile/Desktop Browser

```

---

## Working Principle

1. The TDS sensor continuously measures the conductivity of water.

2. The ESP32 reads the analog sensor value.

3. The sensor value is converted into TDS (ppm).

4. The OLED displays:
   - Current TDS value
   - Live scrolling graph

5. The LCD displays:
   - SAFE
   - CAUTION
   - DANGER

6. The ESP32 uploads the latest TDS value to Firebase.

7. The dashboard reads the data from Firebase and displays:

   - Live TDS value
   - Water Quality Status
   - Real-time graph
   - Power Consumption

---

## Water Quality Classification

| TDS Value | Status |
|-----------:|--------|
| 0 – 299 ppm | SAFE |
| 300 – 599 ppm | CAUTION |
| 600 ppm and above | DANGER |

---

## Repository Structure

```

IoT-Water-Quality-Monitor/

│

├── ESP32/
│   └── WaterQualityMonitor.ino
│

├── WebDashboard/
│   └── index.html
│

├── Images/
│   ├── Prototype.jpg
│   ├── Dashboard.png
│   └── Circuit.png
│

├── docs/
│   ├── Report.pdf
│   └── Poster.pdf
│

├── README.md
└── LICENSE

```

---

## Installation

### 1. Clone Repository

```bash
git clone https://github.com/YOUR_USERNAME/IoT-Water-Quality-Monitor.git
```

---

### 2. Install Arduino Libraries

Install the following libraries from the Arduino Library Manager.

- WiFi
- HTTPClient
- U8g2
- LiquidCrystal_I2C

---

### 3. Configure WiFi

Inside `WaterQualityMonitor.ino`

Replace

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

with your own credentials.

---

### 4. Configure Firebase

Replace

```cpp
const char* firebaseURL =
"https://YOUR_PROJECT_ID-default-rtdb.asia-southeast1.firebasedatabase.app/tds.json";
```

with your Firebase Realtime Database URL.

---

### 5. Upload Code

Upload the Arduino sketch to the ESP32.

---

### 6. Host Dashboard

Upload the contents of the `WebDashboard` folder to Netlify or any static web hosting service.

---

## Firebase Structure

```

Realtime Database

tds

326

```

---

## Dashboard

The web dashboard displays:

- Live TDS Reading
- Water Quality Status
- Real-Time Graph
- Estimated Power Consumption

The dashboard is fully responsive and works on:

- Windows
- macOS
- Android
- iPhone

---

## Applications

- Drinking Water Monitoring
- Home Water Quality Monitoring
- Educational Projects
- Smart Water Systems
- IoT Research
- Environmental Monitoring

---

## Future Improvements

- pH Sensor Integration
- Turbidity Sensor
- Temperature Sensor
- Dissolved Oxygen Sensor
- Mobile Application
- AI-based Water Quality Prediction
- Push Notifications
- Historical Data Analytics

---

## Screenshots

Add screenshots here.

Example:

```

Images/
├── dashboard.png
├── prototype.jpg
├── oled.jpg
└── mobile-dashboard.png

```

---

## Authors

**Agambir Singh Jammu**

Department of Electronics and Communication Engineering

SRM Institute of Science and Technology

---

## License

This project is licensed under the MIT License.

---

## Acknowledgements

- Espressif Systems
- Firebase
- Arduino
- U8g2 Library
- Chart.js
- SRM Institute of Science and Technology

---

⭐ If you found this project useful, consider giving this repository a star.
