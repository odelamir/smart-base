bool fire() {
  int sensorValue = digitalRead(firePin);  // קריאת ערך החיישן
  // Serial.print("fire_sensor:");
  // Serial.println(sensorValue);

  if (sensorValue == 1)  // בדיקה אם יש להבהz
    return 1;

  return 0;
}
