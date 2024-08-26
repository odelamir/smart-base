void handleTheRequest() {
    request = client.readStringUntil('\r');
    Serial.println(request);
   if (request.indexOf("/page_home ") != -1) {
     page=2;
    }
   
  else if (request.indexOf("/map") != -1) {
   page=3;
}
  if(request.indexOf("/CAM") != -1){
         client.println("<div class='video'>");
        client.println("<p align=center><img src='http://192.168.43.32:81/stream' style='width: 50px;'></p>");//need espcam ip address
        client.println("</div>");
     }
      if (request.indexOf("/openDoor") != -1) {
        openDoor();
    }
 
     if (request.indexOf("/openLed") != -1) {
      
        openLed();
    }
     if (request.indexOf("/OffBuzzer") != -1) {
        OffBuzzer();
    }
     if (request.indexOf("/closeLed") != -1) {
      flag_led=0;
        closeLed();
    }
     if (request.indexOf("/OnBuzzer") != -1) {
        OnBuzzer();
    }
     if (request.indexOf("/closeDoor") != -1) {
        closeDoor();
    }
     if (request.indexOf("/calling") != -1) {
       if(flag_calling) {
        flag_calling=0;
         playFromFolder(2, 30);
       }
    }

     if(request.indexOf("/OffDanger")!=-1){
      flag_led=1;
      if(Flag){
danger_life=0; 
      Flag=0;
closeDoor();
OffBuzzer();
closeLed();
 }
       if(flag){
           flag=0;
      danger_stole=0;
closeDoor();
OffBuzzer();
closeLed();
   
      }
    
    }
     if(request.indexOf("/OnDanger")!=-1){
     flag_calling=1;
 
      Flag=1;
     
      flag=1;
      

    
    }
     if (request.indexOf("/cam") != -1) {
        client.println("<div class='video'>");
        client.println("<p align=center><img src='http://192.168.0.101:81/stream' style='width: 500px;'></p>");
        client.println("</div>");
    }
}

