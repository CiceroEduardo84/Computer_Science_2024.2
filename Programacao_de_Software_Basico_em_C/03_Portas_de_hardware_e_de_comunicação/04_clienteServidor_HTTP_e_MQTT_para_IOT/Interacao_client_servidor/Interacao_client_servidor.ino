WiFiServer server(80);

void setup(){
  Serial.begin(115200);
  pinMode(2, OUTPUT); //set the LED pin mode

   delay(10);

   // We start by connecting to a WiFi network

   Serial.println();
   Serial.println();
   Serial.println("Connecting to ");
   Serial.println(ssid);

   WiFi.begin(ssid, password);

   while(WiFi.status() != WL_CONNECTED){
    Delay(1000);
    SErial.println(".");
   }

   Serial.println("");
   Serial.println("WiFi connected.");
   Serial.println("IP address: ");
   Serial.println(WiFi.localIp());

  server.begin();
}

void loop(){
  WifiClient client = server.available(); //listen for incoming clients

  if(client){                         //if you get a client
    Serial.println("New Client.");    // print a message out the serial port
    String currentLine = "";          // make a string to hold incoming data from the client

    while (client.connected()){       // loop while the client's connected
      if(client.available()){         //if there's bytes to read from the client,
        char c = client.read();       //read a byte, then
        Serial.write(c);              //print it out the serial monitor
        if(c == '\n'){                //if the byte is a newline character

          //if the current line is blank, you got two newline character in a row.
          //and a content-type end of the client HTTP request, so send a response:
          if (currentLine.length() == 0){
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            //the content of the HTTP response follows the header:
            //client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            //client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");

            // Exibir a página da Web HTML
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS para estilizar os botões  ON e OFF
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
                        
            // Título da página da Web
            client.println("<body><h1>ESP32 Web Server</h1>");

            client.print("<p><a href=\"/H\"><button class=\"button\">ON</button></a></p>");
            client.print("<p><a href=\"/L\"><button class=\"button button2\">OFF</button></a></p>");

            //The HTTP reponse ends with another blank line:
            client.println();
            //break out of the while loop:
            break;
          } else { // if you git a newline, then clear currentline
            currentline = "";
          }
        } else if (c != '\r'){ //if you got anything else but a carriage return character,
          currentline = ""; // add it to the end of the currentline
        }

        //check to see if the client request was "GET /H" or "GET /L":
        if(currentLine.endsWith("GET /H")){
          digitalWrite(2, HIGH);     //GET /H turns the LED on
        }
         if(currentLine.endsWith("GET /L")){
          digitalWrite(2, LOW);     //GET /L turns the LED off
        }
      }
    }
    //close the connection
    client.stop();
    Serial.println("Client Disconnected.");
  }
}