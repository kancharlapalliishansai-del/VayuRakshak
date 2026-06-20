/**
 * @file VayuRakshakfirmware.ino
 * @brief Industrial Gas & Smoke Monitoring System for Brick Kilns
 * @project VayuRakshak (Air Protector)
 * @license MIT License (2026)
 */

// --- Hardware Pin Definitions ---
const int PIN_MQ2_SMOKE = A0;   // MQ-02 Analog Output (Smoke & Combustible Gases)
const int PIN_MQ7_CO    = A1;   // MQ-07 Analog Output (Carbon Monoxide Add-on)
const int PIN_MQ136_SO2 = A2;   // MQ-136 Analog Output (Sulfur Dioxide Add-on)

const int PIN_ALARM_BUZZER = 8; // High-output Piezoelectric Buzzer
const int PIN_ALERT_LED    = 9; // High-intensity Red Warning LED

// --- Industrial Threshold Configuration (0 - 1023) ---
// Note: Calibrated slightly higher than clean air to account for baseline kiln dust.
const int THRESHOLD_SMOKE = 400; 
const int THRESHOLD_CO    = 300; // Lower threshold due to extreme toxicity of Carbon Monoxide
const int THRESHOLD_SO2   = 350;

// --- Timing Configurations ---
const unsigned long WARM_UP_TIME_MS = 60000; // 1-minute stabilization on boot
unsigned long lastSampleTime = 0;
const int SAMPLE_INTERVAL_MS = 1000;         // Read sensors every 1 second

void setup() {
  // Initialize digital outputs
  pinMode(PIN_ALARM_BUZZER, OUTPUT);
  pinMode(PIN_ALERT_LED, OUTPUT);
  
  // Ensure outputs start in SAFE state
  digitalWrite(PIN_ALERT_LED, LOW);
  noTone(PIN_ALARM_BUZZER);
  
  // Initialize hardware analog inputs
  pinMode(PIN_MQ2_SMOKE, INPUT);
  pinMode(PIN_MQ7_CO, INPUT);
  pinMode(PIN_MQ136_SO2, INPUT);

  // Initialize Serial Telemetry for floor management/debugging
  Serial.begin(9600);
  Serial.println(F("============================================="));
  Serial.println(F("SYSTEM START: VayuRakshak Industrial Monitor"));
  Serial.println(F("============================================="));
  
  // --- Sensor Warm-up Safeguard Period ---
  Serial.print(F("Initializing internal heating elements. Please wait..."));
  
  // Flash LED during initialization to notify workers system is booting
  unsigned long bootStart = millis();
  while (millis() - bootStart < WARM_UP_TIME_MS) {
    digitalWrite(PIN_ALERT_LED, HIGH);
    delay(250);
    digitalWrite(PIN_ALERT_LED, LOW);

