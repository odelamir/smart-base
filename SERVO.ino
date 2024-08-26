void openDoor() {
  my_servo.write(-90);  // Adjust angle for opening
}

void closeDoor() {
  my_servo.write(90);  // Adjust angle for opening
}
