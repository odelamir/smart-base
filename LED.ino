void openLed() {
  if(flag_led){
if(danger_stole||danger_life){
   for (byte i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, 255, 0, 0);
    pixels.show();
  }
}
else{
  for (byte i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, 200, 200, 200); 
    pixels.show(); 
  }
}

}
}


void closeLed() {
  pixels.clear();
  pixels.show();
}