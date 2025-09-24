# 🌱 ESP32 Greenhouse Automation System

## 📌 Overview
This project automates a small **greenhouse environment** using ESP32.  
It monitors **temperature, humidity, and soil moisture** and allows control of **fan, water pump, and light** via a **local web dashboard**.

---

## 🛠️ Hardware Required
- ESP32 Dev Board  
- DHT22 Temperature & Humidity Sensor  
- Soil Moisture Sensor  
- Fan + Relay/MOSFET  
- Water Pump + Relay/MOSFET  
- LED / Grow Light + Relay/MOSFET  
- Jumper wires, breadboard  

---

## 🔌 Wiring
- DHT22 → GPIO34  
- Soil Sensor → GPIO35  
- Fan → GPIO19 (through relay or MOSFET)  
- Pump → GPIO18  
- Light → GPIO5  

---

## ▶️ Usage
1. Upload the sketch to ESP32.  
2. Connect to Wi-Fi AP `ESP32-AP` (password: `12345678`).  
3. Open browser → go to `192.168.4.1`.  
4. Dashboard updates environmental readings every second.  
5. Use buttons to toggle **fan, pump, and light** manually.

---

## 📂 Repo Structure
