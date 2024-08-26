void connectToWifi() {

  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void connectToClient() {

  client = server.available();

  if (client) {
    Serial.println("New client connected.");

    // Read the request
    // String request = client.readStringUntil('\r');


    // Send the response
    String my_html;
    /* client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();
*/
    // Send the HTML page with buttons
    // my_html = fill_my_thml();
    // client.println(my_html);

    handleTheRequest();    // Read the request
    sendResponse(client);  // Send the response
                           // Disconnect the client
    delay(10);
    client.stop();
    Serial.println("Client disconnected.");
  }
}