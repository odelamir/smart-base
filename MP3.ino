#define NEXT_SONG 0x01    //Play next song
#define VOLUME_UP 0x04    //Increase volume by 1
#define VOLUME_DOWN 0x05  //Decrease volume by 1

byte arrCommandMp3[] = { 0x7E, 0xFF, 0x06, 0x00, 0x00, 0x00, 0x00, 0xEF };

void sendCMPtoMP3(byte commandByte, byte dataHigh, byte dataLow) {
  arrCommandMp3[3] = commandByte;
  arrCommandMp3[5] = dataHigh; // folder
  arrCommandMp3[6] = dataLow;  // song
  Serial2.write(arrCommandMp3, 8);
  
  // הדפסה לפלט הסריאלי לבדיקה

}


void resetMp3() {
  sendCMPtoMP3(0xc, 0, 0);
}

void nextSong() {
  sendCMPtoMP3(NEXT_SONG, 0, 0);
}

void volumeUp() {
  sendCMPtoMP3(VOLUME_UP, 0, 0);
}

void volumeDown() {
  sendCMPtoMP3(VOLUME_DOWN, 0, 0);
}

void playFromFolder(byte numbFolder, byte numbSong) {
  sendCMPtoMP3(0xf, numbFolder, numbSong);
}
