# VayuRakshak 🛡️💨
### An Embedded Gas & Smoke Detection System for Brick Manufacturing Units

**VayuRakshak** (meaning *"Air Protector"*) is an industrial-grade embedded safety system designed to monitor air quality and protect workers in harsh brick manufacturing environments and kilns. Utilizing the **MQ-02 sensor** and modular hardware architecture, the system detects dangerous atmospheric changes caused by heavy fuel combustion and triggers localized multi-sensory alarms.

---

## 🚀 Key Features

* **Targeted Gas Detection:** Utilizes the MQ-02 electrochemical sensor to monitor smoke and combustion gases, with an architecture built to scale for toxic kiln byproducts like Carbon Monoxide (CO) and Sulfur Dioxide (SO₂).
* **Industrial-Grade Alerts:** Deploys an aggressive, high-frequency rapid-pulse audio alarm and high-intensity visual LED indicators designed to cut through loud factory floor machinery and low-visibility dust clouds.
* **Smart Baseline Tuning:** Processes continuous analog signals (0–1023) to precisely calibrate safety threshold levels above the naturally high ambient pollution baseline of a brick kiln floor, preventing false triggers.
* **Harsh-Environment Preparation:** Optimized for deployment within dust-proof (IP65-rated) enclosures with downward-facing sensor mounts to prevent heavy soot accumulation from settling onto the hardware mesh.
* **Firmware Stabilization:** Integrates a built-in boot delay to allow the internal sensor heating elements to stabilize completely, ensuring accurate data tracking from the moment monitoring begins.

---

## 🛠️ Technical Stack & Hardware

* **Microcontroller:** Arduino Architecture (Scalable to ESP32 for IoT/Cloud logging)
* **Sensor Module:** MQ-02 Gas & Smoke Sensor (Expandable to MQ-07 / MQ-136)
* **Firmware Language:** C++ (Arduino IDE)
* **Peripherals:** High-Output Piezoelectric Buzzer, High-Intensity Warning LED

### Block Diagram
# VayuRakshak
