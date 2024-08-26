bool ultrasonic(byte trig, byte echo) {
  long duration, distance;
 i++;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration / 58.2;

//   Serial.print("Distance: ");
//   Serial.print(distance);
//  Serial.println(" cm");
 locations[i]=distance;
  if (distance < 30)
    return true;
 return false;
 
}