void sendResponse(WiFiClient client) {
 
 if (page == 1) {
    client.println("<!DOCTYPE html>");
    client.println("<html lang='he'>");
    client.println("<head>");
    client.println("<meta charset='UTF-8'>");
    client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
    client.println("<title>דף התחברות</title>");
    client.println("<style>");
    client.println("body { font-family: sans-serif; margin: 0; padding: 0; background-color: #f4f4f4; display: flex; align-items: center; justify-content: center; height: 100vh; }");
    client.println(".container { background-color: #fff; padding: 30px; border-radius: 10px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); max-width: 400px; width: 100%; }");
    client.println("h1 { text-align: center; margin-bottom: 20px; }");
    client.println(".input-group { margin-bottom: 15px; }");
    client.println("label { display: block; margin-bottom: 5px; }");
    client.println("input[type='text'], input[type='password'] { width: 95%; padding: 10px; border: 1px solid #ccc; border-radius: 5px; }");
    client.println("button[type='submit'] { background-color: #007bff; color: #fff; padding: 10px 20px; border: none; border-radius: 5px; cursor: pointer; width: 100%; margin-top: 10px; }");
    client.println("#write { margin-left: 350px; font-size: large; }");
    client.println(".error-message { color: red; text-align: center; margin-top: 10px; }");
    client.println("</style>");
    client.println("</head>");
    client.println("<body>");
    client.println("<div class='container'>");
    client.println("<h1>התחבר</h1>");
    client.println("<form id='loginForm'>");
    client.println("<div class='input-group'>");
    client.println("<label for='password' id='write'>סיסמה</label>");
    client.println("<input type='password' id='password' name='password' required>");
    client.println("</div>");
    client.println("<button type='submit'>התחבר</button>");
    client.println("</form>");
    client.println("<p class='error-message'></p>");
    client.println("</div>");
    client.println("<script>");
    client.println("const loginForm = document.getElementById('loginForm');");
    client.println("const errorMessageElement = document.querySelector('.error-message');");
    client.println("loginForm.addEventListener('submit', (event) => {");
    client.println("event.preventDefault();");
    client.println("const password = document.getElementById('password').value;");
    client.println("// בדיקה של שם משתמש וסיסמה");
client.println("if (password === 'צהל') {");
client.println("  errorMessageElement.textContent = '';");
client.println("  window.location.href = '/page_home';"); 


    client.println("} else {");
    client.println("// התחברות כושלת");
    client.println("errorMessageElement.textContent = 'שם משתמש או סיסמה שגויים.';");
    client.println("}");
    client.println("});");
    client.println("</script>");
    client.println("</body>");
    client.println("</html>");
}

else if (page == 2) {
       client.println("<!DOCTYPE html>");
    client.println("<html lang='he'>");
    client.println("<head>");
    client.println("<meta charset='UTF-8'>");
    client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
    client.println("<title>שלום המפקד!</title>");
    client.println("<style>");
    client.println(".button-link { display: inline-block; padding: 10px 20px; background-color: #3b674e; color: white; text-decoration: none; border-radius: 5px; border: 2px solid #2a4e37; font-family: Arial, sans-serif; font-size: 16px; text-align: center; }");
    client.println(".button-link:hover { background-color: #4e845e; }");
    client.println(".button-link:active { background-color: #2a4e37; }");
    client.println("body { font-family: Arial, sans-serif; direction: rtl; text-align: center; background-color: #f5f5f5; margin: 0; padding: 0; }");
    client.println(".container { display: inline-block; padding: 40px; background-color: #fff; border: 1px solid #ccc; border-radius: 10px; margin-top: 50px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1); }");
    client.println(".button-group { margin: 20px 0; }");
    client.println(".button-group span { display: block; font-size: 20px; margin-bottom: 10px; }");
    client.println(".button-group button { width: 80px; height: 50px; margin: 0 10px; font-size: 18px; border: 1px solid #ccc; border-radius: 5px; cursor: pointer; }");
    client.println(".map-button { background-color: #ccffcc; padding: 15px 30px; border: none; border-radius: 5px; cursor: pointer; font-size: 18px; margin-top: 20px; }");
    client.println(".status-buttons button { width: 150px; margin: 15px 10px; font-size: 18px; border: 1px solid #ccc; border-radius: 5px; cursor: pointer; padding: 10px; }");
    client.println("</style>");
    client.println("</head>");
    client.println("<body>");
    client.println("<h1>שלום המפקד!</h1>");
    client.println("<div class='button-link' onclick=\"window.location.href = '/map';\">מפת הבסיס</div>");

    client.println("<div class='container'>");
    client.println("<div class='button-group'>");
    client.println("<span>תאורה</span>");
    client.println("<button onclick='toggleLightOff()'>off</button>");
    client.println("<button onclick='toggleLightOn()'>on</button>");
    client.println("</div>");
    client.println("<div class='button-group'>");
    client.println("<span>אזעקה</span>");
    client.println("<button onclick='toggleAlarmOff()'>off</button>");
    client.println("<button onclick='toggleAlarmOn()'>on</button>");
    client.println("</div>");
    client.println("<div class='button-group'>");
    client.println("<span>שער</span>");
    client.println("<button onclick='toggleGateClose()'>close</button>");
    client.println("<button onclick='toggleGateOpen()'>open</button>");
    client.println("</div>");
    client.println("<div class='button-group'>");
    client.println("<span>מצלמה</span>");
    client.println("<button onclick='toggleCameraOpen()'>open</button>");
    client.println("<button onclick='calling()'>הכרזה למסדר</button>");
    client.println("</div>");
    client.println("<div class='button-group'>");
    client.println("<span>התראות</span>");
    client.println("<button onclick='OnDanger()'>החזרת התראות</button>");
    client.println("<button onclick='OffDanger()'>כיבוי התראות</button>");
    client.println("</div>");
    client.println("<div class='button-group'>");
    client.println("<span>סטטוס </span>");
    if(danger_stole){client.println("<button style='background-color: red;'>גניבת ציוד</button>");}

    else{
client.println("<button >גניבת ציוד</button>");
    }
    if(danger_life){
      client.println("<button style='background-color: red;'>מצב סכנה</button>");

    }
    else{
    client.println("<button >מצב סכנה</button>");}
    client.println("</div>");
    client.println("</div>");
    client.println("<script>");
    client.println("function toggleLightOff() {  window.location.href = '/closeLed'}");
     client.println("function toggleLightOn() {  window.location.href = '/openLed'}");
    client.println("function toggleAlarmOff() { window.location.href = '/OffBuzzer'}");
    client.println("function toggleAlarmOn() { window.location.href = '/OnBuzzer'}");
    client.println("function toggleGateOpen() { window.location.href = '/openDoor' }");
    client.println("function toggleGateClose() { window.location.href = '/closeDoor' }");
    client.println("function toggleCameraOpen() { window.location.href = '/cam' }");
     client.println("function calling() { window.location.href = '/calling' }");
    client.println("function OffDanger() { window.location.href = '/OffDanger' }");
     client.println("function OnDanger() { window.location.href = '/OnDanger' }");

  //  http://192.168.43.32
  
    client.println("</script>");
    client.println("</body>");
    client.println("</html>");
    } 
   
 else if (page == 3) {
 
    client.println("<!DOCTYPE html>");
    client.println("<html lang='he'>");
    client.println("<head>");
    client.println("<meta charset='UTF-8'>");
    client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
    client.println("<title>מפת הבסיס</title>");
  
    client.println("<style>");
        client.println(".button-link { display: inline-block; padding: 10px 20px; background-color: #3b674e; color: white; text-decoration: none; border-radius: 5px; border: 2px solid #2a4e37; font-family: Arial, sans-serif; font-size: 16px; text-align: center; }");
    client.println(".button-link:hover { background-color: #4e845e; }");
    client.println(".button-link:active { background-color: #2a4e37; }");
    client.println("body { font-family: Arial, sans-serif; direction: rtl; text-align: center; margin: 0; }");
    client.println(".base-map { position: relative; width: 1200px; height: 600px; border: 2px solid navy; margin: 0 auto; margin-top: 100px; display: grid; grid-template-columns: repeat(21, 1fr); grid-template-rows: repeat(3, 1fr); }");
    client.println(".base-map .grid-item { border: 1px solid #ccc; position: relative; }");
    client.println(".base-map .grid-item .label { position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); font-size: 10px; }");
    client.println(".base-map .sol { border: 1px solid #ccc; position: relative;  }");
    client.println(".base-map .sol .label { position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); font-size: 10px; }");
    client.println(".base-map .tank-area { grid-column: 19 / 22; grid-row: 1 / 4; border-left: 2px solid red; display: flex; align-items: center; justify-content: center; font-size: 16px; color: black; font-size: 30px; }");
    client.println(".facility-side { position: absolute; top: 10px; left: 360px; width: 100px; height: 50px; border: 2px solid black; z-index: 2;  }");
    client.println(".facility-side .label { position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); font-size: 16px; }");
    client.println(".train { position: absolute; top: 360px; left: 530px; width: 740px; height: 395px; border: 2px solid rgb(19, 104, 56); z-index: 2; background-color: rgba(255, 255, 255, 0.5); }");
    client.println(".train .label { position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); font-size: 30px; }");
    client.println("</style>");
    client.println("</head>");
    client.println("<body>");
    client.println("<div class='facility-side'><div class='label'>מסדר מוכן</div></div>");
 
    if ( locations[2]==6&&locations[3]==6) {
      flag_calling=1;
    client.print("<style>.facility-side { background-color: green; }</style>");}
       else {
    client.print("<style>.facility-side { background-color: white; }</style>");
}

    client.println("<h1>מפת הבסיס</h1>");
    client.println("<div class='base-map' id='baseMap'>");


  


    int numRows = 3;
    int numCols = 18;
    
    for (int row = 1; row <= numRows; row++) {
        for (int col = 1; col <= numCols; col++) {
            if (locations[row] == col) {
              if(danger_stole||danger_life){
                client.print("<div class='sol' style='background-color: red;'><div class='label'>");}
                else{client.print("<div class='sol' style='background-color: rgb(26, 143, 20);'><div class='label'>");}

                client.print(row);
                client.print(" , ");
                client.print(col);
                client.print("</div>");
              
                
                client.println("</div>");
                locations[row]++;
            } else {
                client.print("<div class='grid-item'><div class='label'>");
                client.print(row);
                client.print(" , ");
                client.print(col);
                client.println("</div></div>");
            }
        }
    }
client.println("<div class='tank-area'>ציוד</div>");

if ( danger_stole) {
    client.print("<style>.tank-area { background-color: red; }</style>");
    
} else {
    client.print("<style>.tank-area { background-color: white; }</style>");
}

client.println("</div>"); // סגירת ה-tank-area div

    client.println("<div class='highlighted-rectangle' id='movableRectangle'></div>");
    client.println("<div class='train'><div class='label'>מסדר</div></div>");
    client.println("<br><br><br>");
           client.println("<div class='button-link' style='margin-left: 1100px;' onclick=\"window.location.href='/page_home';\">לדף הבית</div>");

    client.println("</body>");

    // קוד JavaScript לרענון אוטומטי של הדף
    client.println("<script>");
    client.println("setInterval(function() {");
    

    client.println("    location.reload();"); // רענון הדף אם ישנה צורך

    client.println("}, 5000);"); // רענון כל 5 שניות (5000 מילישניות)

    client.println("</script>");

    client.println("</html>");
}

   
}



