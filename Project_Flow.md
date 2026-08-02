Start
  ↓
Initialize System (LCD, Serial, Pins, Valves OFF)
  ↓
Read Turbidity Sensor (A0)
  ↓
Convert & Display Turbidity
  ↓
Read Float Switch 1 (Tank 1 Level)
  ↓
Tank Empty?
  ↓
Yes → Turn ON Solenoid Valve 1
No  → Turn OFF Solenoid Valve 1
  ↓
Read Float Switch 2 (Tank 2 Level)
  ↓
Tank Empty?
  ↓
Yes → Turn ON Solenoid Valve 2
No  → Turn OFF Solenoid Valve 2
  ↓
Read Flow Sensor Pulses (HIGH & LOW)
  ↓
Calculate Time (X + Y)
  ↓
Calculate Frequency
  ↓
Calculate Flow Rate (L/min)
  ↓
Convert to Liters/sec
  ↓
Update Total Water Used
  ↓
Display Flow Rate & Total on LCD
  ↓
Send Data (Turbidity + Total) via Serial (every 10 cycles)
  ↓
Repeat Loop
