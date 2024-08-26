bool temperture() {
  float valtemp;
  String my_print = "";

  valtemp = readTemp(LM75_addr);

  // my_print = "Temperature: " + String(valtemp);
  // Serial.println(my_print);

  if (valtemp > 50)
    return 1;

  return 0;
}

//======================== "funcTemp" ========================

void configTemp(byte add) {
  Wire.beginTransmission(add);
  Wire.write(0x0);
  Wire.endTransmission();
}

float readTemp(int add) {

  float temp;

  Wire.requestFrom(add, 2);

  if (Wire.available()) {
    temp = ((Wire.read() << 8 | Wire.read()) >> 5) * 0.125;
    return temp;
  }
}